#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_WORD_LENGTH 15
#define MODEL_SIZE 10
#define WORD_LENGTH 5  

const char *wordModel[MODEL_SIZE] = {
    "education",
    "technology",
    "society",
    "progress",
    "innovation",
    "communication",
    "knowledge",
    "globalization",
    "future",
    "opportunity"
};

void displayWordModel() {
    printf("Words to type:\n");
    for (int i = 0; i < MODEL_SIZE; ++i) {
        printf("%s ", wordModel[i]);
    }
    printf("\n\n");
}

double measureTypingSpeed(clock_t start, clock_t end, int typedCharacters) {
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    return ((double)typedCharacters / WORD_LENGTH / timeTaken * 60)/10;
}

int main() {
    char targetWord[MAX_WORD_LENGTH];
    char userInput[MAX_WORD_LENGTH];
    clock_t startTime, endTime;
    int typedCharacters = 0;

    displayWordModel();

    for (int i = 0; i < MODEL_SIZE; ++i) {
        strcpy(targetWord, wordModel[i]);

        printf("Type the word: %s\n", targetWord);

        startTime = clock();  // Record the start time

        fgets(userInput, MAX_WORD_LENGTH, stdin);

        endTime = clock();  // Record the end time

        for (int j = 0; j < MAX_WORD_LENGTH - 1; ++j) {
            if (userInput[j] == targetWord[j]) {
                typedCharacters++;
            }
        }

        printf("\n");
    }

    double typingSpeed = measureTypingSpeed(startTime, endTime, typedCharacters);

    printf("Typing speed: %.2f words per minute (WPM)\n", typingSpeed);

    return 0;
}
