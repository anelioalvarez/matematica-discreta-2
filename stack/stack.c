#include "stack.h"


typedef struct _node *node;

struct _node {
    void *data;
    node next;
};

struct _stack {
    node first;
    u32 size;
};

// Implementation
stack stack_new(void)
{
    stack s = (stack)malloc(sizeof(struct _stack));
    assert(s != NULL);

    s->first = NULL;
    s->size = 0u;

    return s;
}

void stack_push(stack s, void *data)
{
    assert(s != NULL);
    node new_node = (node)malloc(sizeof(struct _node));
    assert(new_node != NULL);

    new_node->data = data;
    new_node->next = s->first;
    s->first = new_node;
    ++s->size;
}

void stack_pop(stack s)
{
    assert(s != NULL && !stack_is_empty(s));

    node delete_node = s->first;
    s->first = s->first->next;
    free(delete_node);
    --s->size;
}

bool stack_is_empty(stack s)
{
    assert(s != NULL);
    return (s->first == NULL && s->size == 0u);
}

stack stack_destroy(stack s)
{
    assert(s != NULL);
    while (!stack_is_empty(s))
        stack_pop(s);
    
    free(s);
    s = NULL;
    return s;
}

u32 stack_len(stack s)
{
    assert(s != NULL);
    return s->size;
}

void *stack_front(stack s)
{
    assert(s != NULL && !stack_is_empty(s));
    return s->first->data;
}
