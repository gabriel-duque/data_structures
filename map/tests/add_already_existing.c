#include <stdlib.h>

#include "map.h"

int main(void)
{
    struct map *map = map_init(42);

    map_add(map, "toto", "tata", NULL);
    if (map->size != 1)
        return EXIT_FAILURE;

    map_add(map, "toto", "titi", NULL);
    if (map->size != 1)
        return EXIT_FAILURE;

    map_destroy(map, NULL);
    return EXIT_SUCCESS;
}
