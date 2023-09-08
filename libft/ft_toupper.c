/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:06:36 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 10:08:04 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}
/*
#include<stdio.h>
#include<ctype.h>

int main()
{
	int b = 'a';
	printf("Function:%d\nMy function:%d", toupper(b), ft_toupper(b));
}
*/
