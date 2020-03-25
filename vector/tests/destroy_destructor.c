#include <stdlib.h>

#include "vector.h"

static void increment_size_t(void *void_ptr)
{
    size_t *n_ptr = void_ptr;
    (*n_ptr)++;
}

int main(void)
{
    struct vector *vector = vector_new(4);
    if (vector == NULL || vector->size || vector->capacity != 4)
        return EXIT_FAILURE;

    size_t a = 42;
    size_t b = 43;
    size_t c = 44;
    size_t d = 45;

    if (!vector_push_back(vector, &a))
        return EXIT_FAILURE;
    if (!vector_push_back(vector, &b))
        return EXIT_FAILURE;
    if (!vector_push_back(vector, &c))
        return EXIT_FAILURE;
    if (!vector_push_back(vector, &d))
        return EXIT_FAILURE;

    if (vector->size != 4)
        return EXIT_FAILURE;

    vector_destroy(vector, increment_size_t);
    if (a != 43 || b != 44 || c != 45 || d != 46)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
