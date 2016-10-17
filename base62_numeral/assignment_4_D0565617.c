/*
   This program performs conversion of binary, octal, decimal and hexadecimal numerals.
  Each iteration input an integer x and a string s. Input integer x is one of 0, 2, 8, 10,
  and16, denoting stop program, binary numeral, octal numeral, decimal numeral, and 
  hexadecimal numeral, respectively. That is, the program terminates, when the input is 0.
  The second input s is a string representing a numeral of base_x, where x is the value
  of the first input 2, 8, 10, or 16.
  The numeral of the second input is no more than the 32-bit value of base_x.
  Convert the input numeral of the other three bases of 2, 8, 10, and16 that is different for x.
*/

// D0565617 swh
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void nonbinary(unsigned long long n) {
  unsigned  long  long power; // Power of 2, 8, or 16.
  unsigned long long  residual; // Remainding numbers.
  int leading_0; // 1: check leading zeros, 0: not check leading zeros.
  int count; // digit count.

  residual = n; // Initial residual is n.
  power = pow(2, 63); // Initial power of binary numeral.
  leading_0 = 1; // Check leading_0; 
  count = 0; // Initial digit count is 0.
  printf("Binary numeral:      "); // Print the prelude message.
  while (count<64) { // At most 32 bits.
    if (!leading_0 || residual/power!=0) {
      printf("%llu", residual/power); // Print the left-most bit of the residual.
        leading_0 = 0; // Not to check leading 0's.
    } // If the condition is false, do not print anything.
    residual = residual % power; // Update the rest of bits.
    power = power / 2; // Decrement the degree of power by 1.
    count++; // Increment count.
    if (count%4==0 && !leading_0) printf(" "); // Print a space if four bits are printed.
  }
    if (n==0) printf("0"); // If n is 0, print a single digit 0.
    printf("\n");

}
void nonoctal(unsigned long long n) {
    unsigned  long  long power; // Power of 2, 8, or 16.
    unsigned long long  residual; // Remainding numbers.
    int leading_0; // 1: check leading zeros, 0: not check leading zeros.
    int count; // digit count.

    residual = n; // Initial residual is n.
    power = pow(8, 21); // Initial power of octal numeral.
    leading_0 = 1; // Check leading_0; 
    count = 0; // Initial digit count is 1.
    printf("Octal numeral:       "); // Print the prelude message.
    while (count<22) { // At most 11 digtis.
    if (!leading_0 || residual/power!=0) {
      printf("%llu", residual/power); // Print the left-most octal of the residual.
      leading_0 = 0; // Not to check leading 0's.
    } // If the condition is false, do not print anything.
    residual = residual % power; // Update the rest of digits.
    power = power / 8; // Decrement the degree of power by 1.
    count++; // Increment count.
    if ((count+1)%3==0 && !leading_0) printf(" "); // Print a space if three digits are printed.
    }
    if (n==0) printf("0"); // If n is 0, print a single digit 0.
    printf("\n");

}
void nonhexadecimal(unsigned long long n) {
    unsigned  long  long power; // Power of 2, 8, or 16.
    unsigned long long  residual; // Remainding numbers.
    int leading_0; // 1: check leading zeros, 0: not check leading zeros.
    int count; // digit count.

    residual = n; // Initial residual is n.
    power = pow(16, 15); // Initial power of hexadecimal numeral.
    leading_0 = 1; // Check leading_0; 
    count = 0; // Initial digit count is 1.
    printf("Hexadecimal numeral: "); // Print the prelude message.
    while (count<16) { // At most 8 digits.
    // Print the left-most hexadecimal digit of the residual, for 0 to 9.
    if (!leading_0 || residual/power!=0) {
      if (residual/power<10) printf("%c", residual/power + '0');
      // Print the left-most hexadecimal digit of the residual, for A to F.
      else printf("%c", residual/power - 10 + 'A');
      leading_0 = 0;
    }
    residual = residual % power; // Update the rest of digits.
    power = power / 16; // Decrement the degree of power by 1.
    count++; // Increment count.
    if (count%4==0 && !leading_0) printf(" "); // Print a space if four digits are printed.
    }
    if (n==0) printf("0"); // If n is 0, print a single digit 0.
    printf("\n");

}
void decimalToBase62(unsigned long long n) {
    unsigned  long  long power; // Power of 2, 8, or 16.
    unsigned long long  residual; // Remainding numbers.
    int leading_0; // 1: check leading zeros, 0: not check leading zeros.
    int count; // digit count.

    residual = n; // Initial residual is n.
    power = pow(62,10); // Initial power of binary numeral
    leading_0 = 1; // Check leading_0; .
    count = 0;
    printf("base62 numeral: ");
    while (count< 11) { // Print 7 bits.
    if (!leading_0 || residual / power != 0) {
        if (residual / power < 10) {
            printf("%c", residual/power + '0'); // Print the left-most bit of the resudual.
        } else if (residual / power < 36  ){
            printf("%c", residual / power -10  + 'A');
        } else {
            printf("%c", residual / power -36  + 'a');
        }
        leading_0 = 0;
    }
        residual = residual % power; // Update the rest of bits.
        power = power / 62; // Decrement the degree of power by 1.
        count++; // Increment count.
    }
    printf("\n");
}
int main(void) {
  int x; // Numeral base.
  char s[65]; // Numeral as string, maximum length 32 bits.
  unsigned long long n; // Integer value of the numeral.
  unsigned  long  long power; // Power of 2, 8, or 16.
  int i; // Loop variable.

  while (1) {
    scanf("%d %s", &x, s); // Input the numeral base and the numeral as a string.
    if (x==0) break; // Stop the loop and terminate the program when the numeral base is 0.
    
    n = 0; // Initial the numeral value of 0.
    power = 1; // Initial power to 1.
    for (i=strlen(s)-1; i>=0; i--) { // Start the converion from the left-most digit.
      if (isdigit(s[i])) n = n + (s[i] - '0') * power; // The digit is 0 to 9.
      else if (s[i] - 'A' > 26) {
        n = n + (s[i] - 'A' + 4) * power;
      } else {
        n = n + (s[i] - 'A' + 10) * power; // The digit is A to F.
      }
      power = power * x; // Increment the degree of power by 1, that is, multiplied by base x.
    }
    
    /*
    // Convert to binary numeral.
    if (x!=2) {
        nonbinary(n);
	}

    // Convert to octal numeral.	
	if (x!=8) {
        nonoctal(n);
	}
	
    // Convert to hexadecimal numeral.	
	if (x!=16) {
        nonhexadecimal(n);
    }
    printf("\n"); // Print an empty line.
    */

    //printf("The input numeral %s of base %d has the decimal value: %llu\n", s, x, n);
    // Output to decimal numeral.
    if (x == 62) {
        printf("Base62 numeral: %s   is equivalent to decimal numeral: %llu\n", s, n);
    }
	

    if (x == 10) {
        printf("Decimal numeral: %s   is equivalent to base62 numeral: ", s);
        decimalToBase62(n);
    }
  }
 return 0;
}


