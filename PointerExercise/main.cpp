#include <iostream>

int main()

{

	int num1 = 3;
	int num2 = 4;

	int* num1_ptr = &num1;
	int* num2_ptr = &num2;

	int sum = *num1_ptr + *num2_ptr;

	std::cout << "The sum of " << num1 << " and " << num2 << " is " << sum << ".";

	return 0;
}