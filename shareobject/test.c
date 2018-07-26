#include <stdio.h>
#include "mystack.h"

/*
 * call functions in mystack library
 */
void main(void)
{
    ElementTP a;
    int i;
    STACK sk;
    sk = init_stack();
    push(sk, 1);
    push(sk, 2);
    push(sk, 8);
    printf("Stack is null? %d\n", is_null(sk));
    for (i=0; i<3; i++) {
        a = pop(sk);
        printf("pop: %d\n", a);
    }

    printf("Stack is null? %d\n", is_null(sk));    
    delete_stack(sk);
}