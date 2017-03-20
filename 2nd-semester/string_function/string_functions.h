// Computing the length of a string, recursive function 
size_t my_strlen_rec(const char *);

// Computing the lenght of a string, iterative function
size_t my_strlen_ite(const char *);

// Comparing two strings "lexical graphically" order, iterative function.
int strcmp_ite(const char *, const char *);

// Comparing two strings "lexical graphically" order, recursive function.
int strcmp_rec(const char *, const char *);

// Copy the second string to the first string and return the starting
// address of the first string.
char *strcpy_ite(char *, const char *);

// String pointr break Finds the first character in string str1 that matches
// any character specified in str2. Iterative version
size_t strspn_ite(const char *, const char *);

// Substring matching. Finds the first occurence of the entire string str2
// which appears in the string str1.
char *strstr_ite(const char *, const char *);

