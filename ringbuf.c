#include <stdio.h>
#include <stdint.h> 

#define BUFFER_SIZE 8 

typedef struct{
    uint8_t buffer[BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;


}RingBuffer;
int main (){
    printf("Ring Buffer Assignment\n");
    return 0;
} 