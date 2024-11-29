#include "malloc.h"

void* malloc(size_t size) {
    (void)size;
    ft_printf("%s[malloc] size: %u%s\n", GREEN, size, RESET);
    return NULL;
}

void free(void* ptr) {
    (void)ptr;
    ft_printf("%s[free] ptr: %p%s\n", RED, ptr, RESET);
}
