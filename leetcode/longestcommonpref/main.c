#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	looping(char **strs, int ch, int size)
{
	int	i = 0;
	int	count = 0;
	int	smth = 1;

	while (count < size - 1)
	{
		if (strs[i][ch] != strs[i + 1][ch])
		{
			smth = 0;
			break;
		}
		i++;
		count++;
	}
	return (smth);
}

char* longestCommonPrefix(char** strs, int strsSize)
{
	int	j = 0;
	int	k = 0;
	int	len = 0;
	char *result;

	if (strs[0][0] == '\0')
	{
		result = malloc(sizeof(char));
		result[0] = '\0';
		return result;
	}
	if (strsSize == 1)
	{
		result = malloc((strlen(strs[0]) + 1) * sizeof(char));
		while (strs[0][j] != '\0')
			result[k++] = strs[0][j++];
		result[k] = '\0';
		return (result);
	}
	while (looping(strs, j, strsSize) == 1 && strs[0][j] != '\0')
		len++, j++;
	if (len == 0)
	{
		result = malloc(sizeof(char));
		result[0] = '\0';
	}
	else
	{
		result = malloc((len + 1) * sizeof(char));
		j = 0;
		while (k < len)
			result[k++] = strs[0][j++];
		result[k]  ='\0';
	}
	return (result);
}

int	main(void)
{
	char *strs[] = {"flower","flower","flower","flower"};
	char *result = longestCommonPrefix(strs, 4);
	printf("%s\n", result);
	free(result);
}
