/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:32:11 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/06 15:52:01 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned char		*dst;
	const unsigned char	*source;

	dst = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (n--)
		{
			*dst++ = *source++;
		}
	}
	else if (dest > src)
	{
		dst += n - 1;
		source += n - 1;
		while (n > 0)
		{
			*dst-- = *source--;
			n--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char dest[] = "This is a string";
	ft_memmove(dest + 5, dest, 5);
	printf("Destination: %s", dest);
}
*/
