#include <stdlib.h>

#include "vector.h"

int main(void)
{
    struct vector *vector = vector_new(4);
    if (vector == NULL || vector->size || vector->capacity != 4)
        return EXIT_FAILURE;
    size_t n = 42;
    vector_push_back(vector, &n);

    if (vector_is_empty(vector))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
