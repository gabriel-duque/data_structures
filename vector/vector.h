#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>

struct vector {
    size_t size;
    size_t capacity;
    void **data;
};

struct vector *vector_new(size_t capacity);

bool vector_is_empty(struct vector *vector);

bool vector_push_back(struct vector *vector, void *value);

void *vector_pop_back(struct vector *vector);

bool vector_push_front(struct vector *vector, void *value);

void *vector_pop_front(struct vector *vector);

void *vector_remove_at(struct vector *vector, size_t i);

struct vector *vector_clone(struct vector *vector);

void vector_destroy(struct vector *vector, void (*destructor) (void*));

#endif /* !VECTOR_H */
