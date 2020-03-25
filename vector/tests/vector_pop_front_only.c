#include <stdlib.h>

#include "vector.h"

int main(void)
{
    struct vector *vector = vector_new(4);
    if (vector == NULL || vector->size || vector->capacity != 4)
        return EXIT_FAILURE;

    size_t n = 42;
    size_t *ptr;

    if (vector->size != 0)
        return EXIT_FAILURE;

    if (!vector_push_front(vector, &n))
        return EXIT_FAILURE;

    if ((ptr = vector_pop_front(vector)) == NULL)
        return EXIT_FAILURE;

    if (*ptr != n)
        return EXIT_FAILURE;

    if (vector->size != 0)
        return EXIT_FAILURE;

    if (vector_pop_front(vector) != NULL)
        return EXIT_FAILURE;

    if (vector->size != 0)
        return EXIT_FAILURE;

    vector_destroy(vector, NULL);
    return EXIT_SUCCESS;
}
