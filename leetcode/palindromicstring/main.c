#include <stdio.h>
#include <string.h>

int	palindromic(char *str)
{
	int	len =strlen(str) - 1;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != str[len--])
			return (0);
	}
	return (1);
}

char* firstPalindrome(char** words, int wordsSize)
{
	for(int i = 0; i < wordsSize; i++)
	{
		if (palindromic(words[i]))
			return (words[i]);
	}
	return ("");
}

int	main(void)
{
	char *words[] = {"abc","car","ada","racecar","cool"};

	char *res = firstPalindrome(words, 5);
	printf("%s\n",res);
	char *str = words[2];
	int	len = strlen(str) - 1;
	for (int j = 0; str[j] != '\0'; j++)
	{
		printf("j: %c len: %c\n", str[j], str[len--]);
	}
}
