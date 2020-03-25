#include <stdlib.h>

#include "vector.h"

int main(void)
{
    struct vector *vector = vector_new(42);
    if (vector == NULL || vector->size || vector->capacity != 42)
        return EXIT_FAILURE;

    struct vector *clone = vector_clone(vector);
    if (clone == NULL || clone->size || clone->capacity != 42)
        return EXIT_FAILURE;

    vector_destroy(vector, NULL);
    vector_destroy(clone, NULL);
}
