/* By Vamei */
/* use single-linked list to implement stack */
#include <stdio.h>
#include <stdlib.h>
#include "mystack.h"


/*
 * initiate the stack
 * malloc the head node.
 * Head node doesn't store valid data
 * head->next is the top node
 */
STACK init_stack(void)
{
    position np;
    STACK    sk;
    np = (position) malloc(sizeof(struct node));
    np->next     = NULL;  // sk->next is the top node
    sk = np; 
    return sk;
}

/* pop out all elements 
 * and then delete head node
 */
void delete_stack(STACK sk)
{
    while(!is_null(sk)) {
        pop(sk);
    }
    free(sk);
}
/* 
 * View the top frame
 */
ElementTP top(STACK sk)
{
    return (sk->next->element);
}

/*
 * push a value into the stack
 */
void push(STACK sk, ElementTP value) 
{
    position np, oldTop;
    oldTop = sk->next;    

    np = (position) malloc(sizeof(struct node));
    np->element  = value;
    np->next     = sk->next;

    sk->next     = np; 
}

/* 
 * pop out the top value
 */
ElementTP pop(STACK sk)
{
    ElementTP element;
    position top, newTop;
    if (is_null(sk)) {
        printf("pop() on an empty stack");
        exit(1);
    } 
    else {
        top      = sk->next;
        element  = top->element;     
        newTop   = top->next;
        sk->next     = newTop;
        free(top);
        return element;
    } 
}

/* check whether a stack is empty*/
int is_null(STACK sk)
{
    return (sk->next == NULL);
}