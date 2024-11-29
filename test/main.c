#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    write(1, "============\n", 13);
    void* ptr = malloc(10);
    free(ptr);

    return 0;
}
