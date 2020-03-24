#ifndef MAP_H
#define MAP_H

#include <stdint.h>

/* A structure for a map entry */
struct pair {
    uint32_t hkey;
    char *key;
    void *value;
    struct pair *next;
};

/* The actual map structure */
struct map {
    size_t size;
    size_t capacity;
    struct pair **tab;
};

/* Returns a new map */
struct map *map_init(size_t capacity);

/* Get a entry from the map or NULL if it isn't present */
struct pair *map_get(struct map *map, char *key);

/* Add a new entry into the map */
int map_add(struct map *map, char *key,
            char *value, void (*destructor) (void*));

/* Delete an entry from the map */
void map_remove(struct map *map, char *key, void (*destructor) (void*));

/* Destroys a map */
void map_destroy(struct map *map, void (*destructor) (void*));

/* The threshold for resizing */
#define RESIZE_THRESH 0.75f

#endif /* !MAP_H */
