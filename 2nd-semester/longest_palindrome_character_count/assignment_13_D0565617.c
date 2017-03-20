#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Palindrome check function, iterative version.
int is_palindrome(char *s) {
  unsigned int h = 0; // Head pointer of string s.
  unsigned int t = strlen(s) - 1; // Tail pointer of string s.

  // Scan the string from head and tail toward the center, if a pair corresponding
  // characters are not identical, return flase (0).
  // The loop continues when head pointer is on the left-hand-side of the tail pointer.
  while (h<t) if (s[h++]!=s[t--]) return 0;
  return 1; // If the entire string passes the check, s is a palindrome.
}

// (1) Read data from a text file named <file_name>.
// (2) Store the data in a buffer pointed by <buffer_ptr>.
// (3) Return the memory address of the data buffer.
char *read_text_file(char *file_name) {
  FILE *fPtr; // File pointer.
  char * buffer_ptr; // Pointer to the data buffer.
  unsigned int size; // Size of the text file.

  fPtr = fopen(file_name, "r"); // Open file <file_name> with read mode.
  fseek(fPtr, 0, SEEK_END); // Move the file pointer to the end of the file.
  size = ftell(fPtr); // Get the position of the file, i.e., the size of the file.
  fseek(fPtr, 0, SEEK_SET); // Move the file pointer to the beginning of the file.
  buffer_ptr = (char *) malloc((size + 1) * sizeof(char)); // Allocate buffer memory.
  fread(buffer_ptr, 1, size, fPtr); // Read data from the input file and store in the data buffer.
  fclose(fPtr); // Close the input file.
  buffer_ptr[size] = '\0'; // Insert the end-of-string after the end of the text data.
  return buffer_ptr; // Return the memory address of the data buffer.
}

// Write text data pointed by <buffer_ptr> to a file named <file_name>.
// Free memory space of the data buffer.
void write_text_file(char *file_name, char *buffer_ptr) {
  FILE *fPtr; // File pointer.

  fPtr = fopen(file_name, "w");  // Open file <file_name> with write mode.
  fwrite(buffer_ptr, 1, strlen(buffer_ptr), fPtr); // Write data from the data buffer to the output file.
  fclose(fPtr); // Close the output file.
  free(buffer_ptr); // Release the memory space of the data buffer.	
}

struct word_counter {
    unsigned int one;
    unsigned int two;
    unsigned int three;
    unsigned int four;
    unsigned int five;
    unsigned int six;
    unsigned int extra;
};

void print_word_counter(struct word_counter counter) {
    printf("Length %d: %d\n", 1, counter.one);
    printf("Length %d: %d\n", 2, counter.two);
    printf("Length %d: %d\n", 3, counter.three);
    printf("Length %d: %d\n", 4, counter.four);
    printf("Length %d: %d\n", 5, counter.five);
    printf("Length %d: %d\n", 6, counter.six);
    printf("Length greater than %d: %d\n", 6, counter.extra);
}

void init_word_counter(struct word_counter *counter) {
    counter->one = 0;
    counter->two = 0;
    counter->three = 0;
    counter->four = 0;
    counter->five = 0;
    counter->six = 0;
    counter->extra = 0;
}

void increase_word_counter(struct word_counter *c_counter, unsigned int word_len) {
    switch (word_len) {
        case 0:
            break;
        case 1:
            c_counter->one ++;
            break;
        case 2:
            c_counter->two ++;
            break;
        case 3:
            c_counter->three ++;
            break;
        case 4:
            c_counter->four ++;
            break;
        default:
            c_counter->four ++;
    }
}

struct contiguous_word_counter {
    unsigned int zero;
    unsigned int one;
    unsigned int two;
    unsigned int three;
};

void print_contiguous_word_counter(struct contiguous_word_counter c_counter) {
    printf("One character: %d\n", c_counter.zero);
    printf("Two contiguous character: %d\n", c_counter.one);
    printf("Three contiguous character: %d\n", c_counter.two);
    printf("Four or more contiguous character: %d\n", c_counter.three);
}

void init_contiguous_word_counter(struct contiguous_word_counter *c_counter) {
    c_counter->zero = 0;
    c_counter->one = 0;
    c_counter->two = 0;
    c_counter->three = 0;
}
void increase_contiguous_word_counter(struct contiguous_word_counter *c_counter, unsigned int word_len) {
    switch (word_len) {
        case 0:
            c_counter->zero ++;
            break;
        case 1:
            c_counter->one ++;
            break;
        case 2:
            c_counter->two ++;
            break;
        case 3:
            c_counter->three ++;
            break;
        default:
            c_counter->three ++;
            break;
    }
}

struct vowel_word_counter {
    unsigned int a;
    unsigned int e;
    unsigned int i;
    unsigned int o;
    unsigned int u;
};

void print_vowel_word_counter(struct vowel_word_counter v_counter) {
    printf("Vowel 'A': %d\n", v_counter.a);
    printf("Vowel 'E': %d\n", v_counter.e);
    printf("Vowel 'I': %d\n", v_counter.i);
    printf("Vowel 'O': %d\n", v_counter.o);
    printf("Vowel 'U': %d\n", v_counter.u);
}

void init_vowel_word_counter(struct vowel_word_counter *v_counter) {
    v_counter->a = 0;
    v_counter->e = 0;
    v_counter->i = 0;
    v_counter->o = 0;
    v_counter->u = 0;
}
void increase_vowel_word_counter(struct vowel_word_counter *v_counter, char v_word) {
    switch (v_word) {
        case 'A':
            v_counter->a ++;
            break;
        case 'E':
            v_counter->e ++;
            break;
        case 'I':
            v_counter->i ++;
            break;
        case 'O':
            v_counter->o ++;
            break;
        case 'U':
            v_counter->u ++;
            break;
        default:
            break;
    }
}


int main(void) {
  char *data_ptr; // Data buffer pointer. 
  unsigned int inx = 0; // Index of the modified text.
  unsigned int i; // Loop variable.
  unsigned int word_len, c_word_len;

  struct word_counter counter;
  init_word_counter(&counter);

  struct contiguous_word_counter c_counter;
  init_contiguous_word_counter(&c_counter);

  struct vowel_word_counter v_counter;
  init_vowel_word_counter(&v_counter);

  // Read data from file "longest_palindrome_in.txt" and store in the da
  data_ptr = read_text_file("longest_palindrome_in.txt");

  // Scan the entire data buffer.
  for (i=0, word_len = 0, c_word_len = 0; i<strlen(data_ptr); i++) {
    // If the character is an English letter, convert to the uppercase letter and
    // store it in the modified text;
    // otherwise, ignore the character, i.e., remove non-English letters.
    if (isalpha(data_ptr[i])) {
        data_ptr[inx++] = toupper(data_ptr[i]);
        if(i > 0 && data_ptr[inx - 1] == data_ptr[inx - 2]) {
            c_word_len++;
        } else {
            increase_contiguous_word_counter(&c_counter, c_word_len);
            c_word_len = 0;
        }
        increase_vowel_word_counter(&v_counter, data_ptr[inx - 1]);
        word_len ++;
    } else {
        increase_word_counter(&counter, word_len);
        word_len = 0;
    }
  }

  data_ptr[inx] = '\0'; // Insert the end-of-string after the end of the modified text.

  printf(">>>> The testing text is read from file longest_palindrome_in.txt.\n");
  printf("************************************************************************\n");
  // (3) Count and report the number of words with length 1 to 6 and over 6 and print the length of the modified text.
  // Note that a word is a sequence of English letters separated by a non-English character such as space,
  // punctuation symbol, and newline.
  print_word_counter(counter);
  printf("Total character count %d .\n\n", inx);
  printf("************************************************************************\n");

  printf("The first 500 characters are:\n  "); // Print the first 500 characters.
  for (i=0; i<500; i++) { // 800 characters in a line.
  	if ((i+1)%80==0)  printf("%c\n  ", data_ptr[i]); // If it is not a full line, print the character only.
  	else printf("%c", data_ptr[i]); // If it is a full line, print the character and a new line.
  }
  printf("\n\n");
  printf("************************************************************************\n");

  printf(">>>> The number of contiguous letter(s) are :\n");
  print_contiguous_word_counter(c_counter);
  printf("Total character count %d .\n\n", inx);
  printf("************************************************************************\n");

  printf(">>>> The number of occurrences of vowels :\n");
  print_vowel_word_counter(v_counter);
  printf("Total vowel count %d .\n\n", v_counter.a + v_counter.e + v_counter.i + v_counter.o + v_counter.u);
  printf("************************************************************************\n");

  if (is_palindrome(data_ptr)) printf("Yes, it is a palindrome.\n"); // Yes, a palindrome.    
  else printf("No, it is not a palindrome.\n"); // No, not a palindrome.
  printf("************************************************************************\n");

  write_text_file("longest_palindrome_out.txt", data_ptr); // Write the data in buffer to the output file.

  printf(">>>> The modified text is written to file longest_palindrome_out.txt.\n");
  printf("************************************************************************\n");
  return 0;
}
