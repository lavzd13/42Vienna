#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *mergeAlternately(char *word1, char *word2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int len;
    char *result;

    len = strlen(word1) + strlen(word2);
    result = (char *)malloc((len + 1) * sizeof(char));
    while (word1[i] != '\0' && word2[j] != '\0')
    {
        result[k++] = word1[i++];
        result[k++] = word2[j++];
    }
    if (word1[i] == '\0' && word2[j] != '\0')
    {
        while (word2[j] != '\0')
            result[k++] = word2[j++];
    }
    else if (word2[j] == '\0' && word1[i] != '\0')
    {
        while (word1[i] != '\0')
            result[k++] = word1[i++];
    }
    result[k] = '\0';
    return(result);
}
