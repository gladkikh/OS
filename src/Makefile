TARGET = i586-elf-
AS = $(TARGET)as
CPP = $(TARGET)cpp
CC = $(TARGET)gcc
LD = $(TARGET)ld
CPPFLAGS += -Iinclude

OBJDIR = objs
KERNEL_OBJS = start.o main.o vga.o kernel.o process_manager.o
KERNEL_GEN_OBJS := $(addprefix $(OBJDIR)/,$(KERNEL_OBJS))
KERNEL_HEADERS = include/*.h


.PHONY: kernel clean

kernel: $(OBJDIR)/kernel.elf

clean:
	-rm -r $(OBJDIR)


$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/kernel.elf: $(OBJDIR)/kernel.ld.s $(KERNEL_GEN_OBJS) $(KERNEL_HEADERS)
	$(CC) -o $@ -nostdlib -Wl,-T,$(OBJDIR)/kernel.ld.s $(KERNEL_GEN_OBJS)


$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.s: %.S | $(OBJDIR)
	$(CPP) $(CPPFLAGS) -undef -P -D IN_ASM -o $@ $<
