#include <stdlib.h>

#include "vector.h"

int main(void)
{
    struct vector *vector = vector_new(42);

    if (vector == NULL || vector->size || vector->capacity != 42)
        return EXIT_FAILURE;

    size_t a = 42;
    size_t b = 43;
    size_t c = 44;
    size_t d = 45;

    if (!vector_push_back(vector, &a))
        return EXIT_FAILURE;
    if (vector->size != 1)
        return EXIT_FAILURE;
    if (!vector_push_back(vector, &b))
        return EXIT_FAILURE;
    if (vector->size != 2)
        return EXIT_FAILURE;
    if (!vector_push_back(vector, &c))
        return EXIT_FAILURE;
    if (vector->size != 3)
        return EXIT_FAILURE;
    if (!vector_push_back(vector, &d))
        return EXIT_FAILURE;
    if (vector->size != 4)
        return EXIT_FAILURE;

    vector_destroy(vector, NULL);

    return EXIT_SUCCESS;
}
