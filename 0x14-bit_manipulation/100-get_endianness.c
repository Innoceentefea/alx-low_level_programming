#include "main.h"

/**
 * get_endianness - function that checks the endianness
 *
 * Return: 0 if big endian, 1 if little endian
 */

int get_endianness(void)
{
	v_int32_t fff = 0x12345678;
	v_int8_t *ggg = (v_int8_t *)&fff;

	if (*ggg == 0x78)
		return (1);
	else
		return (0);
}
