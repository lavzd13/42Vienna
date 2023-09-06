/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:32:31 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/05 11:00:43 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	int	a;

	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

/*
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
	int b = -150;
	printf("Function:%d\nMy function:%d", toupper(b), ft_toupper(b));
}
*/
