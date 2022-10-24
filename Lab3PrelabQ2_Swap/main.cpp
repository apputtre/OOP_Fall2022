#include <iostream>
#include "swap_arr.h"

using std::cout;

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int len_arr1 = 5;
	int arr2[] = { 9, 8, 7 };
	int len_arr2 = 3;

	cout << "Before swap:\n";
	for (int i = 0; i < len_arr1; cout << arr1[i++] << " ") {}
	cout << "\n";
	for (int i = 0; i < len_arr2; cout << arr2[i++] << " ") {}
	cout << "\n\n";

	swap_arr(arr1, arr2, len_arr1, len_arr2);

	cout << "After swap:\n";
	for (int i = 0; i < len_arr1; cout << arr1[i++] << " ") {}
	cout << "\n";
	for (int i = 0; i < len_arr2; cout << arr2[i++] << " ") {}

	return 0;
}