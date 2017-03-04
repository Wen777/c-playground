#include <stdio.h>
#include <string.h>
#include "hanoi_stack_array_D0565617.h"

void NewStack(Stack *s, char name[8]) {
    //s->pre = NULL;
    strcpy(s->name,name);
    s->ptr = -1;
}

void Push(Stack *s, int num){
    if(s->ptr + 1 == max) {
        printf("Stack %s overflow", s->name);
        return;
    }
    s->elem[++s->ptr] = num;
};

int Pop(Stack *s){
    if(s->ptr - 1 < -1) {
        printf("Stack %s underflow", s->name);
        return -9999;
    }
    int temp = s->elem[s->ptr --];
    return temp;
};

void PrintStack(Stack *s) {
    int temp;
    printf("Peg %s :", s->name);
    for(temp = 0; temp <= s->ptr; temp ++) {
        printf("%2d", s->elem[temp]);
    }
    printf("\n");
}
