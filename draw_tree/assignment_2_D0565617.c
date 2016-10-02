#include <stdio.h>

void printChar(int times, char word) {
    int i = 0;
    for (i = 0; i <times; ++i) {
        printf("%c", word);
    }
}

// "layer", "side", "growth", "width", and "height"
int main(void) {
    int layer = 0, side = 0, growth = 0, width = 0, height = 0, space = 26;
    int i = 0, j = 0, k = 0;

    printf(" test %d %d %d \n", layer, side, growth);
    do {
        if (layer > 5 || layer < 2) {
            printf("\nlayer is ? 2-5 : ");
            scanf("%d", &layer);
        }

        if (side > 5 || side < 3) {
            printf("\nside is ? 3-5 : ");
            scanf("%d", &side);
        }

        if (growth < 1 || growth > 5) {
            printf("\ngrowth is ? 1-5 : ");
            scanf("%d", &growth);
        }

        if (width > 9 || width < 3 || width % 2 == 0) {
            printf("\ntrunk width is ? 3-9 : ");
            scanf("%d", &width);
        }

        if (height > 10 || height < 4) {
            printf("\ntrunk height is ? 4-10 : ");
            scanf("%d", &height);
        }

    } while( (layer > 5 || layer <2)   || (side > 5 || side < 3) || 
           (growth < 1 || growth > 5) || (width > 9 || width < 3 || width % 2 == 0 ) ||
           (height > 10 || height < 4));
    
    // Top char of tree.
    printChar(space, ' ');
    printf("#\n");

    for (i = 0; i < layer; ++i) {
        for (j = 0; j < (side - 1) + i * growth; ++j) {
            printChar(space - j - 1, ' ');
            printf("#");
            // character '@' for the interior points of the triangles.
            if (j + 1 == (side - 1) + i * growth) {
                printChar(2 *j + 1, '#');
            } else {
                printChar(2 *j + 1, '@');
            }
            printf("#\n");
        }
    }
    // Trunk
    for (k = 0; k  < height ; ++k ) {
        printChar(space - (width - 1) / 2, ' ');
        printChar(width, '|');
        printf("\n");
    }
    return 0;
}

