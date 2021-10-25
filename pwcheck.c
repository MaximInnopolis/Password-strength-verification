#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isSpecialSym(const char sym) {
    if ((sym <= 47 && sym >= 33) || (sym <= 64 && sym >= 58) || (sym <= 96 && sym >= 91) || (sym <= 126 && sym >= 123)) {
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

int strLength(const char *string) { // count number of element which is not full
    int i = 0;
    while (string[i] != 0) i++;
    return i - 1;               // with count of '\n' symbol
}

int isNum(char sym) {
    if (sym <= 57 && sym >= 48) {
        return true;
    }
    return false;
}

int strCmp(char string1[], char string2[] )
{
    for (int i = 0; ; i++)
    {
        if (string1[i] != string2[i])
        {
            return string1[i] < string2[i] ? -1 : 1;
        }

        if (string1[i] == '\0')
        {
            return 0;
        }
    }
}

int findNumChar(char a[120][100]){
    int unique = 1;
    for (int i = 0; i < 120; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (a[i][j] == 0) break;
            bool isUnique = true;
            bool ended = false;

            for (int z = i; z < 120; ++z) {
                bool isBrake = false;

                if (j == 0){
                    for (int y = j; y < 100; ++y) {
                        if ((i == z) && (j == y)){
                            isUnique = isUnique && (a[i][j] != a[z][y]);
                            continue;
                        }
                        if(a[z][y] == 0){
                            break;
                        }
                        if (a[i][j] == a[z][y]) {
                            isUnique = isUnique && (a[i][j] != a[z][y]);
                            printf("Found equal char %c %d %d, %d %d\n", a[i][j], i, j, z, y);
                            isBrake = true;
                            break;
                        }
                        if ((y == strLength(a[y]) - 1) && (z == 119)) {
                            isUnique = true;
                            isBrake = true;
                        }
                    }
                    if (isBrake){
                        break;
                    }
                }

                if ((j != 99) && (j != 0) && (ended == true)){
                    for (int y = 0; y < 100; ++y) {
                        if ((i == z) && (j == y)){
                            isUnique = isUnique && (a[i][j] != a[z][y]);
                            continue;
                        }
                        if(a[z][y] == 0){
                            break;
                        }
                        if (a[i][j] == a[z][y]) {
                            isUnique = isUnique && (a[i][j] != a[z][y]);
                            printf("Found equal char %c %d %d, %d %d\n", a[i][j], i, j, z, y);
                            isBrake = true;
                            break;
                        }
                        if ((y == strLength(a[y]) - 1) && (z == 119)) {
                            isUnique = true;
                            isBrake = true;
                        }
                    }
                    ended = false;
                    if (isBrake){
                        break;
                    }
                }

                if ((j != 99) && (j != 0)){
                    for (int y = 99 - j; y < 100; ++y) {
                        if ((i == z) && (j == y)){
                            isUnique = isUnique && (a[i][j] != a[z][y]);
                            continue;
                        }
                        if(a[z][y] == 0){
                            break;
                        }
                        if (a[i][j] == a[z][y]) {
                            isUnique = isUnique && (a[i][j] != a[z][y]);
                            printf("Found equal char %c %d %d, %d %d\n", a[i][j], i, j, z, y);
                            isBrake = true;
                            break;
                        }
                        if ((y == strLength(a[y]) - 1) && (z == 119)) {
                            isUnique = true;
                            isBrake = true;
                        }
                    }
                    ended = true;
                    if (isBrake){
                        break;
                    }
                }

                if ((j == 99) && (i != 119) && (z == i)){
                    continue;
                }

                if ((j == 99) && (i != 119) && (z != i)) {
                    for (int y = 0; y < 100; ++y) {
                        if ((i == z) && (j == y)){
                            isUnique = isUnique && (a[i][j] != a[z][y]);
                            continue;
                        }
                        if(a[z][y] == 0){
                            break;
                        }
                        if (a[i][j] == a[z][y]) {
                            isUnique = isUnique && (a[i][j] != a[z][y]);
                            printf("Found equal char %c %d %d, %d %d\n", a[i][j], i, j, z, y);
                            isBrake = true;
                            break;
                        }
                        if ((y == strLength(a[y]) - 1) && (z == 119)) {
                            isUnique = true;
                            isBrake = true;
                        }
                    }
                    if (isBrake){
                        break;
                    }
                }
            }
            if (isUnique){
                ++unique;
                printf("%c is unique\n", a[i][j]);
            }
        }
    }
    printf("Number of unique chars %d\n",unique);
    return unique;
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
            if (isNum(string[i])) {
                num += 1;
            }
            if (isSpecialSym(string[i])) {
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
            if (string[i] == string [i + 1]){
                seqlength++;
            }
        }
        return true;
    }
    return false;
}

bool isFourthLevel(const char *string, int PARAM) {

    int locallength = strLength(string) - PARAM;
    char substringfirst[PARAM + 1];
    char substringsecound[PARAM + 1];

    if (isThirdLevel(string, PARAM)) {
        for (int i = 0 ; i < strLength(string); ++i){
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
//                printf("substringfirst : %s at i = %d\n",substringfirst,i);
//                printf("substringsecound : %s at i = %d\n",substringsecound,i);

                if (strCmp(substringfirst, substringsecound) == 0){
                    return false;                }
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

int main(int argc, char* argv[]) {
    int LEVEL, PARAM;
    char stats[7];

    for (int i = 0; i < argc; ++i) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    if (argc > 1) {
        LEVEL = atoi(argv[1]);
    }
    if (argc > 2) {
        PARAM = atoi(argv[2]);
    }
    if (argc > 3 ) {
        stats[0] = '-';
        stats[1] = '-';
        stats[2] = 's';
        stats[3] = 't';
        stats[4] = 'a';
        stats[5] = 't';
        stats[6] = 's';
    }

    char password[120][100];
    int MIN = 100;
    int nstrings = 0, sumoflengths = 0;

    while ((int) fgets(password[nstrings], 100, stdin)) {
        if (LEVEL == 1) {
            if (isFirstLevel(password[nstrings])) {
                printf("%s", password[nstrings]);
            }
        }
        if (LEVEL == 2) {
            if (isSecondLevel(password[nstrings], PARAM)) {
                printf("%s", password[nstrings]);
            }
        }
        if (LEVEL == 3) {
            if (isThirdLevel(password[nstrings], PARAM)) {
                printf("%s", password[nstrings]);
            }
        }
        if (LEVEL == 4) {
            if (isFourthLevel(password[nstrings], PARAM)) {
                printf("%s", password[nstrings]);
            }
        }

        sumoflengths += strLength(password[nstrings]);
        MIN = findMin(password[nstrings], MIN);
        nstrings++;
    }
    if (strCmp(stats, "--stats")) {
        printf("Statistika:\nRuznych znaku: %d\nMinimalni delka: %d\nPrumerna delka: %d", findNumChar(password), MIN, sumoflengths / nstrings);
    }
    return 0;
}
