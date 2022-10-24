#include "swap_arr.h"

void swap_arr(int arr1[], int arr2[], int len_arr1, int len_arr2)
{
	int temp;
	for (int i = 0; i < len_arr1 && i < len_arr2; i++)
	{
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}