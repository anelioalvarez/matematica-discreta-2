#ifndef QUEUE
#define QUEUE

#include "../macros.h"

typedef struct _queue *queue;

// Operations
queue queue_new(void);

void queue_enqueue(queue q, void *data);

void queue_dequeue(queue q);

bool queue_is_empty(queue q);

queue queue_destroy(queue q);

u32 queue_len(queue q);

void *queue_front(queue q);


#endif /* QUEUE */