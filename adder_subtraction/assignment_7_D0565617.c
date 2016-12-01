// This program is to simulate the combinational logic design of a 32-bit binary adder.
#include <stdlib.h>
#include <stdio.h>

// Output the 32-bit binary representation of decimal number n.
void printBinary(unsigned int n) {
  int i; // loop vairable

  for (i=1; i<=32; i++) { // Output all 32 bits.
    printf("%d", (n>>(32-i))&0X00000001); // Output a bit of n from left to right.
    if (i%4==0) printf(" "); // Print a space every four bits.
  }
}

/*
  Parameters x and y represent the two input bits. Parameters s and c represent
  the sum bit and the carry bit, respectively. The initial value of parameter c is
  the carry_in and its final value is the carry_out. Note that, parameters s and c
  are declared as call-by-address variables. Hence, the assignment statements in
  "fullAdder" should be "*s = ...; *c = ...;" The initial value of parameter c
  is the input value of the carry bit. The final value of parameter c is the output
  value of the carry bit. The final value of parameter s is the output value of
  the sum bit. All values of x, y, c, and s should be either 0 or 1 only.
*/
void fullAdder (int x, int y, int *c, int *s) {
  *s = (x ^ y) ^ *c; // s = (x xor y) xor c_in.
  *c = (x & y) | (*c & (x ^ y)); // c_out = (x and y) or (c_in and (x xor y))
}

/*
  Parameters X and Y are two positive integers which are represented as two 32-bit
  binary numbers. Parameter c represents the carry bit and it is call-by-address.
  Its input value 0 and its final value is returned to inidcate  overflow situation.
  If the final value is 0, then overflow does not occur; otherwise, overflow occurs.
  Function Adder will return the sum, S, of X and Y. S is also a 32-bit binary number.
  Variable pos represents the poistion of the bit being processed. The least significant
  bit is of position 0 and the most significant bit is of position 31. The value of
  variable S is returned at the end of function Adder. Variable x, y, and s represent
  the current bit of X, Y, and S, respectively, that will be processed by fullAdder.
*/
int adder(unsigned int X, unsigned int Y, int *c) {
  unsigned int S; // At the end S=X+Y and its value is returned.
  int pos; // Position, from right to left. of the current bit to apply full adder.
  int x, y, s; // A single bit of X, Y, and S, respectively.

  for (pos=0; pos<32; pos++) { // 32-bit adder.
    x = X & 1; // Set x to the current bit of X, i.e., the least significant bit of X.
    y = Y & 1; // Set y to the current bit of Y, i.e., the least significant bit of Y.
    // Perform fullAdder to add x, y , and the carry in c and
    // to yield the sum bit s and the carry out c.
    // Note that c is a pointer to an integer.
    fullAdder(x, y, c, &s);
    // The shift operation is to move the next processed bit of X and Y to the least significant bit.
    X = X >> 1; // Update X to shift its bits one position to the right-hand-side.
    Y = Y >> 1; // Update Y to shift its bits one position to the right-hand-side.
    // Place the sum bit s in sum to the appropriate position of S specified by pos.
    S = S | (s << pos);
  }
  // Return the result sum.
  return S;
}

int suber(unsigned int X, unsigned int Y, int *c) {
  unsigned int S; // At the end S=X+Y and its value is returned.
  int pos; // Position, from right to left. of the current bit to apply full adder.
  int x, y, s, checker; // A single bit of X, Y, and S, respectively.

  for (pos=0; pos<32; pos++) { // 32-bit adder.
    x = X & 1; // Set x to the current bit of X, i.e., the least significant bit of X.
    y = (Y & 1) ^ 1; // Set y to the current bit of Y, i.e., the least significant bit of Y.
    checker = *c;
    fullAdder(x, y, c, &s);
    X = X >> 1; // Update X to shift its bits one position to the right-hand-side.
    Y = Y >> 1; // Update Y to shift its bits one position to the right-hand-side.
    S = S | (s << pos);
  }
  *c = checker ^ *c;
  return S;
}


int main(void) {
  unsigned int X, Y, S; // To compute S=X+Y.
  int c; // Carry bit.
  char operator;

  while (1){ // Continue to process the adder until both input are 0's.
    // Input two 32-bit positive integers.
    printf("Enter two non-negative integers between 0 and 4,294,967,295: ");
    scanf("%u %c %u", &X, &operator, &Y);
    if (X==0 && Y==0) break; // If both X and Y are 0, stop the loop and terminate the program.

    if (operator == '-') {
        c = 1; // Initial carry in to 0.
        S = suber(X, Y, &c);
    } else if (operator == '+' && X < sizeof(1) / 2 ) {
        c = 0; // Initial carry in to 0.
        S = adder(X, Y, &c); // Call function adder().
    }
    printf("X = %-10d  Binary value: ", X); // Output decimal value of X with left alignment.
    printBinary(X); // Output binary value of X.
    printf("\n"); // Output a new line.
    printf("Y = %-10d  Binary value: ", Y); // Output decimal value of Y with left alignment.
    printBinary(Y); // Output binary value of Y.
    printf("\n"); // Output a new line.
    printf("S = %-10d  Binary value: ", S); // Output decimal value of the sum S with left alignment.
    printBinary(S); // Output binary value of S.
    printf("\n"); // Output a new line.

    if (operator == '-') {
    // Print the confirming message. The else case should not be executed.
    if (X-Y==S) printf("Correct! Adder operation test: %d - %d = %d\n", X, Y, S);
    else printf("Incorrect! Adder operation test: %d - %d != %d\n", X, Y, S);

    } else if (operator == '+') {
    // Print the confirming message. The else case should not be executed.
    if (X+Y==S) printf("Correct! Adder operation test: %d + %d = %d\n", X, Y, S);
    else printf("Incorrect! Adder operation test: %d + %d != %d\n", X, Y, S);

    }


    // Print the overflow message.
    if (c!=0) printf("**** The addition operation is overflow. c = %d\n", c); // If the final carry_out is 1, overflow occurs.

    printf("-----------------------------------------------------\n"); // Print a separated line.
  }

  return 0;
}
