#ifndef _LIB_H_INCLUDED_
#define _LIB_H_INCLUDED_

int putc(unsigned char c);
unsigned char getc(void);
int puts(unsigned char *str);
int gets(unsigned char *buf);
int putxval(unsigned long value, int column);

void* memset(void* buf, int c, long len);
void* memcpy(void* dst, const void* src, long len);
int memcmp(const void* buf1, const void* buf2, long len);

int strlen(const char* str);
char* strcpy(char* dst, const char* src);
int strcmp(const char* str1, const char* str2);
int strncmp(const char* str1, const char* str2, int len);

#endif
