#include "main.h"
/**
 * flip_bits - number of bits you would need to flip
 * to get from one number to another
 * @n: parameter
 * @m: destiny
 * Return: nflips
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int nflips = 0;

	unsigned long int bbb = n ^ m;

	int lep;

	for (lep = 0; lep < (int)(sizeof(unsigned long int) * 8); lep++)
	{
		nflips += (bbb >> lep) & 1;
	}

	return (nflips);
}
