#include <stdio.h>
#include <stdint.h> 

#define BUFFER_SIZE 8 

typedef struct{
    uint8_t buffer[BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
}RingBuffer;

void ringbuf_init(RingBuffer *rb){
    rb -> head = 0;
    rb -> tail = 0;
    rb -> count = 0;

}

int main (){
    //printf("Ring Buffer Assignment\n");
    RingBuffer rb;

    ringbuf_init(&rb);

    printf("Head = %d\n", rb.head);
    printf("tail = %d\n", rb.tail);
    printf("count = %d\n", rb.count);

    return 0;
} 