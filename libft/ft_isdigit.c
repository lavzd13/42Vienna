/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:44:02 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/04 16:46:10 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int n)
{
	if (n >= 48 && n <= 57)
		return (1);
	else
		return (0);
}
