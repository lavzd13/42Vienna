#include <stdio.h>

int numberOfEmployeesWhoMetTarget(int* hours, int hoursSize, int target)
{
	int	target_fullfilled = 0;

	for (int i = 0; i < hoursSize; i++)
	{
		if (hours[i] >= target)
			target_fullfilled++;
	}
	return (target_fullfilled);
}
