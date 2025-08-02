#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

void* allocate_memory(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void deallocate_memory(void* ptr) {
    free(ptr);
}