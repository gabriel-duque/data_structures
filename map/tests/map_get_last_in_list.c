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

    map_add(map, "toto466", "titi", NULL);
    if (map->size != 2)
        return EXIT_FAILURE;

    if (map->tab[5] == NULL)
        return EXIT_FAILURE;

    if (strcmp(map->tab[5]->key, "toto"))
        return EXIT_FAILURE;

    if (strcmp((char*)map->tab[5]->value, "tata"))
        return EXIT_FAILURE;

    if (strcmp(map->tab[5]->next->key, "toto466"))
        return EXIT_FAILURE;

    if (strcmp((char*)map->tab[5]->next->value, "titi"))
        return EXIT_FAILURE;

    if (map->tab[5]->next->next != NULL)
        return EXIT_FAILURE;

    map_add(map, "toto499", "tutu", NULL);
    if (map->size != 3)
        return EXIT_FAILURE;

    if (map->tab[5] == NULL)
        return EXIT_FAILURE;

    if (strcmp(map->tab[5]->key, "toto"))
        return EXIT_FAILURE;

    if (strcmp((char*)map->tab[5]->value, "tata"))
        return EXIT_FAILURE;

    if (strcmp(map->tab[5]->next->key, "toto466"))
        return EXIT_FAILURE;

    if (strcmp((char*)map->tab[5]->next->value, "titi"))
        return EXIT_FAILURE;

    if (strcmp(map->tab[5]->next->next->key, "toto499"))
        return EXIT_FAILURE;

    if (strcmp((char*)map->tab[5]->next->next->value, "tutu"))
        return EXIT_FAILURE;

    if (map->tab[5]->next->next->next != NULL)
        return EXIT_FAILURE;

    struct pair *pair = map_get(map, "toto499");
    if (pair == NULL)
        return EXIT_FAILURE;

    if (strcmp(pair->key, "toto499"))
        return EXIT_FAILURE;

    if (strcmp((char *)pair->value, "tutu"))
        return EXIT_FAILURE;

    if (pair->next != NULL)
        return EXIT_FAILURE;

    map_destroy(map, NULL);
    return EXIT_SUCCESS;
}
