#ifndef MAP_H
#define MAP_H

#include <stdint.h>

/* A structure for a map entry */
struct entry {
    uint32_t hash;
    char *key;
    void *value;
    struct entry *next;
};

/* The actual map structure */
struct map {
    size_t size;
    size_t capacity;
    struct entry **tab;
};

/* Returns a new map */
struct map *map_init(size_t capacity);

/* Get a entry from the map or NULL if it isn't present */
struct entry *map_get(struct map *map, char *key);

/* Add a new entry into the map */
int map_add(struct map *map, char *key, char *value);

/* Delete an entry from the map */
void map_del(struct map *map, char *key);

/* Destroys a map */
void map_destroy(struct map *map);

#endif /* !MAP_H */
