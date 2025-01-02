#include <math.h>
#include <sys/types.h>

typedef struct map_entry {
        const char* key;
        int value;

} map_entry;

typedef struct map {
        size_t total_capacity;
        size_t length;
        int (*_hash_function)(unsigned char*);

        map_entry *entries;
} map;

map* new_map();

map* new_map_with_hash(int (*hash_function)(unsigned char*));

void del_map(map* map);

char* map_set(map* map, char* key, int value);

int map_get(map* map, char* key);

int pjw_hash(unsigned char* key);
