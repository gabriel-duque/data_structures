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
    size_t n2 = 43;
    size_t n3 = 44;
    size_t n4 = 45;

    struct map *map = map_init(10);
    map_add(map, "toto", &n1, NULL);
    map_add(map, "titi", &n2, NULL);
    map_add(map, "tutu", &n3, NULL);
    map_add(map, "tata", &n4, NULL);

    map_remove(map, "tutu", increment);
    if (map->size != 3)
        return EXIT_FAILURE;

    map_remove(map, "titi", increment);
    if (map->size != 2)
        return EXIT_FAILURE;

    map_remove(map, "tata", increment);
    if (map->size != 1)
        return EXIT_FAILURE;

    map_remove(map, "toto", increment);

    if (n1 != 43 || n2 != 44 || n3 != 45 || n4 != 46)
        return EXIT_FAILURE;

    if (map->size)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
