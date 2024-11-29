#include "ft_printf.h"

size_t ft_strlen(char* str) {
    if (!str)
        return 0;

    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

void ft_putchar_fd(int fd, char c) {
    write(fd, &c, 1);
}

size_t ft_put_string_fd(int fd, char* str) {
    size_t len = ft_strlen(str);

    write(fd, str, len);
    return len;
}

size_t ft_put_number_base_fd(int fd, long num, char* base) {
    size_t       len      = 0;
    const size_t base_len = ft_strlen(base);

    if (num < 0) {
        ft_putchar_fd(fd, '-');
        num *= -1;
        len++;
    }
    if (num / base_len != 0)
        len += ft_put_number_base_fd(fd, num / base_len, base);
    ft_putchar_fd(fd, base[num % base_len]);

    return len + 1;
}

size_t ft_put_unsigned_number_base_fd(int fd, size_t num, char* base) {
    const size_t base_len = ft_strlen(base);
    size_t       len      = 0;

    if (num / base_len != 0)
        len += ft_put_unsigned_number_base_fd(fd, num / base_len, base);
    ft_putchar_fd(fd, base[num % base_len]);

    return len + 1;
}
