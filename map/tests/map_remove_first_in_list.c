#include <stdlib.h>

#include "map.h"

static void increment(void *ptr)
{
    size_t *tmp = ptr;
    (*tmp)++;
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

    map_destroy(map, NULL);
    return EXIT_SUCCESS;
}
