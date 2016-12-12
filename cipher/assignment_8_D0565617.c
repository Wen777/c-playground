#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
  char keyword[41]; // The keyword.
  int key_leng; // The length of the keyword.
  char original_text[10001]; // The original input text.
  char encoded_text[10001]; // Encoded text.
  char decoded_text[10001]; // Decoded text.
  int i, j, z;
  char encode_book[26] = {'N', 'E', 'I', 'Q', 'O', 'Y', 'A', 'R', 'D',
    'C', 'S', 'H', 'X', 'Z', 'B', 'P', 'J', 'T', 'K', 'U', 'F', 'L', 'V',
    'G', 'W', 'M'};
  char decode_book[26];

  scanf("%s", keyword); // Input the keyword;
  key_leng = strlen(keyword); // Length of the keyword.
  do {
    original_text[0] = getchar(); // Input a character from the console.
  } while (!isalpha(original_text[0])); // Continue until reaching the first letter.

  i = 1; // Inintial loop varible i to 1.
  do {
    original_text[i++] = getchar(); // Input a character from the console.
  } while (!feof(stdin)); // Stop until the end of file.
  original_text[i] = '\0'; // Insert end-of-string.

  printf("**** The keyword is: %s\n\n", keyword); // Ouput the keyword.
  printf(">>>> The input original text:\n\n%s\n\n", original_text); // Output the original text.
  printf("-------------------------------------------------------------------------\n");

  j = 0; // Initail the index of the encoded text to 0.
  for (i=0; i<strlen(original_text); i++) {
    if (isalpha(original_text[i])) {
      z = 0;
      while (encode_book[z] - keyword[j % key_leng] != 0) {
        z++;
      }
      encoded_text[j] = encode_book[(z + toupper(original_text[i]) - 'A') % 26 ];
      j++;
    }
  }
  encoded_text[j] = '\0'; // Insert end-of-string.

  printf(">>>> The encoded text:\n\n%s\n\n", encoded_text); // Output the encoded text.
  printf("-------------------------------------------------------------------------\n");

  // Generate decode book.
  for (i=0; i<sizeof(decode_book);i++ ) {
    decode_book[encode_book[i] - 'A'] = i + 'A' ;
  }

  for (i=0; i<strlen(encoded_text); i++) {
    z = 0;
    while (encode_book[z] - keyword[i % key_leng] != 0) {
      z++;
    }
    j = 0;
    while (encoded_text[i] - encode_book[j] != 0) {
      j++;
    }
    // According to the [Vigenère_cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher), we know the
    // Algebraic description of Vigenère cipher.
    //
    // For Vigenere cipher
    // Encoding:
    // P = V + C
    // V is encode book / rule. C is the original character / data.
    // P is encoded character.
    //
    // Decoding:
    // C = P - V
    decoded_text[i] = decode_book[encode_book[(j - z + 26 ) % 26] - 'A'];
  }
  encoded_text[i] = '\0'; // Insert end-of-string.

  printf(">>>> The decoded text:\n\n%s\n\n", decoded_text); // Output the encoded text.
  printf("-------------------------------------------------------------------------\n");

  return 0;
}
