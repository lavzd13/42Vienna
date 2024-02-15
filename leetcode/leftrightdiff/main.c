#include <stdio.h>
#include <stdlib.h>

int* leftRightDifference(int* nums, int numsSize, int* returnSize)
{
	int	i = 0;
	int	j = 0;
	int	*answer;
	int	leftsum[numsSize];
	int	rightsum[numsSize];
	*returnSize = numsSize;
	answer = (int *)malloc(sizeof(int) * numsSize);
	if (!answer)
		return (NULL);
	while (i < numsSize)
	{
		if (i == 0)
			leftsum[i] = 0;
		else
			leftsum[i] = leftsum[i - 1] + nums[i - 1];
		i++;
	}
	i = 0;
	while (i < numsSize)
	{
		if (i == 0)
			rightsum[i] = 0;
		else
			rightsum[i] = rightsum[i - 1] + nums[numsSize - i];
		i++;
	}
	i -= 1;
	while (j < numsSize)
	{
		answer[j] = abs(leftsum[j] - rightsum[i - j]);
		j++;
	}
	return (answer);
}
