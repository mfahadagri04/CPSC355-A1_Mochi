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

// Function to search for a single bamboo type in the grid
void searchBamboo1(int N, int forest[N][N], int bambooType) {
    int bambooCounter = 0;
    int coordinates[N*N][2]; // To store coordinates of eaten bamboo
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (forest[row][col] == bambooType) {
                coordinates[bambooCounter][0] = row;
                coordinates[bambooCounter][1] = col;
                bambooCounter++;
            }
        }
    }

    // If no bamboo found :(
    if (bambooCounter == 0) {
        printf("Oh no! Mochi couldn’t find any bamboo type %d.\n", bambooType);
    } else {
        printf("Mochi has eaten %d pieces of bamboo type %d.\n", bambooCounter, bambooType);
        printf("Coordinates of eaten bamboo:\n");
        for (int i = 0; i < bambooCounter; i++) {
            printf("(%d, %d)\n", coordinates[i][0], coordinates[i][1]);
        }
    }
}

// Function to search for two bamboo types in the grid
void searchBamboo2(int N, int forest[N][N], int bambooType1, int bambooType2) {
    // Implementation goes here
}

// Calculate and print the percentage of the grid that has been eaten
void calculatePercentageEaten(int N, int totalCellsEaten) {
    return (totalCellsEaten / (N * N)) * 100.0;
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

    // Ask user how many bamboo types does mochi want
    int choice;
    while (1) {
        printf("\nHow many bamboo types does Mochi want to eat, 1 or 2? ");
        scanf("%d",&choice);

        if (choice == 1 || choice == 2) {
            break;
        } else {
            printf("\nPlease enter either 1 or 2\n");
        }
    }
    
    // Switch case for 1 or 2 bamboo types
    int bambooType1;
    int bambooType2;
    switch (choice) {
        case 1:
            while (1) {
            printf("\nWhich bamboo type does Mochi want to eat? (0-9): ");
            scanf("%d",&bambooType1);

            if (bambooType1 >= 0 && bambooType1 <= 9) {
                searchBamboo1(N, forest, bambooType1);
                break;
            } else {
                printf("Has to be within 0-9!\n");
            }
            }
            break;

        case 2:
            while (1) {
                printf("\nWhich bamboo type (1) does Mochi want to eat? (0-9): ");
                scanf("%d", &bambooType1);

                if (bambooType1 < 0 || bambooType1 > 9) {
                    printf("First bamboo type has to be within 0-9!\n");
                    continue; 
                }

                printf("Which bamboo type (2) does Mochi want to eat? (0-9): ");
                scanf("%d", &bambooType2);

                if (bambooType2 < 0 || bambooType2 > 9) {
                    printf("Second bamboo type has to be within 0-9!\n");
                    continue; 
                }

                if (bambooType1 == bambooType2) {
                    printf("Bamboo types must be different!\n");
                    continue; 
                }

                printf("Within the range: %d and %d.\n", bambooType1, bambooType2);
                break;
            }

        default:
            break;
        }

    return 0;
}
