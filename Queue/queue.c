#include <stdint.h>
#include <queue.h>

typedef struct
{
	int32_t readPos;
	int32_t writePos;
	int32_t count;
	int32_t size;
	int32_t data[];
}queue;

typedef enum
{
	ecSuccess,
	ecQueueFull,
	ecQueueEmpty
}errorCode;

errorCode enqueue(queue* q, int32_t value)
{
	if (q->count >= q->size)
	{
		return ecQueueFull;
	}

	q->data[q->writePos] = value;
	q->writePos++;

	q->writePos %= q->size;

	q->count++;
	return ecSuccess;
}

errorCode dequeue(queue* q, int32_t* value)
{
	if (q->count <= 0)
	{
		return ecQueueEmpty;
	}

	*value = q->data[q->readPos];
	q->readPos++;
	q->readPos %= q->size;
	q->count--;

	return ecSuccess;
}

void initQ(queue* q)
{
	q->count = 0;
	q->readPos = 0;
	q->writePos = 0;
}

queue* newQ(int32_t size)
{
	queue* q = malloc(sizeof(queue) + size * sizeof(int32_t));
	q->size = size;
	initQ(q);
	return q;
}