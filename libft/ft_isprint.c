/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:08:14 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/08 09:10:25 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	else
		return (16384);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	printf("Mine: %d\nFucntion: %d", ft_isprint('\v'), isprint('\v'));
}
*/
