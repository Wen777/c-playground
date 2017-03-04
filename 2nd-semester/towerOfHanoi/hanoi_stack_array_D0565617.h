#define max 12 // Maximum 12 disks.
typedef struct {
    char name[8]; // Stack name.
    int elem[max]; // Holding stack elements; using integers to represent disks.
    int ptr; // Pointer to the top of stack; initial value is -1.
    //struct Stack pre
} Stack;

void NewStack(Stack *s, char name[8]);

void Push(Stack *s, int num);

int Pop(Stack *s);

void PrintStack(Stack *s);
