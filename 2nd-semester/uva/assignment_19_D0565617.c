#include<string.h>
#include<stdio.h>
// D0565617 施文祥

int cost[36];

void cheapestBase(int n) {
    // variable declaration
    int number, base, total[36];
    int cheapest = 2000000001;
    for (base = 2; base <= 36; base++) {
        number = n;
        total[base - 2] = 0;
        while(number > 0) {
           // use remainder to find the correspondent cost
           total[base - 2] += cost[ number % base ];
           number /= base;
        }
        // update the cheapest base
        if (cheapest > total[base - 2]) {
            cheapest = total[base - 2];
        }
    }
    // show the cheapest base
    for (base = 2; base < 37; base ++) {
        if (cheapest == total[base - 2]) {
            printf(" %d", base );
        }
    }
    printf("\n");
}
int main(void) {
    // show the value of loops
    int loop, _loop;
    int i,j;
    int testCase;
    int n;
    scanf("%d", &loop);
    _loop = loop;

    while(1) {
        loop--;
        // Code
        // cost of each base
        for(i = 0; i < 36; i++) {
            scanf("%d", &cost[i]);
        }


        scanf("%d", &testCase);
        printf("Case %d:\n", _loop - loop);

        for(i = 1; i <= testCase; i++) {
            scanf("%d", &n);
            printf("Cheapest base(s) for number %d:", n);
            // call cheapestBase function
            cheapestBase(n);
        }

        // termination
        if (loop == 0) {
            break;
        }
        printf("\n");
    }
    return 0;
}

