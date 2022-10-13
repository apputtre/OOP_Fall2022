#include "my_code.h"

int max_test(int scores[], int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (scores[i] > max)
			max = scores[i];
	}
	return max;
}

int min_test(int scores[], int size)
{
	int min = 100;
	for (int i = 0; i < size; i++)
	{
		if (scores[i] < min)
			min = scores[i];
	}
	return min;
}

float avg_test(int scores[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += scores[i];
	}
	return (float)sum / size;
}