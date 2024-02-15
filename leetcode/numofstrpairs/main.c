#include <stdio.h>
#include <string.h>

int	compare(char *s1, char *s2)
{
	int res = 0;
	printf("ENter\n");
	if (s1[0] == s2[0])
		res++;
	else if (s1[0] == s2[1])
		res++;
	if (s1[1] == s2[0])
		res++;
	else if (s1[1] == s2[1])
		res++;
	if (res == 2)
		return (printf("RES: %d s1: %s s2: %s\n", res, s1, s2), 1);
	else
		return (0);
}

int	distinctstrings(char **words, int i, int wordsSize, char *str)
{
	while (i < wordsSize )
	{
		if (compare(str, words[i]))
			return(1);
		i++;
	}
	return (0);
}

int maximumNumberOfStringPairs(char ** words, int wordsSize)
{
	int	res =0;

	for(int i = 0; i < wordsSize ; i++)
	{
		if (distinctstrings(words, i + 1, wordsSize, words[i]))
			res++;
	}
	return (res);
}

int	main(void)
{
	char *words[] = {"xi","nw","qp","to","oo","xp","ix","wn","pq"};
	int	res = maximumNumberOfStringPairs(words, 9);
	printf("%d\n", res);
}
