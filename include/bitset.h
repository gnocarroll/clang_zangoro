// Basic bitset functionality for use with memory buffer

#include <stdbool.h>
#include <stddef.h>

// note: bitset_zero will round up to the next byte so it may zero beyond the
// precise number of bits requested

void *bitset_zero(void *bitset, size_t n_bits);
bool bitset_get(void *bitset, size_t idx);
bool bitset_set(void *bitset, size_t idx, bool val);

// you provide char * to bitset_str, it will not allocate anything

char *bitset_str(char *dst, void *bitset, size_t n_bits);

#define BITSET_SIZE(n_bits) ((n_bits - 1) / sizeof(char) + 1)
