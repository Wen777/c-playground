#include <stdio.h>
#include "hanoi_stack_array_D0565617.h"

void printStacks(Stack *source1, Stack *source2, Stack *source3) {
    Stack *arr[3];
    arr[source1->name[0] - 'A'] = source1;
    arr[source2->name[0] - 'A'] = source2;
    arr[source3->name[0] - 'A'] = source3;

    PrintStack(arr[0]);
    PrintStack(arr[1]);
    PrintStack(arr[2]);
}

void hanoi(int n, Stack *sour, Stack *aux, Stack *dest) {
  static int step = 1;
  int temp;
  if (n > 0) {
    hanoi(n-1, sour, dest, aux);
    temp = Pop(sour);
    Push(dest, temp);

    printf("\n***********\n>>>>Step: %4d: Move disc %d from '%s' to '%s' \n", step++, n, sour->name, dest->name);

    printStacks(sour,aux,dest);

    hanoi(n-1, aux, sour, dest);
  }
}

int main(void) {
  int k,i  = 0;
  Stack a, b, c;
  NewStack(&a, "A");
  NewStack(&b, "B");
  NewStack(&c, "C");

  do {
    printf("Please enter the number of discs: ");
    scanf("%d",&k);
  } while (k<1 || k>12);

  for(i = k; i > 0; i--) {
    Push(&a, i);
  }

  printf("Initial pegs: \n");
  printStacks(&a, &b, &c);

  printf("\n");
  hanoi(k, &a, &b, &c);
  printf("Finish!!!\n");
  return 0;
}
