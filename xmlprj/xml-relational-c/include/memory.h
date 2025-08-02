#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>

void* allocate_memory(size_t size);
void deallocate_memory(void* ptr);
void* reallocate_memory(void* ptr, size_t new_size);

#endif // MEMORY_H