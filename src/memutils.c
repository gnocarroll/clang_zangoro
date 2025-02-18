#include "memutils.h"

#include <string.h>

void *memzero(void *ptr, size_t num) {
    return memset(ptr, 0, num);
}
