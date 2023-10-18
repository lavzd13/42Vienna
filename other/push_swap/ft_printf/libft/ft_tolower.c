/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:08:49 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 10:09:55 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
/*
#include<stdio.h>
#include<ctype.h>

int main()
{
	int	b = '5';
	printf("Function: %d\nMy function: %d", tolower(b), ft_tolower(b));
}
*/
