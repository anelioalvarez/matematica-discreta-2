#include "queue.h"

typedef struct _node *node;

struct _node {
    void *data;
    node next;
};

struct _queue {
    node first;
    node last;
    u32 size;
};

// Implementation
queue queue_new(void)
{
    queue q = (queue)malloc(sizeof(struct _queue));
    
    assert(q != NULL);
    q->first = NULL;
    q->last = NULL;
    q->size = 0u;
    return q;
}

void queue_enqueue(queue q, void *data)
{
    assert(q != NULL);
    node new_node = (node)malloc(sizeof(struct _node));

    assert(new_node != NULL);
    new_node->data = data;
    new_node->next = NULL;

    if (queue_is_empty(q)) {
        q->first = new_node;
        q->last = new_node;
    }
    else {
        q->last->next = new_node;
        q->last = new_node;
    }

    ++q->size;
}

void queue_dequeue(queue q)
{
    assert(q != NULL && !queue_is_empty(q));

    node delete_node = q->first;
    if (queue_len(q) == 1u) {
        q->first = NULL;
        q->last = NULL;
    }
    else {
        q->first = q->first->next;
    }

    free(delete_node->data); // o funcion encargada de destruir el Nodo por completo
    free(delete_node);
    delete_node = NULL;
    
    --q->size;
}

bool queue_is_empty(queue q)
{
    assert(q != NULL);
    return (q->first == NULL && q->last == NULL && q->size == 0u);
}

queue queue_destroy(queue q)
{
    assert(q != NULL);
    while (!queue_is_empty(q))
        queue_dequeue(q);
    
    free(q);
    q = NULL;
    return q;
}

u32 queue_len(queue q)
{
    assert(q != NULL);
    return q->size;
}

void *queue_front(queue q)
{
    assert(q != NULL && !queue_is_empty(q));
    return q->first->data;
}
