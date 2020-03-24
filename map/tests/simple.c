#include <stdlib.h>

#include "map.h"

int main(void)
{
    if (map_add(NULL, NULL, NULL) != 42)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
