#ifndef istack_included
#define istack_included

struct nodo{
    int dato;
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* stack;

stack* a_create();
int s_push (stack *, int);
int s_pop(stack *);
int s_top(stack);
int s_empty(stack);
int s_length(stack);

#endif
