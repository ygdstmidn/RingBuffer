#include "RingBuffer.h"

int RingBuffer_Init(RingBuffer *rb, unsigned int size)
{
    rb->buffer = (unsigned char *)malloc(size);
    if (rb->buffer == NULL)
    {
        return 1;
    }
    rb->size = size;
    rb->head = 0;
    rb->tail = 0;
    rb->isntFull = 1;
    return 0;
}

void RingBuffer_Destroy(RingBuffer *rb)
{
    free(rb->buffer);
    rb->buffer = NULL;
    rb->size = 0;
    rb->head = 0;
    rb->tail = 0;
    rb->isntFull = 1;
}

unsigned char RingBuffer_Get(RingBuffer *rb)
{
    unsigned char data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % rb->size;
    return data;
}

void RingBuffer_Put(RingBuffer *rb, unsigned char data)
{
    rb->buffer[rb->head] = data;
    rb->head = (rb->head + rb->isntFull) % rb->size;
    rb->isntFull = (rb->head != rb->tail);
}