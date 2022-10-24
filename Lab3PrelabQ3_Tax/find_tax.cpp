#include "find_tax.h"

float find_tax(float price, float rate, float quantity)
{
	return (price * quantity) + (price * quantity * rate);
}