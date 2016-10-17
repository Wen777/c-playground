// An implementation of a char stack

#include<stdlib.h>
#include<stdio.h>
#define MAXLEN 100

typedef char Data;
typedef struct _stack {
    int top;
    Data data[MAXLEN];
} Stack;

void stackInit(Stack *s) {
    s-> top = 0;
}

Data stackPop(Stack *s) {
    return s-> data [--s->top];
}

Data stackPush(Stack *s, Data x) {
    s-> data[s-> top++] = x;
    return x;
}

int main(void) {
    Stack s;
    stackInit(&s);
    printf("push %c\n", stackPush(&s, 'a') );
    printf("push %c\n", stackPush(&s, 'b'));
    printf("pop %c\n", stackPop(&s) );
    printf("pop %c\n", stackPop(&s));
    return 0;
}
