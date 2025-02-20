#ifndef TILEMAP_H
#define TILEMAP_H

#define 

#define TILE_GROUP_WIDTH (100)

#define TILE_UP    (0)
#define TILE_RIGHT (1)
#define TILE_DOWN  (2)
#define TILE_LEFT  (3)

typedef enum tile_state {
    AIR = 0,
    BLOCK
} tile_state;

typedef struct tile {
    int id;
    tile_state state;
} tile;

typedef struct tile_group {
    tile tiles[TILE_GROUP_WIDTH][TILE_GROUP_WIDTH];
    int adj_list[4];
} tile_group;

#endif // TILEMAP_H
