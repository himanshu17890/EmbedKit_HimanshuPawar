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

// creating a full check function 
int ringbuf_is_full(RingBuffer *rb){
    return(rb ->count == BUFFER_SIZE);

}

// creating a counting function 

uint8_t ringbuf_count(RingBuffer *rb){
    return rb-> count;
} 

// writing data 
int ringbuf_write(RingBuffer *rb, uint8_t data){
    if(ringbuf_is_full(rb)){
        return -1 ;
    }
 // storing the data 
    rb-> buffer[rb -> head] = data; 

// next move  head 
    rb->head =(rb -> head +1 )%BUFFER_SIZE;  

// incrementing the count 
    rb->count++; 

    return 0;


    
}

//reading data 


int ringbuf_read(RingBuffer *rb, uint8_t *data){
    // check if empty 
    if(ringbuf_is_empty(rb))
    {
        return -1;
    }

     // reading the value tail = 0
     //buffer[0] = 0x41
    *data = rb->buffer[rb->tail];

    // moving the tail 

    rb->tail = (rb->tail + 1) % BUFFER_SIZE;

    //Decreasing the count 

    rb->count--;

    return 0;

}

int main (){
     RingBuffer rb; 
     ringbuf_init(&rb);

     


    if(ringbuf_is_empty(&rb)){
        printf("Buffer is Empty\n");

    }else{
        printf("Buffer is not empty\n");
    }

    if(ringbuf_is_full(&rb)){
        printf("Buffer is full\n");

    }else {
        printf("buffer is not full\n");
    } 

    // writing operation 
    ringbuf_write(&rb, 0x41);
    ringbuf_write(&rb, 0x42);
    
    printf("Head = %d\n", rb.head);
    printf("Count = %d\n", rb.count); 

  // reading operation
    uint8_t data;

   ringbuf_read(&rb, &data);

   printf("Read Data = 0x%X\n", data);
   printf("Tail = %d\n", rb.tail);
   printf("Count = %d\n", rb.count);

   
    

    

    printf("current count = %u\n",ringbuf_count(&rb));
    //printf("Ring Buffer Assignment\n");
   
    
    ringbuf_init(&rb);

    printf("Head = %d\n", rb.head);
    printf("tail = %d\n", rb.tail);
    printf("count = %d\n", rb.count);

    return 0;
} 

