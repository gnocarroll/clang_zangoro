#include <stdio.h>

#include "bitset.h"

#define N_BITS (10)

int main() {
    char bitset[BITSET_SIZE(N_BITS)];
    char str[50] = { 0 };

    printf("%s\n", bitset_str(str, bitset, N_BITS));

    for (int i = 0; i < N_BITS; i += 2) {
        bitset_set(bitset, i, true);
    }
    
    printf("%s\n", bitset_str(str, bitset, N_BITS));

    printf("printing bits one by one...\n");

    for (int i = 0; i < N_BITS; i++) {
        printf("%d", bitset_get(bitset, i));
    }

    printf("\n");

    return 0;
}
