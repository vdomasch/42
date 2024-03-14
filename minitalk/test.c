#include "minitalk.h"

int main(void)
{
	int number;
	int	i;

	number = 0;
	i = 8;
	while (--i >= 0)
	{
		if ('c' >> i & 1)
		{
			number = number << 1;
			number += 1;
		}
		else
		{
			number = number << 1;
		}
		printf("%d\n", i);
	}
	printf("%d\n", number);
	printf("%d\n", 'c');
}
