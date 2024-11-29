#include "ft_printf.h"

static size_t spec_s(va_list ap, int fd);
static size_t spec_p(va_list ap, int fd);
static size_t spec_u(va_list ap, int fd);

size_t print_spec(char c, va_list ap, int fd) {
    if (c == 's')
        return (spec_s(ap, fd));
    if (c == 'p')
        return (spec_p(ap, fd));
    if (c == 'u')
        return (spec_u(ap, fd));
    return (1);
}

static size_t spec_s(va_list ap, int fd) {
    char* str = va_arg(ap, char*);

    size_t len = ft_put_string_fd(fd, str);
    return len;
}

static size_t spec_u(va_list ap, int fd) {
    size_t num = va_arg(ap, size_t);

    size_t len = ft_put_unsigned_number_base_fd(fd, num, "0123456789");
    return len;
}

static size_t spec_p(va_list ap, int fd) {
    size_t ptr = va_arg(ap, size_t);

    size_t len = 0;
    len += ft_put_string_fd(fd, "0x");
    len += ft_put_unsigned_number_base_fd(fd, ptr, "0123456789abcdef");
    return len;
}
