/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:01:55 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 09:02:01 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	else
		return (0);
}
/*
#include<stdio.h>
#include<ctype.h>

int	main()
{
	printf("Mine: %d\nFunction: %d", ft_isalpha('a'), isalpha('a'));
}
*/
