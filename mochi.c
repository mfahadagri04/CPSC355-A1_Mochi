/*
    CPSC 355 Assignment 1 - Hungry Mochi
    Full Name: Muhammad Fahad
    UCID: 30177705
    LEC: LEC01
    TUT: T02
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// -------------- Functions ----------------------

// Create a grid Nrow x Ncol where N is taken from cla
// Populate the grid with random integers from 0 to 9
void initGrid(int N, int forest[N][N]) {
    srand(time(NULL));

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            forest[row][col] = rand() % 10; // Random integer from 0 to 9
        }
    }
}

// Print the grid to the console
void printGrid(int N, int forest[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", forest[row][col]);
        }
        printf("\n");
    }
}

// -------------- Main ----------------------

int main(int argc, char *argv[]) {
    // check CLA
    if (argc != 2) {
        fprintf(stderr, "Error: Please provide the size of the forest grid (N).\n");
        fprintf(stderr, "Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int forest[N][N];

    initGrid(N,forest);

    printf("<==================== Mochi the Panda ====================>\n");
    printf("\nMochi is hungry....\n");
    printf("\nForest Grid:\n");
    printGrid(N,forest);

    while (1) {
        int bambooType;
        printf("\nWhich bamboo type does Mochi want to eat? (0-9): ");
        scanf("%d",&bambooType);

        if (bambooType >= 0 && bambooType <= 9) {
            printf("Within the range.\n");
            break;
        } else {
            printf("Has to be within 0-9!\n");
        }
    }
    
    return 0;
}
