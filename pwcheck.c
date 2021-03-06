#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isSpecialSymbol(const char sym) {
    if ((sym <= 47 && sym >= 32) || (sym <= 64 && sym >= 58) || (sym <= 96 && sym >= 91) || (sym <= 126 && sym >= 123)) {
        return true;
    }
    return false;
}

bool isUpper(const char sym) {
    if (sym <= 90 && sym >= 65) {
        return true;
    }
    return false;
}

bool isLower(const char sym) {
    if (sym <= 122 && sym >= 97) {
        return true;
    }
    return false;
}

int strLength(const char *string) {
    int i = 0;
    while (string[i]) i++;
    return i;
}

int isNumber(char sym) {
    if (sym <= '9' && sym >= '0') {
        return true;
    }
    return false;
}

int strCmp(char string1[], char string2[]) {        // Compares 2 strings
    for (int i = 0; ; ++i) {
        if (string1[i] != string2[i]) {
            return string1[i] < string2[i] ? -1 : 1;
        }

        if (string1[i] == '\0') {
            return 0;
        }
    }
}

bool isFirstLevel(const char *string) {
    bool upper = 0;
    bool lower = 0;
    for (int i = 0 ; i < strLength(string); ++i) {
        if (lower == 1 && upper == 1) {
            return true;
        }

        if (isUpper(string[i])) {
            upper+= 1;
        }
        if (isLower(string[i])) {
            lower += 1;
        }
    }

    return false;
}

bool isSecondLevel(const char *string, int PARAM) {
    bool upper = false, lower = false, num = false, spec = false;

    if (isFirstLevel(string)) {
        for (int i = 0 ; i < strLength(string); ++i) {

            if (isUpper(string[i])) {
                upper += 1;
            }

            if (isLower(string[i])) {
                lower += 1;
            }
            if (isNumber(string[i])) {
                num += 1;
            }
            if (isSpecialSymbol(string[i])) {
                spec += 1;
            }
            if (PARAM <= (int)upper + (int)lower + (int)num + (int)spec) {
                return true;
            }
        }
    }
    return false;
}

bool isThirdLevel(const char *string, int PARAM) {
    int seqlength = 1;
    if (isSecondLevel(string, PARAM)) {
        for (int i = 0 ; i < strLength(string); ++i) {
            if (PARAM == seqlength) {
                return false;
            }
            if (string[i] == string [i + 1]) {
                seqlength++;
            }
        }
        return true;
    }
    return false;
}

bool isFourthLevel(const char *string, int PARAM) {

    const int localPARAM = PARAM + 1;
    int locallength = strLength(string) - PARAM;

    char substringfirst[localPARAM];
    char substringsecound[localPARAM];

    if (isThirdLevel(string, PARAM)) {
        for (int i = 0 ; i < strLength(string); ++i) {
            locallength--;
            if (locallength <= 0) {
                break;
            }
            else {
                for (int j = i, z = 0; z < PARAM; ++j, z++) {
                    substringfirst[j - i] = string[j];
                }
                for (int z = 0, j = PARAM + i; z < PARAM; ++j, z++){
                    substringsecound[j - PARAM - i] = string[j];
                }
                if (strCmp(substringfirst, substringsecound) == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

int findMin(const char *string, int MIN ){
    if (strLength(string) < MIN) {
        return strLength(string);
    }
    return MIN;
}

void checkLevel(const char *password, int LEVEL, int PARAM){
    if (LEVEL == 1) {
        if (isFirstLevel(password)) {
            printf("%s\n", password);
        }
    }
    if (LEVEL == 2) {
        if (isSecondLevel(password, PARAM)) {
            printf("%s\n", password);
        }
    }
    if (LEVEL == 3) {
        if (isThirdLevel(password, PARAM)) {
            printf("%s\n", password);
        }
    }
    if (LEVEL == 4) {
        if (isFourthLevel(password, PARAM)) {
            printf("%s\n", password);
        }
    }
}

int main(int argc, char* argv[]) {
    int LEVEL, PARAM;
    const char stats[7] = {"--stats"};

    if (argc > 1) {
        LEVEL = atoi(argv[1]);
    }
    if (argc > 2) {
        PARAM = atoi(argv[2]);
    }

    if (argc < 5) {

        char password[100];
        int MIN = 100;
        int nstrings = 0, index = 0, sumoflengths = 0;
        char c;
        bool repeat[128] = {
                0};             // Array which contains '0's and '1's at unique indexes  (128 elements in ASCII table)

        while ((c = getchar()) != EOF) {
            if (c != '\n') {
                password[index] = c;        // Assigning array
                index++;

                repeat[(int) c] = 1;         // Assign '1' at unique index
            } else {
                password[index] = 0;        // Instead of '\n' there will be '\0' in array

                checkLevel(password, LEVEL,
                           PARAM);     // Checks LEVEL and PARAM and print password if it passes this checks

                sumoflengths += strLength(password);
                MIN = findMin(password, MIN);
                nstrings++;
                index = 0;
            }
        }

        int unique = 0;
        for (int i = 0; i < 128; ++i)           // Count unique symbols
            unique += repeat[i];

        if (argc > 3) {
            if (strCmp(argv[3], stats)) {
                printf("Statistika:\nRuznych znaku: %d\nMinimalni delka: %d\nPrumerna delka: %.1f", unique, MIN,
                       (float) sumoflengths / nstrings);
            }
        }
    }

    return 0;
}