/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:44:46 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/09 11:17:10 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
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
	ft_memmove(dest + 5, dest, 4);
	printf("Destination: %s", dest);
}
*/
