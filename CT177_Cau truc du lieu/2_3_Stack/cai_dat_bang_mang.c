/*Cac phep toan*
 *  makenullStack(&S);
    emptyStack(S);
    full(S);
    push(X,&S);
    pop(&S);
    top(S);
 */ 
#include <stdio.h>

#define Maxlength 100

typedef int ElementType;

typedef struct{
    ElementType Elements[Maxlength];
    int Top_idx;
}Stack;

void makenullStack(Stack *pS){
    pS->Top_idx=Maxlength;
}

int emptyStack(Stack S){
    return S.Top_idx==Maxlength;
}

int full(Stack S){
    return S.Top_idx==0;
}

void push(ElementType x, Stack *pS){
    if(full(*pS))
        printf("Stack da day!!!");
    else{
        pS->Top_idx--;
        pS->Elements[pS->Top_idx]=x;
    }
}

void pop(Stack *pS){
    if(!emptyStack(*pS))
        pS->Top_idx++;
    else
        printf("Stack rong!!!");
        
}

ElementType top(Stack S){
    if(!emptyStack(S))
        return S.Elements[S.Top_idx];
    else{
        printf("Stack rong!!!");
        return 9999;
    }    
}
