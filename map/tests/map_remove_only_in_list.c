#include <stdlib.h>

#include "map.h"

static void increment(void *ptr)
{
    size_t *n = ptr;
    (*n)++;
}

int main(void)
{
    size_t n1 = 42;

    struct map *map = map_init(10);
    map_add(map, "toto", &n1, NULL);
    map_remove(map, "toto", increment);

    if (n1 != 43)
        return EXIT_FAILURE;

    if (map->size)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
