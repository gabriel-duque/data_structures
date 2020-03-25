#include <stdlib.h>

#include "map.h"

int main(void)
{
    size_t n1 = 42;
    size_t n2 = 43;

    struct map *map = map_init(10);
    map_add(map, "toto", &n1, NULL);
    map_add(map, "tata", &n2, NULL);
    map_remove(map, "tyty", NULL);

    if (map->size != 2)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
