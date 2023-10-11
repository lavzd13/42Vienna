/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:05:26 by jlomic            #+#    #+#             */
/*   Updated: 2023/10/09 20:34:42 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniheader.h"

int	g_received = 0;

void	checkg(int i, int **ptr)
{
	while (!g_received)
	{
		sleep(1);
		i++;
		if (i == 30)
		{
			ft_printf("Timeout error, exiting...\n");
			ft_free(ptr);
			exit (EXIT_FAILURE);
		}
	}
}

int	sender(int pid, int **ptr)
{
	int	byte;
	int	bit;
	int	i;

	byte = 0;
	while (ptr[byte])
	{
		bit = 0;
		while (bit <= 7)
		{
			g_received = 0;
			i = 0;
			if (ptr[byte][bit] == 1)
				kill(pid, SIGUSR1);
			else if (ptr[byte][bit] == 0)
				kill(pid, SIGUSR2);
			checkg(i, ptr);
			bit++;
		}
		byte++;
	}
	return (1);
}

int	**chartobin(char *str)
{
	int	byte;
	int	bit;
	int	**ptr;
	int	i;

	byte = ft_strlen(str);
	ptr = ft_calloc(byte + 2, sizeof(int *));
	if (!ptr)
		return (0);
	byte = 0;
	while (str[byte])
	{
		ptr[byte] = ft_calloc(8, sizeof(int));
		if (!(bitcheck(&ptr[byte], ptr)))
			return (0);
		i = 7;
		bit = 0;
		while (i >= 0)
			ptr[byte][bit++] = (str[byte] >> i--) & 1;
		byte++;
	}
	checknull(&ptr[byte], &str[byte]);
	return (ptr);
}

void	handler(int signal, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signal == SIGUSR1)
		g_received = 1;
	else if (signal == SIGUSR2)
		ft_printf("Message received\n");
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sig;
	int					**ptr;

	if (argc != 3)
	{
		ft_printf("Invalid number of arguments.");
		ft_printf("Usage: ./client <pid> <message>\n");
		return (-1);
	}
	sig.sa_sigaction = handler;
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&(sig.sa_mask));
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pid = ft_atoi(argv[1]);
	ptr = chartobin(argv[2]);
	if (!ptr)
	{
		ft_printf("Error encountered while allocating memory, exiting...\n");
		return (-1);
	}
	checker(pid, ptr);
	sender(pid, ptr);
	ft_free(ptr);
}
