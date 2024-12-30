# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>

typedef struct stack
{
    int content;
    struct stack *next;
    struct stack *prev;
}stack;

#endif