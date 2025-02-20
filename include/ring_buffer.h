#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdbool.h>
#include <stddef.h>

// to use define your own struct which contains this as its first member
// then set the size properly and you can cast a pointer to your struct to a
// ring_buffer * to use these functions with it

typedef struct ring_buffer {
    size_t size;     // buffer capacity
    size_t begin;    // first occupied byte and where data is consumed from
    size_t end;      // one after last occupied, data is added here
    bool   is_empty; // take a wild guess...
    char   data[];   // in your struct there would be buffer after
} ring_buffer;

void ring_buffer_init(ring_buffer* rb);
void ring_buffer_set_size(ring_buffer* rb, size_t size);
long ring_buffer_append(ring_buffer *rb, void *src, size_t count);
long ring_buffer_consume(ring_buffer *rb, void *dst, size_t count);
long ring_buffer_count(ring_buffer *rb);

// macro which you could use to create ring buffer type with capacity cap

#define DECL_RING_BUFFER(CAP)          \
    typedef struct ring_buffer_##CAP { \
        ring_buffer rb;                \
        char data[CAP];                \
    } ring_buffer_##CAP;

#endif // RING_BUFFER_H
