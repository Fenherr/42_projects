#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i;
	unsigned char mask;
	char out;

	i = 7;
	mask = 1;

	while (i >= 0)
	{
		out = ((octet >> i) & mask) + '0';
		write(1, &out, 1);
		i--;
	}
}