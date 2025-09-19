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
#include <stdbool.h>

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
int searchBamboo1(int N, int forest[N][N], int bambooType) {
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
        printf("Oh no! Mochi could not find any bamboo type %d.\n", bambooType);
    } else {
        printf("Mochi has eaten %d pieces of bamboo type %d.\n", bambooCounter, bambooType);
        printf("Coordinates of eaten bamboo:\n");
        for (int i = 0; i < bambooCounter; i++) {
            printf("(%d, %d)\n", coordinates[i][0], coordinates[i][1]);
        }
    }

    return bambooCounter;
}

// Search for two bamboo types
int searchBamboo2(int N, int forest[N][N], int bambooType1, int bambooType2) {
    int bambooType1Counter = 0;
    int bambooType2Counter = 0;
    int totalBambooCounter = 0;
    int coordinates[N * N][2];

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (forest[row][col] == bambooType1) {
                coordinates[totalBambooCounter][0] = row;
                coordinates[totalBambooCounter][1] = col;
                bambooType1Counter++;
                totalBambooCounter++;
            } 
            else if (forest[row][col] == bambooType2) { // 👈 avoid double count
                coordinates[totalBambooCounter][0] = row;
                coordinates[totalBambooCounter][1] = col;
                bambooType2Counter++;
                totalBambooCounter++;
            }
        }
    }

    if (bambooType1Counter == 0) {
        printf("Oh no! Mochi could not find bamboo type %d.\n", bambooType1);
    } else {
        printf("Mochi has eaten %d pieces of bamboo type %d.\n", bambooType1Counter, bambooType1);
    }

    if (bambooType2Counter == 0) {
        printf("Oh no! Mochi could not find bamboo type %d.\n", bambooType2);
    } else {
        printf("Mochi has eaten %d pieces of bamboo type %d.\n", bambooType2Counter, bambooType2);
    }

    printf("Mochi has eaten a total of %d pieces of bamboo.\n", totalBambooCounter);

    if (totalBambooCounter > 0) {
        printf("Coordinates of eaten bamboo:\n");
        for (int i = 0; i < totalBambooCounter; i++) {
            printf("(%d, %d)\n", coordinates[i][0], coordinates[i][1]);
        }
    }

    return totalBambooCounter;  
}


// Calculate and print the percentage of the grid that has been eaten
void calculatePercentageEaten(int N, int totalCellsEaten) {
    double percentageEaten = (totalCellsEaten / (double) (N * N)) * 100.0;
    printf("Mochi has eaten %.2f%% of the forest.\n", percentageEaten);
}

// Chosen bamboo type(s) tracker
bool isChosen(int chosen[], int chosenCount, int type) {
    for (int i = 0; i < chosenCount; i++) {
        if (chosen[i] == type) return true;
    }
    return false;
}

// -------------- Main ----------------------

int main(int argc, char *argv[]) {
    // check CLA
    if (argc != 2) {
        printf("Usage: %s <grid_size>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("Grid size must be positive!\n");
        return 1;
    }

    int forest[N][N];
    initGrid(N,forest);

    printf("<==================== Mochi the Panda ====================>\n");
    printf("\nMochi is hungry....\n");
    printf("\nForest Grid:\n");
    printGrid(N,forest);


    int eatingCounter = 0;
    int chosenTypes[10]; // To track chosen bamboo types
    int chosenCounter = 0;
    int totalBambooEaten = 0;

    while (eatingCounter < 2) {
        // Ask user how many bamboo types does mochi want
        int choice;
        while (1) {
            printf("\nHow many bamboo types does Mochi want to eat, 1 or 2? (q to quit): ");
            char input[10];
            scanf("%s", input);

            if (input[0] == 'q' || input[0] == 'Q') {
                printf("Exiting program...\n");
                return 0;
            }

            choice = atoi(input);
            if (choice == 1 || choice == 2) break;

            printf("Please enter either 1 or 2\n");
        }
        
        // Switch case for 1 or 2 bamboo types
        int bambooType1, bambooType2;
        switch (choice) {
            case 1:
                while (1) {
                    printf("Which bamboo type does Mochi want to eat? (0-9, q to quit): ");
                    char input[10];
                    scanf("%s", input);

                    if (input[0] == 'q' || input[0] == 'Q') {
                        printf("Exiting program...\n");
                        return 0;
                    }

                    bambooType1 = atoi(input);

                    if (bambooType1 < 0 || bambooType1 > 9) {
                        printf("Has to be within 0-9!\n");
                        continue;
                    }
                    if (isChosen(chosenTypes, chosenCounter, bambooType1)) {
                        printf("This bamboo type was already chosen!\n");
                        continue;
                    }

                    int eaten = searchBamboo1(N, forest, bambooType1);
                    totalBambooEaten += eaten;
                    calculatePercentageEaten(N, eaten);

                    chosenTypes[chosenCounter++] = bambooType1;
                    eatingCounter++;
                    break;
                }
                break;

            case 2:
                while (1) {
                    printf("Which bamboo type (1) does Mochi want to eat? (0-9, q to quit): ");
                    char input[10];
                    scanf("%s", input);

                    if (tolower(input[0]) == 'q') {
                        printf("Exiting program...\n");
                        return 0;
                    }
                    bambooType1 = atoi(input);

                    if (bambooType1 < 0 || bambooType1 > 9) {
                        printf("First bamboo type has to be within 0-9!\n");
                        continue;
                    }
                    if (isChosen(chosenTypes, chosenCounter, bambooType1)) {
                        printf("This bamboo type was already chosen!\n");
                        continue;
                    }

                    printf("Which bamboo type (2) does Mochi want to eat? (0-9, q to quit): ");
                    scanf("%s", input);

                    if (input[0] == 'q' || input[0] == 'Q') {
                        printf("Exiting program...\n");
                        return 0;
                    }
                    bambooType2 = atoi(input);

                    if (bambooType2 < 0 || bambooType2 > 9) {
                        printf("Second bamboo type has to be within 0-9!\n");
                        continue;
                    }
                    if (bambooType1 == bambooType2) {
                        printf("Bamboo types must be different!\n");
                        continue;
                    }
                    if (isChosen(chosenTypes, chosenCounter, bambooType2)) {
                        printf("This bamboo type was already chosen!\n");
                        continue;
                    }

                    int eaten = searchBamboo2(N, forest, bambooType1, bambooType2);
                    totalBambooEaten += eaten;
                    calculatePercentageEaten(N, eaten);

                    chosenTypes[chosenCounter++] = bambooType1;
                    chosenTypes[chosenCounter++] = bambooType2;
                    eatingCounter++;
                    break;
                }
                break;
            }

            // Ask if Mochi is still hungry
            if (eatingCounter < 2) {
                char ans[10];
                printf("\nMochi is still hungry...would you like to continue? (y/n, q to quit): ");
                scanf("%s", ans);

                if (ans[0] == 'q' || ans[0] == 'Q' || ans[0] == 'n' || ans[0] == 'N') {
                    printf("Mochi is ANGRY! You must choose again!\n");
                    continue;
                } else if (ans[0] == 'y' || ans[0] == 'Y') {
                    continue;
                } else {
                    printf("Invalid input, exiting program...\n");
                    return 0;
            }   
        }
        }
    
    return 0;
}
