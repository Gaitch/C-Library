#include <stdint.h>

typedef struct
{

}queue;

typedef enum
{

}errorCode;

errorCode enqueue(queue* q, int32_t value);

errorCode dequeue(queue* q, int32_t* value);

void initQ(queue* q);

queue* newQ(int32_t size);