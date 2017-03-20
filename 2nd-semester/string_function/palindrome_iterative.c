/*
  This program repeatedly reads a string and checks whether it is a palindrome or not.
  The program stops when the input string is "000".
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Palindrome check function, iterative version.
int is_palindrome(char *s, int head, int tail) {
    if (head + 1 == tail || strlen(s) / 2 == head + 1) {
        printf("Final head %d tail %d\n", head, tail);
        return 1;
    }

    printf("Round %d, head %d tail %d\n", head + 1, head, tail);
    if (s[head++] == s[tail--]) {
        return is_palindrome(s, head, tail) ; // If the entire string passes the check, s is a palindrome.
    } else {
        printf("Stop\n");
        return 0;
    }
}

int main(void) {
  char str[101]; // Input string, maximum 100 characters.
  
  while (1) { // Continue until "000" is read.
    printf("Enter a string: "); // Enter a string without spaces and punctuations.
    scanf("%s", str);
    
    if (strcmp(str, "000")) { // If the string is not "000".
      if (is_palindrome(str, 0, strlen(str) - 1)) printf("**** %s is a palindrome.\n", str); // Palindrome check succeeds.
      else  printf("**** %s is not a palindrome.\n", str); // Palindrome check fails.
      printf("------------------------------------------------\n");
    }  
    else {
      printf("\n"); // String entered is "000". 
      return 0; // Retrun from the main program (program terminates).
    }
  }
}
