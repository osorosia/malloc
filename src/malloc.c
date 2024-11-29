#include <unistd.h>

void* malloc(size_t size) {
    (void)size;
    write(1, "malloc\n", 7);
    return NULL;
}

void free(void* ptr) {
    (void)ptr;
    write(1, "free\n", 5);
}
