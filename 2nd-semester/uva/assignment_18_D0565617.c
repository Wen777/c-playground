#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>

int main(void) {
    // Variable declaration.
    int brown_1 = 0, brown_2 = 0, brown_3 = 0;
    int to_brown_1 = 0, to_brown_2 = 0, to_brown_3 =0;
    int green_1 = 0, green_2 = 0, green_3 = 0;
    int to_green_1 = 0, to_green_2 = 0, to_green_3 = 0;
    int clear_1 = 0, clear_2 = 0, clear_3 = 0;
    int to_clear_1 = 0, to_clear_2 = 0, to_clear_3 = 0;
    // Variable to store string, ex: "BGC"
    char ans[4];
    int ans_num = 0, recent = 0, min = 0;

    // Get data from standard input
    while(scanf("%d %d %d %d %d %d %d %d %d ",
    &brown_1, &green_1, &clear_1,
    &brown_2, &green_2, &clear_2,
    &brown_3, &green_3, &clear_3) == 9) {
        min = pow(2, 16) - 1; 

        // count the smallest moves for each case
        to_brown_1 = brown_2 + brown_3;
        to_brown_2 = brown_1 + brown_3;
        to_brown_3 = brown_1 + brown_2;

        to_green_1 = green_2 + green_3;
        to_green_2 = green_1 + green_3;
        to_green_3 = green_1 + green_2;

        to_clear_1 = clear_2 + clear_3;
        to_clear_2 = clear_1 + clear_3;
        to_clear_3 = clear_1 + clear_2;

        // Use brute-force to find the smallest moves among six cases

        // BCG
        recent = to_brown_1 + to_clear_2 + to_green_3;
        if (min > recent) {
            min = recent;
            strcpy(ans, "BCG");
        }
        // BGC
        recent = to_brown_1 + to_green_2 + to_clear_3;
        if (min > recent) {
            min = recent;
            strcpy(ans, "BGC");
        }
        // GBC
        recent = to_green_1 + to_brown_2 + to_clear_3;
        if (min > recent) {
            min = recent;
            strcpy(ans, "GBC");
        }
        // GCB
        recent = to_green_1 + to_clear_2 + to_brown_3;
        if (min > recent) {
            min = recent;
            strcpy(ans, "GCB");
        }
        // CBG
        recent = to_clear_1 + to_brown_2 + to_green_3;
        if (min > recent) {
            min = recent;
            strcpy(ans, "CBG");
        }
        // CGB
        recent = to_clear_1 + to_green_2 + to_brown_3;
        if (min > recent) {
            min = recent;
            strcpy(ans, "CGB");
        }

        printf("%s %d\n", ans, min);
    }
}