#ifndef STACK
#define STACK

#include "../macros.h"

typedef struct _stack *stack;

// Operations
stack stack_new(void);

void stack_push(stack s, void *data);

void stack_pop(stack s);

bool stack_is_empty(stack s);

stack stack_destroy(stack s);

u32 stack_len(stack s);

void *stack_front(stack s);

#endif /* STACK */