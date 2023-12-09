/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:53:55 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/09 15:16:16 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

void	handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	ch;
	static int				bit = -1;

	(void)context;
	if (bit < 0)
		bit = 7;
	if (signal == SIGUSR1)
		ch = ch | (1 << bit);
	bit--;
	if (ch == '\0' && bit < 0)
		kill(info->si_pid, SIGUSR2);
	if (bit < 0 && ch)
	{
		ft_printf("%c", ch);
		ch = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;
	pid_t				pid;

	sig.sa_sigaction = handler;
	pid = getpid();
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&(sig.sa_mask));
	ft_printf("Server pid is : %d\n", pid);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		sleep(1);
}
