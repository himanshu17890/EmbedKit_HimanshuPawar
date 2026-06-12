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

int main()
{
    RingBuffer rb;
    uint8_t data;

    ringbuf_init(&rb);

    // Write 8 bytes 
    uint8_t write_data1[] = {
        0x41, 0x42, 0x43, 0x44,
        0x45, 0x46, 0x47, 0x48
    };

    for(int i = 0; i < 8; i++)
    {
        if(ringbuf_write(&rb, write_data1[i]) == 0)
        {
            printf("[WRITE] 0x%X -> OK (count=%u)",
                   write_data1[i],
                   ringbuf_count(&rb));

            if(ringbuf_is_full(&rb))
            {
                printf(" FULL");
            }

            printf("\n");
        }
    }

    //  Overflow Test 
    if(ringbuf_write(&rb, 0x99) == -1)
    {
        printf("[WRITE] 0x99 -> FAIL (buffer full)\n");
    }

    // Read 3 bytes 
    for(int i = 0; i < 3; i++)
    {
        if(ringbuf_read(&rb, &data) == 0)
        {
            printf("[READ] -> 0x%X (count=%u)\n",
                   data,
                   ringbuf_count(&rb));
        }
    }

    /* Write 3 new bytes */
    uint8_t write_data2[] = {0x49, 0x4A, 0x4B};

    for(int i = 0; i < 3; i++)
    {
        if(ringbuf_write(&rb, write_data2[i]) == 0)
        {
            printf("[WRITE] 0x%X -> OK (count=%u)\n",
                   write_data2[i],
                   ringbuf_count(&rb));
        }
    }

    /*  Read remaining 8 bytes */
    while(!ringbuf_is_empty(&rb))
    {
        if(ringbuf_read(&rb, &data) == 0)
        {
            printf("[READ] -> 0x%X (count=%u)\n",
                   data,
                   ringbuf_count(&rb));
        }
    }

    printf("Buffer Empty = %s\n",
           ringbuf_is_empty(&rb) ? "YES" : "NO");

    /*  Read from empty buffer */
    if(ringbuf_read(&rb, &data) == -1)
    {
        printf("[READ] (empty) -> FAIL (buffer empty)\n");
    }

    return 0;
}
