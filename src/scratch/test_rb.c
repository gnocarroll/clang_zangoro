#include "scratch/test_rb.h"

#include <stdio.h>
#include <string.h>

#include "ring_buffer.h"

char text[5000]  = { 0 };
char text2[1000] = { 0 };
char dest[10000] = { 0 };

DECL_RING_BUFFER(2048)

// test ring buffer

void test_rb(void) {
    memset(text,  'A', 5000);
    memset(text2, 'B', 1000);

    ring_buffer_2048 rb;

    ring_buffer_init((ring_buffer *) &rb);
    ring_buffer_set_size((ring_buffer *) &rb, 2048);

    long ret1 = ring_buffer_append((ring_buffer*) &rb, text2, 1000);

    printf("APPEND RET: %ld, COUNT: %ld\n", ret1, ring_buffer_count(&rb));

    long ret2 = ring_buffer_consume((ring_buffer*) &rb, dest, 500);
    
    printf("CONSUME RET: %ld, COUNT: %ld\n", ret2, ring_buffer_count(&rb));

    long ret3 = ring_buffer_append((ring_buffer*) &rb, text, 5000);
    
    printf("APPEND RET: %ld, COUNT: %ld\n", ret3, ring_buffer_count(&rb));
}
