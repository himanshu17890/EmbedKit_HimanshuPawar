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
// creating a empty check function 
int ringbuf_is_empty(RingBuffer *rb){
    return(rb -> count == 0);
}

int main (){
     RingBuffer rb;

    if(ringbuf_is_empty(&rb)){
        printf("Buffer is Empty\n");

    }else{
        printf("Buffer is not empty\n");
    }
    //printf("Ring Buffer Assignment\n");
   

    ringbuf_init(&rb);

    printf("Head = %d\n", rb.head);
    printf("tail = %d\n", rb.tail);
    printf("count = %d\n", rb.count);

    return 0;
} 

