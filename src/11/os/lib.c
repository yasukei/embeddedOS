#include "defines.h"
#include "serial.h"
#include "lib.h"

int putc(
		unsigned char c
		)
{
	if (c == '\n')
	{
	  serial_send_byte(SERIAL_DEFAULT_DEVICE, '\r');
	}

	return serial_send_byte(SERIAL_DEFAULT_DEVICE, c);
}

unsigned char getc(
		void
		)
{
	unsigned char c = serial_recv_byte(SERIAL_DEFAULT_DEVICE);
	c = (c == '\r') ? '\n' : c;
	putc(c); /* echo back */

	return c;
}

int puts(
		unsigned char *str
		)
{
	while (*str)
	{
	  putc(*(str++));
	}

	return 0;
}

int gets(
		unsigned char *buf
		)
{
	int i = 0;
	unsigned char c;

	do
	{
		c = getc();
		if(c == '\n')
		{
			c = '\0';
		}
		buf[i++] = c;
	}
	while(c);

	return i - 1;
}

int putxval(
		unsigned long value,
		int column
		)
{
	char buf[9];
	char* p;

	p = buf + sizeof(buf) - 1;
	*(p--) = '\0';

	if(!value && !column)
	{
		column++;
	}

	while(value || column)
	{
		*(p--) = "0123456789abcdef"[value & 0xf];
		value >>= 4;
		if(column)
		{
			column--;
		}
	}

	puts(p + 1);

	return 0;
}

void* memset(
		void* buf,
		int c,
		long len
		)
{
	char* p;

	for(p = buf; len > 0; len--)
	{
		*(p++) = c;
	}
	return buf;
}

void* memcpy(
		void* dst,
		const void* src,
		long len
		)
{
	char* d = dst;
	const char* s = src;

	for(; len> 0; len--)
	{
		*(d++) = *(s++);
	}
	return dst;
}

int memcmp(
		const void* buf1,
		const void* buf2,
		long len
		)
{
	const char* p1 = buf1;
	const char* p2 = buf2;
	
	for(; len > 0; len--)
	{
		if(*p1 != *p2)
		{
			return (*p1 > *p2) ? 1 : -1;
		}
		p1++;
		p2++;
	}

	return 0;
}

int strlen(
		const char* str
		)
{
	int len;

	for(len = 0; *str; str++, len++)
	{
		;
	}

	return len;
}

char* strcpy(
		char* dst,
		const char* src
		)
{
	char* d = dst;
	
	for(;; dst++, src++)
	{
		*dst = *src;
		if(! *src){
			break;
		}
	}

	return d;
}

int strcmp(
		const char* str1,
		const char* str2
		)
{
	while(*str1 || *str2)
	{
		if(*str1 != *str2)
		{
			return (*str1 > *str2) ? 1 : -1;
		}
		str1++;
		str2++;
	}

	return 0;
}

int strncmp(
		const char* str1,
		const char* str2,
		int len
		)
{
	while((*str1 || *str2) && (len > 0))
	{
		if(*str1 != *str2)
		{
			return (*str1 > *str2) ? 1 : -1;
		}
		str1++;
		str2++;
		len--;
	}

	return 0;
}
