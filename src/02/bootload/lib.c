#include "defines.h"
#include "serial.h"
#include "lib.h"

int putc(unsigned char c)
{
  if (c == '\n')
    serial_send_byte(SERIAL_DEFAULT_DEVICE, '\r');
  return serial_send_byte(SERIAL_DEFAULT_DEVICE, c);
}

int puts(unsigned char *str)
{
  while (*str)
    putc(*(str++));
  return 0;
}

void* memset(
		void* buf,
		int c,
		long len
		)
{
	return NULL;
}

void* memcpy(
		void* dst,
		const void* src,
		long len
		)
{
	return NULL;
}

int memcmp(
		const void* buf1,
		const void* buf2,
		long len
		)
{
	return 0;
}

int strlen(
		const char* str
		)
{
	return 0;
}

char* strcpy(
		char* dst,
		const char* src
		)
{
	return NULL;
}

int strcmp(
		const char* str1,
		const char* str2
		)
{
	return 0;
}

int strncmp(
		const char* str1,
		const char* str2,
		int len
		)
{
	return 0;
}
