#ifndef RING_BUFFER_H
#define RING_BUFFER_H

typedef struct ring_buffer {
    size_t size;
    size_t begin;
    size_t end;
    char[] data;
} ring_buffer;

void ring_buffer_init(ring_buffer* rb);
void ring_buffer_append(ring_buffer *rb, void *src, size_t count);
void ring_buffer_consume(ring_buffer *rb, void *dst, size_t count);

#endif // RING_BUFFER_H
