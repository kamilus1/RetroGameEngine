#ifndef __ALLOCATORS_H__
#define __ALLOCATORS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "error_codes.h"

typedef struct {
    uint8_t * buffer;
    size_t size;
    size_t offset;
} StackAllocator;

typedef StackAllocator LinearAllocator;



ErrorCode stack_allocator_init(StackAllocator * allocator, size_t size);
void * stack_allocator_alloc(StackAllocator * allocator, size_t size);
ErrorCode stack_allocator_free(StackAllocator * allocator);
void * stack_allocator_get(StackAllocator * allocator,  size_t offset);
ErrorCode stack_allocator_free_element(StackAllocator * allocator, size_t offset);
ErrorCode stack_allocator_reset(StackAllocator * allocator);

ErrorCode linear_allocator_init(LinearAllocator * allocator, size_t size);
void * linear_allocator_alloc(LinearAllocator * allocator, size_t size, size_t element_size);
void linear_allocator_reset(LinearAllocator * allocator);
ErrorCode linear_allocator_free(LinearAllocator * allocator);
void * linear_allocator_get(LinearAllocator * allocator, void * ptr, size_t offset);

#endif // __ALLOCATORS_H__