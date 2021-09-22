#include <stdio.h>

List Stack;

void makenullStack(Stack *pS){
    makenullList(pS);
}

int emptyStack(Stack S){
    emptyList(S);
}

void top(Stack S){
    return retrieve(first(S),S);
}

void push(ElementType X, Stack *pS){
    inserstList(X,first(*pS),pS);
}

void pop(Stack *pS){
    deleteList(first(*pS),pS);
}

