/*  Simple OS for AUCA OS course
    Author: Gladkikh Artem
    Email: gladkikh_artem@mail.ru
*/

#include "main.h"
#include "kernel.h"

static const char* itoa(int n)
{
    int radix = 10;
	static const char digits[] = "0123456789ABCDEF";
	static char buf[66];  /* max. 64 digits + sign + terminator */

	if ((radix < 2) && (radix > 16))
		return 0;

	char *ptr = buf + (sizeof(buf) - 2);
	do
	{
		*ptr-- = digits[n % radix];
		n /= radix;
	} while (n > 0);
	if (n < 0)
		*ptr-- = '-';

	return ++ptr;
}

int main()
{
    int i = 0;

    init_video();
    puts ("Hello!!!");

    while(1)
    {

    }
}
