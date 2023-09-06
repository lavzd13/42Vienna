/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:47:22 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/05 11:07:58 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	int	a;

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
	int	b = -129;
	printf("Function: %d\nMy function: %d", tolower(b), ft_tolower(b));
}
*/
