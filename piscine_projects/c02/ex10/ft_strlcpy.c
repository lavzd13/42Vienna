/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:25:24 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/13 10:09:31 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0')
		{
			if (i == size)
			{
				i--;
				break ;
			}
			dest[i] = src[i];
			i++;
		}
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
