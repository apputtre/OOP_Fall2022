#include "gradeutils.h"

void modify(int arr[], int index, int val)
{
	arr[index] = val;
}

char grade(int arr[], int size)
{
	int sum = sum_arr(arr, size);

	if (sum > 93)
		return 'A';
	if (sum >= 85)
		return 'B';
	if (sum >= 70)
		return 'C';
	if (sum >= 60)
		return 'D';
	return 'F';
}

void show(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

float avg(int arr[], int size)
{
	return (float) sum_arr(arr, size) / size;
}

int sum_arr(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int sum_gteq6(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if(arr[i] >= 6)
			sum += arr[i];
	}
	return sum;
}