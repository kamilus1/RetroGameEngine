#include "allocators.h"

ErrorCode stack_allocator_init(StackAllocator * allocator, size_t size) {
    if(allocator == NULL) {
        return ERROR_ARGUMENT_NULL;
    }
    allocator->buffer = (uint8_t *)malloc(size);
    if(allocator->buffer == NULL) {
        return ERROR_OUT_OF_MEMORY;
    }
    allocator->size = size;
    allocator->offset = 0;
    return ERROR_NONE;
}

void * stack_allocator_alloc(StackAllocator * allocator, size_t size) {
    if(allocator == NULL) {
        return NULL;
    }
    void * ptr = allocator->buffer + allocator->offset;
    allocator->offset += size;
    return ptr;
}

void * stack_allocator_get(StackAllocator * allocator, size_t offset) {
    if(allocator == NULL) {
        return NULL;
    }
    if(offset >= allocator->size) {
        return NULL;
    }
    return allocator->buffer + offset;
}

ErrorCode stack_allocator_free_element(StackAllocator * allocator, size_t offset) {
    if(allocator == NULL) {
        return ERROR_ARGUMENT_NULL;
    }
    if(offset >= allocator->size) {
        return ERROR_OFFSET_OUT_OF_BOUNDS;
    }
    // In a stack allocator, we can only free the most recently allocated element.
    if(offset + allocator->offset == allocator->size) {
        allocator->offset = offset;
    }
    allocator->buffer[offset] = NULL;
    return ERROR_NONE;
}

ErrorCode stack_allocator_reset(StackAllocator * allocator) {
    if(allocator == NULL) {
        return ERROR_ARGUMENT_NULL;
    }
    allocator->offset = 0;
    for(size_t i = 0; i < allocator->size; i++) {
        allocator->buffer[i] = NULL;
    }
    return ERROR_NONE;
}

ErrorCode stack_allocator_free(StackAllocator * allocator) {
    if(allocator == NULL) {
        return ERROR_ARGUMENT_NULL;
    }
    free(allocator->buffer);
    allocator->buffer = NULL;
    allocator->size = 0;
    allocator->offset = 0;
    return ERROR_NONE;
}