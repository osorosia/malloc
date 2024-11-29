#include <stdio.h>
#include <stdlib.h>

int main() {
    void* ptr = malloc(10);
    printf("ptr: %p\n", ptr);
    free(ptr);

    return 0;
}
