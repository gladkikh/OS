#ifndef __MULTIBOOT_H__
#define __MULTIBOOT_H__

#ifdef IN_ASM

#define MB_HEADER_MAGIC			0x1badb002

#define MB_HDRFLG_ALIGN_MODULES	0x00000001
#define MB_HDRFLG_MEMORY_INFO	0x00000002
#define MB_HDRFLG_VIDEO_MODE	0x00000004
#define MB_HDRFLG_LOAD_ADDRESS	0x00010000

#else

#include "types.h"

#define MB_LOADER_MAGIC			0x2BADB002

#define MB_INFO_MEMORY			0x00000001
#define MB_INFO_BOOTDEV			0x00000002
#define MB_INFO_CMDLINE			0x00000004
#define MB_INFO_MODULES			0x00000008
#define MB_INFO_AOUT_SYMBOLS	0x00000010
#define MB_INFO_ELF_SHDR		0x00000020
#define MB_INFO_MEMORY_MAP		0x00000040
#define MB_INFO_DRIVES			0x00000080
#define MB_INFO_CONFIG_TABLE	0x00000100
#define MB_INFO_LOADER_NAME		0x00000200
#define MB_INFO_APM_TABLE		0x00000400
#define MB_INFO_VBE_TABLE		0x00000800
#define MB_INFO_FRAMEBUFFER		0x00001000

typedef struct multiboot_info {
	uint32_t flags;
	uint32_t mem_lower;
	uint32_t mem_upper;
	uint32_t bootdev;
	uint32_t cmdline_ptr;
	uint32_t modules_count;
	uint32_t modules_ptr;
	uint32_t kernel_tbl[4];
	uint32_t mmap_length;
	uint32_t mmap_ptr;
	uint32_t drives_length;
	uint32_t drives_ptr;
	uint32_t config_tbl_ptr;
	uint32_t loader_name_ptr;
	uint32_t apm_tbl_ptr;
	uint8_t vbe_data[16];
	uint8_t framebuffer_data[28];
} multiboot_info_t;

#define MB_MMAP_AVAILABLE		1
#define MB_MMAP_RESERVED		2
#define MB_MMAP_ACPI_RECLAIM	3
#define MB_MMAP_NVS				4
#define MB_MMAP_BAD_RAM			5

typedef struct multiboot_mmap {
	uint32_t entry_size;
	uint64_t addr;
	uint64_t len;
	uint32_t type;
} __attribute__((packed)) multiboot_mmap_t;

typedef struct multiboot_module {
	uint32_t start;
	uint32_t end;
	uint32_t cmdline_ptr;
	uint32_t reserved;
} multiboot_module_t;

#endif  /* IN_ASM */

#endif  /* __MULTIBOOT_H__ */
