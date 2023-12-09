/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:25:34 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/11 16:37:42 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	sign(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		++i;
	while (n != 0)
	{
		++i;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;

	count = ft_count(n);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		--count;
		str[count] = sign(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
