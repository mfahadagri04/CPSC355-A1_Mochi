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
    if (argc != 2) {
        printf("Please enter size of Forest Grid (N)");
        return 0;
    }

    int N = atoi(argv[1]);
    int forest[N][N];

    initGrid(N,forest);

    printf("<======= Mochi the Panda =======>\n");

    printf("Generated Forest Grid:\n");
    printGrid(N,forest);

    return 0;
}
