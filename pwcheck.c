#include <stdio.h>
#include <stdbool.h>

bool isSpecialSym(const char sym) {
    if ((sym <= 47 && 33 >= sym) || (sym <= 64 && 58 >= sym) || (sym <= 96 && 91 >= sym) || (sym <= 123 && 126 >= sym)) {
        return true;
    }
    return false;
}

bool isUpper(const char sym){
    if (sym <= 90 && sym >= 65) {
        return true;
    }
    return false;
}

bool isLower(const char sym){
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

int isNum(char sym) {
    if (sym <= 57 && sym >= 48) {
        return true;
    }
    return false;
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
    bool upper = 0;
    bool lower = 0;
    bool num = 0;
    bool spec = 0;

    if (isFirstLevel(string)){
        for (int i = 0 ; i < strLength(string); ++i){
            if (PARAM == (int)upper + (int)lower + (int)num + (int)spec){
                return true;
            }
            if (isUpper(string[i])) {
                upper += 1;
            }

            if (isLower(string[i])) {
                lower += 1;
            }
            if (isNum(string[i])) {
                num += 1;
            }
            if (isSpecialSym(string[i])) {
                spec += 1;
            }
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
    char stats[7];
    if (argc > 1) {
        LEVEL = (int) argv[1];
    }
    if (argc > 2) {
        PARAM = (int) argv[2];
    }
    if ((argc == 4 ) && (argv[3] == "--stats")) {
        gets(stats);
    }

    else { printf("Too many arguments");}

    char password[120][100];
    for (int i = 0; i < 120; ++i) {
        for (int j = 0; j < 100; ++j){
            getc(NULL);
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

            if (LEVEL == 2) {
                isSecondLevel(password[i], PARAM);
            }
            nstrings++;
            sumoflengths += strLength(password[i]);

            MIN = findMin(password[i], MIN);

            if (stats == "--stats"){
                printf("Statistika:\n Ruznych znaku: %d\nMinimalni delka: %d\nPrumerna delka: %d", NCHAR, MIN, sumoflengths / nstrings);
            }
        }
    }

    return 0;
}