/*  Simple OS for AUCA OS course
    Author: Gladkikh Artem
    Email: gladkikh_artem@mail.ru
*/
#ifndef KERNEL_H
#define KERNEL_H




extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
extern int strlen(const char *str);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);

extern void cls();
extern void putch(unsigned char c);
extern void puts(unsigned char *str);

extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();



#endif // KERNEL_H
