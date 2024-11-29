#include "ft_printf.h"

static int _vprintf(const char* format, va_list args) {
    size_t print_size = 0;

    long i = 0;
    while (format[i]) {
        if (format[i] == '%') {
            i++;
            print_size += print_spec(format[i], args, 1);
        } else {
            ft_putchar_fd(1, format[i]);
            print_size++;
        }
        i++;
    }

    return print_size;
}

int ft_printf(const char* format, ...) {
    va_list args;

    va_start(args, format);
    int ret = _vprintf(format, args);
    va_end(args);

    return ret;
}
