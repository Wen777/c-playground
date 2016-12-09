#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    // code book.
    char code_book[26] = {'N', 'E', 'I', 'Q', 'O', 'Y', 'A', 'R', 'D',
    'C', 'S', 'H', 'X', 'Z', 'B', 'P', 'J', 'T', 'K', 'U', 'F', 'L', 'V',
    'G', 'W', 'M'};

    // Declare variable
    char decode_book[26];
    char original_text[10001];
    char encoded_text[10001];
    char decoded_text[10001];
    int i, j;

    i = 0;
    do {
        original_text[i++] = getchar();
    } while(!feof(stdin));
    original_text[i] = '\0';

    printf(">>>> The input original text:\n\n%s\n\n", original_text);

    printf("--------------------------------------------\n");

    j = 0;
    for (i=0; i < strlen(original_text);i++) {
        if (isalpha(original_text[i])) {
            encoded_text[j++]  = code_book[toupper(original_text[i]) - 'A'];
        }
    }

    encoded_text[j]  = '\0';

    printf(">>>>>> The encoded text:\n\n%s\n\n", encoded_text);
    printf("------------------------------------\n");

    for (i=0; i < 26; i++) {
        decode_book[code_book[i] - 'A'] = i + 'A';
    }
     for (i=0; i < 26; i++) {
        printf("%c ", decode_book[i]);
    }

    for (i=0; i < strlen(encoded_text); i++) {
        decoded_text[i] = decode_book[encoded_text[i] - 'A'];
    }

    decoded_text[i] = '\0';

    printf(">>>> The decoded text:\n\n%s\n\n", decoded_text);

    printf("-----------------------------");

    return 0;
}
