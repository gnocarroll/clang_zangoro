#ifndef VECTORS_H
#define VECTORS_H

#include <stdarg.h>

#define VEC_NAME(T, n) vec##n

#define DECL_VEC(T, n)                                                 \
    typedef struct VEC_NAME(T, n) {                                    \
        T data[n];                                                     \
    } VEC_NAME(T, n);

#define VEC(n, ...) ((VEC_NAME(float, n)) {__VA_ARGS__})

DECL_VEC(float, 2)
DECL_VEC(float, 3)
DECL_VEC(float, 4)

#endif // VECTORS_H
