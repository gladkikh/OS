#include "settings.h"
#include "multiboot.h"
#include "main.h"

#define MB_HEADER_FLAGS (MB_HDRFLG_ALIGN_MODULES | MB_HDRFLG_MEMORY_INFO)

.section .mbhdr, "a", @note
	.long MB_HEADER_MAGIC
	.long MB_HEADER_FLAGS
	.long -(MB_HEADER_MAGIC + (MB_HEADER_FLAGS))


.text
.code32
.globl start

start:
    call main

.globl cpu_stop
cpu_stop:
	cli
	hlt
	jmp cpu_stop
