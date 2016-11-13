#include<stdio.h>
#include<math.h>
#include<ctype.h>

// for loop scanf
// if both input are 0, break
// hexamal to decimal
// condition  decimal - F000 0000 0000 0000 > 0, cary flag
// false: printf("%llX")

void printChar(int loop, char character) {
    int i = 0;
    for(; i < loop; i++) {
        printf("%c", character);
    }
}
int main(void) {
    unsigned long long input_1 = 0, input_2 = 0;
    while(1) {
        scanf("%llX %llX", &input_1, &input_2);
        if (input_1 == 0 && input_2 == 0) {
            break;
        }
        
        printf("  %16llX\n", input_1);
        printf("+ %16llX\n", input_2);
        printChar(18, '-');
        printf("\n");
        printf("  %16llX\n", input_1 + input_2);
        long long flag = 0xFFFFFFFFFFFFFFFF - input_1;
        printf("flag %lld\n", flag);
        if(  flag <  input_2 ) {
            printf("%llu + %llu = %llu ***Overflow!!!\n\n", input_1 , input_2, input_1 + input_2);

        } else {
            printf("%llu + %llu = %llu\n\n", input_1 , input_2, input_1 + input_2);
        }

    }
    return 0;
}
