int majorityElement(int* nums, int numsSize)
{
	int majority = 0;
	int result = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (majority == 0)
			result = nums[i];
		if (nums[i] == result)
			majority++;
		else
			majority--;
	}
	return (result);
}
