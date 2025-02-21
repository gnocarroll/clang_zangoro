#include "ring_buffer.h"

#include <stdbool.h>
#include <stddef.h>

/*
 * definition for ring_buffer from ring_buffer.h:
 *
 * typedef struct ring_buffer {
 *   size_t size;
 *   size_t begin;
 *   size_t end;
 *   bool is_empty;
 *   char[] data;
 * } ring_buffer;
 *
 */

void ring_buffer_init(ring_buffer* rb) {
    rb->begin    = 0;
    rb->end      = 0;
    rb->is_empty = true;
}

ssize_t ring_buffer_count(ring_buffer *rb) {
    if (rb->size <= 0 || rb->is_empty) return 0;

    if (rb->begin >= rb->end) {
        return rb->size - rb->begin + rb->end;
    }

    return rb->end - rb->begin;
}

// add data to ring buffer

ssize_t ring_buffer_append(ring_buffer *rb, void *src, size_t count) {
    if (rb->size <= 0) return (ssize_t) -1;

    ssize_t src_idx = 0;

    while (src_idx < count) {
        if (rb->end == rb->begin) {
            if (!rb->is_empty) break;

            rb->is_empty = false;
        }

       rb->data[rb->end++] = ((char *) src)[src_idx++];

       if (rb->end >= rb->size) rb->end = 0; // wrap
    }

    return src_idx;
}

// consume / remove data from ring buffer

ssize_t ring_buffer_consume(ring_buffer *rb, void *dst, size_t count) {
    if ((rb->size <= 0) || (rb->is_empty)) return 0;

    ssize_t src_idx = 0;

    while (src_idx < count) {
        ((char *) dst)[src_idx++] = rb->data[rb->begin++];

        if (rb->begin >= rb->size) rb->begin = 0; // wrap

        if (rb->begin == rb->end) { // => consumed everything in buffer
            rb->is_empty = true;
            break;
        }
    }

    return src_idx;
}
