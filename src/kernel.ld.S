#include "settings.h"

#define LMA(x)	(ADDR(x))

OUTPUT_FORMAT("elf32-i386")
OUTPUT_ARCH(i386)
ENTRY(start)

SECTIONS
{
	. = KERNEL_PHYS_BASE;
	kernel_start = .;

	.text . : AT(LMA(.text))
	{
		*(.mbhdr)
		*(.text*)
	} = 0x90909090

	.rodata . : AT(LMA(.rodata))
	{
		*(.rodata*)
	}

	. = ALIGN(CONSTANT(MAXPAGESIZE));

	.data . : AT(LMA(.data))
	{
		*(.data*)
	}

	.bss . : AT(LMA(.bss))
	{
		*(.bss*)
		*(COMMON)
	}

	kernel_end = .;

	/DISCARD/ :
	{
		*(.comment)
	}
}
