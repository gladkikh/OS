Gladikh_Artem
gladkikh_artem@mail.ru



I didn't implemented OS simulation, because i decided to run OS on real hardware, so
simulation is not needed at all.

Implemented major process-switching algoritms. Process switching procedure is not ready, because
it requires to work with virtual memory, GDT and GDTR. 


To run kernel you need Grub > v1.98 

just type:

insmod elf
insmod multiboot

multiboot */path to kernel.elf file. For example "(hd0,1)/kernel.elf"*/
boot