#include <stdio.h>
#include <stdlib.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize)
{
	int	j = 0;
	int	i = 0;
    int flag;
	int *result;

	result = (int *)malloc(sizeof(int) * pricesSize);
	*returnSize = pricesSize;
	for (i = 0; i < pricesSize - 1; i++)
	{
		if (prices[i] >= prices[i + 1])
			result[j++] = prices[i] - prices[i + 1];
		else
		{
			flag = 0;
			for (int k = i + 1; k < pricesSize; k++)
			{
				if (prices[i] >= prices[k])
				{
					result[j] = prices[i] - prices[k];
					flag = 1;
					break ;
				}
			}
			if (!flag)
				result[j] = prices[i];
			j++;
		}
	}
	if (i == pricesSize - 1 && prices[i])
		result[j++] = prices[i];
	return (result);
}
