#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char* format, ...);

///////////////////////////////
// private
///////////////////////////////
// spec
size_t print_spec(char spec, va_list args, int fd);

// utils
size_t ft_strlen(char* str);
void   ft_putchar_fd(int fd, char c);
size_t ft_put_string_fd(int fd, char* str);
size_t ft_put_number_base_fd(int fd, long num, char* base);
size_t ft_put_unsigned_number_base_fd(int fd, size_t num, char* base);

#endif
