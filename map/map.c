#include "map.h"
#include <stdlib.h>
#include <string.h>

int pjw_hash(unsigned char* key) {
        int h = 0;
        for (int i = 0; key[i] != '\0'; i++) {
                h = (h << 4) + key[i];
                int g = h & 0xf0000000;
                if (g != 0) {
                        h = h ^ (g >> 24);
                        h = h ^ g;
                }
        }

        return h;
}

map* new_map() {
        map map = calloc(unsigned long, unsigned long)
        map = {
                .total_capacity = 17, 
                .length = 0, 
                .entries = NULL,
                ._hash_function = &pjw_hash};

        return &map;
}
