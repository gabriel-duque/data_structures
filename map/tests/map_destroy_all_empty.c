#include <stdlib.h>

#include "map.h"

int main(void)
{
    struct map *map = map_init(42);
    map_destroy(map, NULL);

    return EXIT_SUCCESS;
}
