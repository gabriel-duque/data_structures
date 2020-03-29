#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vector.h"

/* A simple wrapper around malloc */
static inline void *xmalloc(size_t size)
{
    void *ptr;

    if ((ptr = malloc(size)) == NULL)
        perror("vector");

    return ptr;
}

/* A simple wrapper around realloc */
static inline void *xrealloc(void *ptr, size_t size)
{
    void **tmp;

    if ((tmp = realloc(ptr, size)) == NULL)
        perror("vector");

    return tmp;
}

/* Resize our vector up */
static inline bool vector_resize_up(struct vector *vector)
{
    void **tmp;

    if ((tmp = xrealloc(vector->data, 2 * vector->capacity * sizeof(void *)))
         == NULL)
        return false;

    vector->data = tmp;
    vector->capacity *= 2;

    return true;
}

/* Allocate and return a new vector */
__attribute__((visibility("default")))
struct vector *vector_new(size_t capacity)
{
    struct vector *vector;

    if (!capacity)
        capacity = 1;

    if ((vector = xmalloc(sizeof(struct vector))) == NULL)
        return NULL;

    if ((vector->data = xmalloc(capacity * sizeof(void *))) == NULL) {
        free(vector);
        return NULL;
    }

    vector->size = 0;
    vector->capacity = capacity;

    return vector;
}

__attribute__((visibility("default")))
bool vector_is_empty(struct vector *vector)
{
    return !vector->size;
}

__attribute__((visibility("default")))
bool vector_push_back(struct vector *vector, void *value)
{
    if (vector->size == vector->capacity)
        if (!vector_resize_up(vector))
            return false;

    vector->data[vector->size++] = value;

    return true;
}

__attribute__((visibility("default")))
void *vector_pop_back(struct vector *vector)
{
    if (vector->size)
        return vector->data[--vector->size];

    return NULL;
}

__attribute__((visibility("default")))
bool vector_push_front(struct vector *vector, void *value)
{
    if (vector->size == vector->capacity)
        if (!vector_resize_up(vector))
            return false;

    memmove(vector->data + 1, vector->data, vector->size++ * sizeof(void*));
    vector->data[0] = value;

    return true;
}

__attribute__((visibility("default")))
void *vector_pop_front(struct vector *vector)
{
    void *value;

    if (!vector->size)
        return NULL;

    value = vector->data[0];

    memmove(vector->data, vector->data + 1, --vector->size * sizeof(void*));

    return value;
}

__attribute__((visibility("default")))
void *vector_remove_at(struct vector *vector, size_t i)
{
    void *value;

    if (i >= vector->size)
        return NULL;

    value = vector->data[i];

    memmove(vector->data + i, vector->data + i + 1,
            (--vector->size - i) * sizeof(void*));

    return value;
}

__attribute__((visibility("default")))
struct vector *vector_clone(struct vector *vector)
{
    struct vector *clone;

    if ((clone = vector_new(vector->capacity)) == NULL)
        return NULL;

    clone->size = vector->size;
    memcpy(clone->data, vector->data, clone->size * sizeof(void*));

    return clone;
}

__attribute__((visibility("default")))
void vector_destroy(struct vector *vector, void (*destructor) (void*))
{
    if (destructor != NULL)
        for (size_t i = 0; i < vector->size; ++i)
            destructor(vector->data[i]);

    free(vector->data);
    free(vector);
}
