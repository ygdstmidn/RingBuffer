# RingBuffer

## 注意事項
どうせ自分しか使わないからシンプルに，やりたいように作った\
バッファがあふれたらもう使い物にならん．バッファを作り直してくれ\
~~いっぱいになったときにPutできなくなる~~\
**いっぱいになった後，最初の1文字が上書きされ続ける**(やばすぎやろ...)

## 使用例

### 初期化
```c
RingBuffer rb;
```
```c
RingBuffer_Init(&rb, 256);
```
Initしたときにmallocしてメモリ確保に失敗すると1が返ってくる．

### Put
```c
void IRQ_handler()
{
    unsigned char data; // = UART_Receive();
    RingBuffer_Put(&rb, data);
}
```
割り込み処理関数で使うことを想定

### Get
```c
unsigned char data[256];
unsigned int i = 0;
__disable_irq();
if (rb.isntFull == 1)
{
    while (rb.head != rb.tail)
    {
        data[i] = RingBuffer_Get(&rb);
    }
}
else
{
    printf("Buffer is full\n");
    Error_Handler();
}
__enable_irq();
```
別のバッファに移して使う
```c
unsigned char data[256];
unsigned int i = 0;
__disable_irq();
while (rb.head != rb.tail||rb.isntFull == 1)
{
    data[i] = RingBuffer_Get(&rb);
    __enable_irq();
    __disable_irq();
}
if(rb.isntFull == 0)
{
    printf("Buffer is full\n");
    Error_Handler();
}
__enable_irq();
```
こっちの方がいいかなぁ?

### メモリ開放
```c
RingBuffer_Destroy(&rb);
```
メモリは開放すること
```c
if(rb.isntFull == 0)
{
    RingBuffer_Destroy(&rb);
    RingBuffer_Init(&rb, 256);
}
```
バッファがあふれたらバッファを作り直すことをお勧めする\
というか，これが起きないようにバッファは大きめに確保しようね☆\
作り直すときは割り込みを無効にしてからやらないと

## memo
```terminal
gcc main.c RingBuffer.c
```
同時にコンパイルしないとエラーになるよ