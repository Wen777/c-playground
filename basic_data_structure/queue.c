#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 100

typedef struct {
    int count;
    int head;
    int tail;
    int data[MAXLEN];
} Queue;

void queueInit(Queue *q) {
    //head has data, tail does't
    q->head = q->tail = q->count = 0 ;
}

void queueAdd(Queue *q, int val) {
    if (q->count >= MAXLEN) {
        printf("Queue is full\n");
        exit(0);;
    }
    // add to tail
    q->data[q->tail++] = val;
    // if tail is bigger than the size of array. Assign is as 0
    q->tail %= MAXLEN;
    q->count++;
}

int queueRemove(Queue *q) {
    int tmp;
    if (q->count <= 0) {
        printf("Queue is empty\n");
        exit(0);
    }

    q->count --;
    tmp = q->data[q->head++];
    //if head is bigger than the size of array. Assign it as 0
    q->head %= MAXLEN;
    return tmp;
}

int queueIsFull(Queue *q) {
    return q->count >= MAXLEN;
}

int queueIsEmpty(Queue *q) {
    return q->count <= 0;
}

int main() {
    Queue q;
    queueInit(&q);
    queueAdd(&q, 100);
    queueAdd(&q, 200);
    printf("%d\n", queueRemove(&q));
    printf("%d\n", queueRemove(&q));
    return 0;
}
