#include "bitset.h"

#include "memutils.h"

#define TRUE8 ((char) 1)
#define FALSE8 ((char) 0)

#define BOOL8(x) ((x) ? TRUE8 : FALSE8)

// as noted in header, bitset_zero rounds up to next byte (8 bits)

void *bitset_zero(void *bitset, size_t n_bits) {
    return memzero(bitset, BITSET_SIZE(n_bits));
}

bool bitset_get(void *bitset, size_t idx) {
    return ((char *) bitset)[idx / 8] & (TRUE8 >> (idx % 8));
}

bool bitset_set(void *bitset, size_t idx, bool val) {
    char* ptr = ((char*) bitset) + (idx / 8);
    int sh = idx % 8;

    *ptr &= ~(TRUE8      >> sh);
    *ptr |=  (BOOL8(val) >> sh);

    return val;
}

char *bitset_str(char *dst, void *bitset, size_t n_bits) {
    for (size_t i = 0; i < n_bits; i++) {
        dst[i] = bitset_get(bitset, i) ? '1' : '0';
    }

    return dst;
}
