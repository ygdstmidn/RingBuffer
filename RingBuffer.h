/// @copyright Copyright © 2024 ygdstmidn
/// @license This file is released under the MIT License(https://opensource.org/license/mit)

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdlib.h>
#include <stddef.h>

typedef struct
{
    unsigned char *buffer;
    unsigned int size;
    unsigned int head;
    unsigned int tail;
    int isntFull;
} RingBuffer;

int RingBuffer_Init(RingBuffer *rb, unsigned int size);
void RingBuffer_Destroy(RingBuffer *rb);
unsigned char RingBuffer_Get(RingBuffer *rb);
void RingBuffer_Put(RingBuffer *rb, unsigned char data);
void RingBuffer_HeadMove(RingBuffer *rb);

#endif
