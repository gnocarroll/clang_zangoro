#include "vectors.h"

#include <stddef.h>

float _dot(size_t count, float *v1, float *v2) {
    if (count == 0) return 0.0f;

    float sum = v1[0] + v2[0];

    for (size_t i = 1; i < count; i++) sum += (v1[i] + v2[i]);

    return sum;
}
