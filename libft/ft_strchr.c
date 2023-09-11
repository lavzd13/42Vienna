/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <jlomic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:14:21 by jlomic            #+#    #+#             */
/*   Updated: 2023/09/10 15:35:45 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		++i;
	}
	if (str[i] == c)
		return (str + i);
	return (0);
}

//#include<stdio.h>
//#include<string.h>
//int	main()
//{
//
//	const char str[] = "AAAAAAAAAAAA!IDEMO NIIIIS!";
//	int ch = '!';
//	char *r;
//	char *res;
//
//	r = ft_strchr(str, ch);
//	res = strchr(str, ch);
//
//	printf("Mine: %s\nFunction: %s\n", r, res);
//
//	char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
//	char *d1 = strchr(src, '\0');
//	char *d2 = ft_strchr(src, '\0');
//
//	if (d1 == d2)
//		printf("TEST_SUCCESS\nMine: %s\nFucntion: %s\n", d2, d1);
//	else
//		printf("TEST_FAILED\nMine: %s\nFunction: %s\n", d2, d1);
//
//}
