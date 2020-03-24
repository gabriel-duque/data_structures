#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

/* A simple wrapper around malloc */
static inline void *xmalloc(size_t size)
{
    void *ptr;

    if ((ptr = malloc(size)) == NULL)
        perror("map");

    return ptr;
}

/* Compute the hash for a given string */
static inline uint32_t hash(char *str)
{
    uint32_t hash;

    hash = 0;

    for(; *str; ++str) {
        hash += *str;
        hash += hash * 1024;
        hash ^= hash / 64;
    }

    hash += hash * 8;
    hash ^= hash / 2048;
    hash += hash * 32768;

    return hash;
}

/* Create a new pair */
static inline struct pair *pair_init(uint32_t hkey, char *key, void *value)
{
    struct pair *pair;

    if ((pair = xmalloc(sizeof(struct pair))) == NULL)
        return NULL;

    pair->hkey = hkey;
    pair->key = key;
    pair->value = value;

    return pair;
}

/* Destroy a list of pairs */
static inline void pair_destroy(struct pair *pair, void (*destructor) (void*))
{
    struct pair *curr;

    while (pair != NULL) {
        curr = pair;
        pair = pair->next;

        if (destructor != NULL)
            destructor(curr->value);

        free(curr);
    }
}

/* Actually add a new element to our map */
static inline int _map_add(struct map *map, uint32_t hkey,
                           char *key, void *value,
                           void (*destructor) (void*))
{
    struct pair *pair;

    pair = map->tab[hkey % map->capacity];

    if (pair == NULL) {
        map->tab[hkey % map->capacity] = pair_init(hkey, key, value);
        map->size++;
        return 1;
    }

    for (; pair->next != NULL; pair = pair->next) {
        if (pair->hkey == hkey && !strcmp(pair->key, key)) {
            if (destructor != NULL)
                destructor(pair->value);
            pair->value = value;
            return 0;
        }
    }

    pair->next = pair_init(hkey, key, value);
    map->size++;

    return 1;
}

/* Resize our map */
static inline void map_resize_up(struct map *map)
{
    void *ptr;
    struct pair **old_tab;
    struct pair *prev;
    struct pair *pair;

    old_tab = map->tab;

    /* Just keep the current tab if we can't allocate a bigger one */
    if ((ptr = xmalloc(map->capacity * sizeof(struct pair))) == NULL)
        return;

    map->capacity *= 2;
    map->tab = ptr;

    for (size_t i = 0; i < map->capacity; ++i)
        map->tab[i] = NULL;

    for (size_t i = 0; i < map->capacity; ++i) {
        pair = old_tab[i];
        while (pair != NULL) {
            prev = pair;
            pair = pair->next;
            _map_add(map, prev->hkey, prev->key, prev->value, NULL);
            free(prev);
        }
    }
}

/* Returns a new map */
__attribute__((visibility("default")))
struct map *map_init(size_t capacity)
{
    struct map *map;

    if (capacity == 0 || (map = xmalloc(sizeof(struct map))) == NULL)
        return NULL;

    if ((map->tab = xmalloc(capacity * sizeof(struct pair))) == NULL) {
        free(map);
        return NULL;
    }

    map->size = 0;
    map->capacity = capacity;

    for (size_t i = 0; i < capacity; ++i)
        map->tab[i] = NULL;

    return map;
}

/* Add a new entry into the map */
__attribute__((visibility("default")))
int map_add(struct map *map, char *key,
            char *value, void (*destructor) (void*))
{
    uint32_t hkey;

    if (map->size >= RESIZE_THRESH * map->capacity)
        map_resize_up(map);

    hkey = hash(key);

    return _map_add(map, hkey, key, value, destructor);
}

/* Delete an entry from the map */
__attribute__((visibility("default")))
void map_remove(struct map *map, char *key, void (*destructor) (void*))
{
    struct pair *prev;
    struct pair *pair;
    uint32_t hkey;

    hkey = hash(key);
    pair = map->tab[hkey % map->capacity];

    if (pair == NULL)
        return;

    if (pair->next == NULL && hkey == pair->hkey && !strcmp(pair->key, key))
        map->tab[hkey % map->capacity] = NULL;

    while (pair != NULL) {
        prev = pair;
        pair = pair->next;
        if (prev->hkey == hkey && !strcmp(prev->key, key)) {
            if (pair == NULL)
                prev->next = NULL;
            else
                prev->next = pair->next;
            if (destructor != NULL)
                destructor(pair->value);
            free(pair);

            return;
        }
    }
}

/* Get a entry from the map or NULL if it isn't present */
__attribute__((visibility("default")))
struct pair *map_get(struct map *map, char *key)
{
    uint32_t hkey;

    hkey = hash(key);

    for(struct pair *pair = map->tab[hkey % map->capacity];
        pair != NULL;
        pair = pair->next)
        if (pair->hkey == hkey && !strcmp(pair->key, key))
            return pair;

    return NULL;
}

/* Destroys a map */
__attribute__((visibility("default")))
void map_destroy(struct map *map, void (*destructor) (void*))
{
    for (size_t i = 0; i < map->capacity; ++i)
        if (map->tab[i] != NULL)
            pair_destroy(map->tab[i], destructor);

    free(map);
}
