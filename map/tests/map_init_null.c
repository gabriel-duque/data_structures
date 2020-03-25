#include <stdlib.h>

#include "map.h"

int main(void)
{
    if (map_init(0) != NULL)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
