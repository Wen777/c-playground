#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char stringMatrix[100][100];
  char character;
  int maxStrLen = 0, maxLine = 0;
  int line = 0, i = 0, j, k;
  // Read data by character
  while ((character = getchar()) != EOF) {
      // only save valid characters and numbers (includes space and punctuation)
    if (isalnum(character) || character == ' ' || ispunct(character)) {
      stringMatrix[line][i++] = character;
      continue;
    }
    if (character == '\n') {
      stringMatrix[line][i] = '\0';
      // find the maximum string.
      if (strlen(stringMatrix[line]) > maxStrLen) {
        maxStrLen = strlen(stringMatrix[line]);
        maxLine = line;
      }
      line++;
      i = 0;
    }
  }
      stringMatrix[line][i] = '\0';
      // find the maximum string.
      if (strlen(stringMatrix[line]) > maxStrLen) {
        maxStrLen = strlen(stringMatrix[line]);
        maxLine = line;
      }

  for (k = 0; k < maxStrLen; k++) {
    j = line;
    for (; j >= 0; j--) {
      if (strlen(stringMatrix[j]) > k && stringMatrix[j][k] != '\n' && stringMatrix[j][k] != '\0') {
        // print string by character
        printf("%c", stringMatrix[j][k]);
      } else {
        if (j > maxLine) {
          // reach the end of that string. Print space character.
          printf(" ");
        }
      }
    }
    printf("\n");
  }
  return 0;
};
