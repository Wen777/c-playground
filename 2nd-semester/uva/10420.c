// One-star problem
// Problem 10420 List of Conquests
/*
This program is written by
    Prof. Chua-Huang Huang
        Department of Information Engineering and Computer Science
        Feng Chia University
        Taichung, Taiwan
Disclaimer:
    The programming problem is downloaded from UVa Online Judge
(https://uva.onlinejudge.org/).
    The program solution is provided for helping students to prepare Collegiate
Programming
        Examination	(CPE). The author does not guarantee the program is
completely correct to pass
        UVa Online Judge platform or CPE examination platform.
        This program is not intended for a student to copy only. He/She should
practice the
        programming problem himself/herself. Only use the program solution as a
reference.

        The author is not responsible if the program causes any damage of your
computer or
        personal properties.
        No commercial use of this program is allowed without the author's
written permission.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Attribute name is a char pointer to store a string in dynamic memory.
// Attribue women is the number of womem from that country.
typedef struct {
  char *name;
  int women;
  Country *next;
} Country;

typedef struct {
  Country *head;
  int length;
} Countries;

// We assume no woman's name appears twice or more times in a country. If two
// countries
// with the same woman's name, they are different persons. That is, no woman is
// repeated
// in the list.
int main(void) {
  int line;               // Number of lines in the list.
  char country_name[76];  // Country name, assume maximum 75 characters.
  char *str_ptr;
  int num_countries = 0;  // Number of countries.
  int max_countries =
      100;  // Max number of countries; increase 100 when the limit is reached.
  int found;    // To indicate whether a country name is found or not.
  char c;       // Character to drain the woman's name until newline is read.
  int i, j, k;  // Loop variables.

  Countries coun;
  coun.length = 0;
  Country *tempNode;

  scanf("%d", &line);  // Number of lines in the input data.
  for (i = 0; i < line; i++) {
    scanf("%s", country_name);  // Input a country name.
    str_ptr =
        (char *)malloc(strlen(country_name) +
                       1);  // Allocate dynamic memory for this country name.
    strcpy(str_ptr, country_name);

    found = 0;  // Assume the country is not found.
    for (j = 0; j < coun.length && !found;
         j++) {  // The country is sorted in ascending order.
      if (strcmp(countries[j].name, str_ptr) == 0) {  // The country is found.

      // add number
        countries[j].women++;
        found = 1;  // Set found to true.
      } else if (strcmp(countries[j].name, str_ptr) > 0)
        break;  // The country is not found.
    }
    if (!found) {  // Insert this country in the j-th entry.
      if (num_countries ==
          max_countries) {     // The country limit is reached, extend the list.
        max_countries += 100;  // To hole 100 more countreis.
        countries = (Country *)realloc(
            countries,
            max_countries *
                sizeof(Country));  // Request memory for the extended list.
      }
      for (k = num_countries - 1; k >= j;
           k--) {  // Move the countries from entry j one place up.
        countries[k + 1].name = countries[k].name;    // Copy a pointer.
        countries[k + 1].women = countries[k].women;  // Copy an integer value.
      }
      countries[j].name = (char *)malloc((strlen(str_ptr) + 1) * sizeof(char));
      strcpy(countries[j].name,
             str_ptr);  // Add the new country name to the list.
      countries[j].women = 1;
      num_countries++;
    }
    scanf("%c", &c);  // Get a character from the input data.
    while (c != 0X0A && !feof(stdin))
      scanf("%c", &c);  // Drain the woman's name until newline is reached.
  }
  for (i = 0; i < num_countries; i++) {
    printf("%s, %d\n", countries[i].name,
           countries[i].women);  // Output the result.
    free(countries[i].name);     // Release memory for country name.
  }
  free(countries);  // Release memory for countries.
  return 0;
}