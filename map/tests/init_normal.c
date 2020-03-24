#include <stdlib.h>

#include "map.h"

int main(void)
{
    struct map *map;

    if ((map = map_init(42)) == NULL)
        return EXIT_FAILURE;

    map_destroy(map, NULL);

    return EXIT_SUCCESS;
}
