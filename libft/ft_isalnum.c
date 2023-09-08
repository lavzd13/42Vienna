/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:59:31 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 11:00:18 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (8);
	else
		return (0);
}

/*
#include<stdio.h>
#include<ctype.h>

int	main()
{
	printf("Mine: %d\nFunction: %d", ft_isalnum(' '), isalnum(' '));
}
*/
