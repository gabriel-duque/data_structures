#include <stddef.h>

/* Returns a new map */
__attribute__((visibility("default")))
struct map *map_init(size_t capacity)
{
    capacity = capacity;
    return NULL;
}

/* Get a entry from the map or NULL if it isn't present */
__attribute__((visibility("default")))
struct entry *map_get(struct map *map, char *key)
{
    (void) map;
    (void) key;
    return NULL;
}

/* Add a new entry into the map */
__attribute__((visibility("default")))
int map_add(struct map *map, char *key, char *value)
{
    (void) map;
    (void) key;
    (void) value;
    return 42;
}

/* Delete an entry from the map */
__attribute__((visibility("default")))
void map_del(struct map *map, char *key)
{
    (void) map;
    (void) key;
}

/* Destroys a map */
__attribute__((visibility("default")))
void map_destroy(struct map *map)
{
    (void) map;
    return;
}
