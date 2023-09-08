/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:00:33 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 09:00:38 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	else
		return (0);
}
/*
#include<stdio.h>
#include<ctype.h>

int	main()
{
	printf("Mine: %d\nFucntion: %d", ft_isdigit('5'), isdigit('5'));
}
*/
