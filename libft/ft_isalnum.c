/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:59:31 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/09 10:16:22 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
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
