#include "main.h"

/**
 * print_binary - program prints the binary representation
 * of a number.
 * @n: unsigned long int.
 *
 * Return: no return.
 */

void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int leading_zeros = 1;

	while (mask)
	{
		if (n & mask)
		{
			_putchar('1');
			leading_zeros = 0;
		}
		else if (!leading_zeros)
		{
			_putchar('0');
		}

		mask >>= 1;
	}

	if (leading_zeros)
	{
		_putchar('0')
	}
}

