#ifndef _LIB_TEST_H_INCLUDED_
#define _LIB_TEST_H_INCLUDED_

#undef putc
#define putc putc_Target

#undef puts
#define puts puts_Target

#undef memset
#define memset memset_Target

#undef memcpy
#define memcpy memcpy_Target

#undef memcmp
#define memcmp memcmp_Target

#undef strlen
#define strlen strlen_Target

#undef strcpy
#define strcpy strcpy_Target

#undef strcmp
#define strcmp strcmp_Target

#undef strncmp
#define strncmp strncmp_Target

#endif
