/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlomic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:27:42 by jlomic            #+#    #+#             */
/*   Updated: 2023/07/12 11:56:45 by jlomic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	alphanum_to_lower(char *str, int i)
{
	if (str[i - 1] >= 48 && str[i - 1] <= 57)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
	}
	if (str[i - 1] >= 65 && str[i - 1] <= 90)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
	}
	if (str[i - 1] >= 97 && str[i - 1] <= 122)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
	}
}

void	first_letter(char *str, int i)
{
	if (str[i] < 48 || (str[i] > 57 && str[i] < 65))
	{
		if (str[i + 1] >= 97 && str[i + 1] <= 122)
		{
			str[i + 1] -= 32;
		}
	}
	if ((str[i] > 90 && str[i] < 97) || str[i] > 122)
	{
		if (str[i + 1] >= 97 && str[i + 1] <= 122)
		{
			str[i + 1] -= 32;
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[0] >= 97 && str[0] <= 122)
		{
			str[0] -= 32;
		}
		first_letter(str, i);
		alphanum_to_lower(str, i);
		i++;
	}
	return (str);
}
