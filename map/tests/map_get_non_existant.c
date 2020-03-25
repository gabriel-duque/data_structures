#include <stdlib.h>
#include <string.h>

#include "map.h"

int main(void)
{
    struct map *map = map_init(10);

    map_add(map, "toto", "tata", NULL);
    if (map->size != 1)
        return EXIT_FAILURE;

    if (map->tab[5] == NULL)
        return EXIT_FAILURE;

    if (map->tab[5]->next != NULL)
        return EXIT_FAILURE;

    if (map_get(map, "tata") != NULL)
        return EXIT_FAILURE;

    map_destroy(map, NULL);
    return EXIT_SUCCESS;
}
