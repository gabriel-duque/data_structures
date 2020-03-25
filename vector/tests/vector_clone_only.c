#include <stdlib.h>

#include "vector.h"

int main(void)
{
    struct vector *vector = vector_new(4);
    if (vector == NULL || vector->size || vector->capacity != 4)
        return EXIT_FAILURE;

    size_t a = 42;

    if (!vector_push_back(vector, &a))
        return EXIT_FAILURE;

    if (vector->size != 1)
        return EXIT_FAILURE;

    struct vector *clone = vector_clone(vector);
    if (clone == NULL || clone->size != 1 || clone->capacity != 4)
        return EXIT_FAILURE;

    if (vector->data[0] != clone->data[0])
        return EXIT_FAILURE;

    vector_destroy(vector, NULL);
    vector_destroy(clone, NULL);
    return EXIT_SUCCESS;
}
