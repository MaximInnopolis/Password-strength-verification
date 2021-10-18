#include <stdio.h>
#include <stdbool.h>


int strLength(const char *string) {
    int i = 0;
    while (string[i]) i++;
    return i;
}

bool isFirstLevel(const char *string) {
    int upper = 0;
    int lower = 0;
    for (int i = 0 ; i < strLength(string); ++i) {
        if (lower >= 1 && upper >= 1) {
            return true;
        }

        if (string[i] <= 90 && string[i] >= 65) {
            upper+= 1;
        }
        if (string[i] <= 122 && string[i] >= 97) {
            lower += 1;
        }
    }

    return false;
}

int findMin(const char *string, int MIN ){
    if (strLength(string) < MIN) {
        return strLength(string);
    }
    return MIN;
}

int main(int argc, char* argv[]) {
    int LEVEL, PARAM;
    char *stats;
    if (argc > 1) {
        LEVEL = (int) argv[1];
    }
    if (argc > 2) {
        PARAM = (int) argv[2];
    }
    if (argc > 3) {
        char *stats = argv[3];
    }

    char password[120][100];
    for (int i = 0; i < 120; ++i) {
        for (int j = 0; j < 100; ++j){
            password[i][j] =  NULL;
        }
    }

    int AVG = 0, MIN = 100, NCHAR = 0;
    int nstrings = 0, sumoflengths = 0;

    for (int i = 0; i < 1000; ++i)
    {
        while ((int) fgets(password[i], 100, stdin) != EOF) {
            if (LEVEL == 1) {
                isFirstLevel(password[i]);
            }
            nstrings++;
            sumoflengths += strLength(password[i]);

            MIN = findMin(password[i], MIN);

            if (stats != NULL){
                printf("Statistika:\n Ruznych znaku: %d\nMinimalni delka: %d\nPrumerna delka: %d", NCHAR, MIN, sumoflengths / nstrings);
            }
        }
    }

    return 0;
}