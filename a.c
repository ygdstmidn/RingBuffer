#if(0)

#include <stdio.h>
#include "RingBuffer.h"

int main()
{
    RingBuffer rb;
    RingBuffer_Init(&rb, 10);
    for (int i = 0; i < 12; i++)
    {
        RingBuffer_Put(&rb, i);
    }
    printf("%d\n", rb.isntFull);
    for (int i = 0; i < 10; i++)
    {
        printf("%d", RingBuffer_Get(&rb));
    }
    printf("\n");
    RingBuffer_Destroy(&rb);

    RingBuffer rb2;
    RingBuffer_Init(&rb2, 10);
    for (int i = 0; i < 9; i++)
    {
        RingBuffer_Put(&rb2, i);
    }
    printf("%d\n", rb2.isntFull);
    while (rb2.head != rb2.tail)
    {
        printf("%d", RingBuffer_Get(&rb2));
    }
    printf("\n");

    for (int i = 0; i < 9; i++)
    {
        RingBuffer_Put(&rb2, i);
    }
    printf("%d\n", rb2.isntFull);
    while (rb2.head != rb2.tail)
    {
        printf("%d", RingBuffer_Get(&rb2));
    }
    printf("\n");

    RingBuffer_Destroy(&rb2);

    return 0;
}

#endif
