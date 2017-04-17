#include <stdio.h>
#include <stdlib.h>

/*
    Our goal is demonstrating the idea of doubly link list. It includes basic
   functions
*/

typedef struct DulNode {
  int data;
  struct DulNode *prior;
  struct DulNode *next;
} DulNode;

typedef struct DulLinkLists {
  DulNode *head;
  DulNode *tail;
  int length;
} LinkList;

void printLinkList(LinkList *l) {
  int i;
  DulNode *tempNode;

  tempNode = (*l).head;

  printf("************************************************\n");
  printf("Length %d\n", l->length);
  for (i = l->length; i > 0; i--) {
    printf("%5d ->", tempNode->data);
    tempNode = tempNode->next;
  }
  printf("\n************************************************\n");
}

void reversePrintLinkList(LinkList *l) {
  int i;
  DulNode *tempNode;

  tempNode = l->tail;

  printf("************************************************\n");
  printf("Length %d\n", l->length);
  for (i = l->length; i > 0; i--) {
    printf("%5d <-", tempNode->data);
    tempNode = tempNode->prior;
  }
  printf("\n************************************************\n");
}

void appendLinkList(LinkList *l, int data) {
  DulNode *tempNode;
  tempNode = (DulNode *)malloc(sizeof(DulNode));
  tempNode->data = data;
  tempNode->prior = NULL;
  tempNode->next = NULL;

  if (l->length == 0) {
    l->head = tempNode;
    l->tail = tempNode;
    l->length++;
    return;
  }

  l->tail->next = tempNode;
  tempNode->prior = l->tail;
  l->tail = tempNode;
  l->length++;
  return;
}

int insertLinkList(LinkList *l, int index, int data) {
  DulNode *tempNode, *newNode;
  int i = 1;

  newNode = (DulNode *)malloc(sizeof(DulNode));
  newNode->data = data;
  newNode->prior = NULL;
  newNode->next = NULL;

  tempNode = l->head;

  if (index == 0 || index > l->length + 1) {
    free(newNode);
    return 0;
  }

  if (index == 1) {
    l->length++;
    l->head = newNode;
    newNode->next = tempNode;
    tempNode->prior = newNode;
    return 1;
  }

  while (i <= index && newNode->next != NULL) {
    if (i == index) {
      l->length++;
      tempNode->prior->next = newNode;
      newNode->prior = tempNode->prior;
      newNode->next = tempNode;
      tempNode->prior = newNode;
      break;
    }

    i++;
    tempNode = tempNode->next;
  }
  return 1;
}

void swapLinkList(LinkList *l, DulNode **a, DulNode **b) {
  if (NULL == l->head || NULL == (*a) || NULL == (*b)) {
    printf("\n Nothing to swap, just return \n");
    return;
  }

  DulNode *pre_a = (*a)->prior;
  DulNode *pre_b = (*b)->prior;

  DulNode *next_a = (*a)->next;
  DulNode *next_b = (*b)->next;

  if (pre_a != NULL) pre_a->next = (*b);
  if (pre_b != NULL) pre_b->next = (*a);
  if (next_a != NULL) next_a->prior = (*b);
  if (next_b != NULL) next_b->prior = (*a);

  (*a)->next = next_b;
  (*b)->next = next_a;

  (*a)->prior = pre_b;
  (*b)->prior = pre_a;

  if ((l->head) == (*a)) {
    l->head = *b;
  } else if ((l->head) == (*b)) {
    l->head = *a;
  }

  if ((l->tail) == (*a)) {
    l->tail = *b;
  } else if ((l->tail) == (*b)) {
    l->tail = *a;
  }
}

int switchIndex(LinkList *l, int address1, int address2) {
  int i;
  DulNode *tempNode1, *tempNode2, *node1pre, *node1next, *node2pre, *node2next;

  tempNode1 = l->head;
  i = 1;

  if (address1 < 0 || address1 > l->length || address2 < 0 ||
      address2 > l->length) {
    return 0;
  }

  // firstly, find the node whose index is address1
  while (i != address1) {
    i++;
    tempNode1 = tempNode1->next;
  }

  tempNode2 = l->head;
  i=1;
  while (i != address2) {
    i++;
    tempNode2 = tempNode2->next;
  }

  swapLinkList(l, &tempNode1, &tempNode2);
  return 1;
}

int main(void) {
  // init link list

  // another way to init link list
  // LinkList *list;
  // list = (LinkList *) malloc(sizeof(LinkList));
  // list->length = 0;

  LinkList list;
  list.length = 0;
  list.head = NULL;
  list.tail = NULL;

  // print empty link list
  printLinkList(&list);

  // append three new data
  appendLinkList(&list, 10);
  printLinkList(&list);

  appendLinkList(&list, 12);
  printLinkList(&list);

  appendLinkList(&list, 14);
  printLinkList(&list);

  appendLinkList(&list, 16);
  // print link list
  printLinkList(&list);

  // insert linklist to specific index
  insertLinkList(&list, 1, 22);
  printLinkList(&list);
  // change the index of two nodes

//   reversePrintLinkList(&list);
  switchIndex(&list, 1, 5);
  printLinkList(&list);
  reversePrintLinkList(&list);
}