#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// banglaNumber function to print bangla number
// a recursive function
void banglaNumber(char *string) {
  // find string length
  unsigned len = strlen(string);
  int i;
  // flag to avoid duplication of kuti value.
  unsigned flag = 1;
  // variables to store value
  unsigned kutiNum, lakhNum, hajarNum, shataNum, constNum;
  kutiNum = 0;
  lakhNum = 0;
  hajarNum = 0;
  shataNum = 0;
  constNum = 0;

  // if value of length of string is bigger than 9, split it
  if (len > 9) {

    char *tempString;
    tempString = (char *)malloc(sizeof(char) * (len - 7 + 1));
    strncpy(tempString, string, len - 7);
    tempString[len - 7] = '\0';

    banglaNumber(tempString);
    printf("kuti ");
    flag = 0;
  }

  // convert char into integer 
  for (i = 0; i < len; i++) {
    switch (len - i) {
      case 1:
        constNum += string[i] - '0';
        break;
      case 2:
        constNum += (string[i] - '0') * 10;
        break;
      case 3:
        shataNum += string[i] - '0';
        break;
      case 4:
        hajarNum += string[i] - '0';
        break;
      case 5:
        hajarNum += (string[i] - '0') * 10;
        break;
      case 6:
        lakhNum += string[i] - '0';
        break;
      case 7:
        lakhNum += (string[i] - '0') * 10;
        break;
      case 8:
        kutiNum += string[i] - '0';
        break;
      case 9:
        kutiNum += (string[i] - '0') * 10;
        break;
      default:
        break;
    }
  }

  // print result
  if (kutiNum != 0 && flag != 0) {
    printf("%d kuti ", kutiNum);
  }

  if (lakhNum != 0) {
    printf("%d lakh ", lakhNum);
  }

  if (hajarNum != 0) {
    printf("%d hajar ", hajarNum);
  }

  if (shataNum != 0) {
    printf("%d shata ", shataNum);
  }

  if (constNum != 0) {
    printf("%d ", constNum);
  }
}

int main(void) {
  char input[20];
  int count;
  count = 1;

  while (scanf("%s", input) != EOF) {
    printf("%3d. ", count++);
    banglaNumber(input);
    printf("\n");
  }

  return 0;
}