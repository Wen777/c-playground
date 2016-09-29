#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ID: D0565617, Name:施文祥, David

int main(void) {
  // A string is represented as a character array.
  // A word of string is of maximum 30 characters.
  char word[31];
  int word_count = 0; // Word count; initial value is 0.
  int vowel_count = 0; // Vowel count; initial value is 0.
  int i, j; // Loop variable.

  while (scanf("%s", word)==1) {
    for (j=0; j<strlen(word); j++) {
      switch (word[j]) {
        case '-':
            // if true, jump to 'Skip'
            if(word[j+1] == '-') goto Skip;
        case '\'':
            word[j] = ' ';
        case '\"':
            word[j] = ' ';
        case '!':
            word[j] = ' ';
        case ',':
            word[j] = ' ';
        case ';':
            word[j] = ' ';
        case '.':
            word[j] = ' ';
      }
      // Do not print empty word
      if (word[j] != ' ') {
        printf("%c", word[j]);
      }
    }

    printf("#");

    word_count += 1;
    if (word_count==12) {
      printf("\n");
      word_count = 0;
    }
    
    // Jump to here if the char is '-'
    Skip:

    for (i=0; i<strlen(word); i++) // Check every character is word.
    // If it is a vowel.
    if (word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' ||word[i]=='U' ||
    word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
    vowel_count = vowel_count + 1; // Increment the vowel count.

  }

  if (word_count!=0) printf("\n"); // The current line is not finished. Output a newline.
  // Print a newline before the line contents. That is, print an empty line.
  printf("\nTotal %d vowels.\n", vowel_count); // Output the total number of vowels.

  return 0;
}
