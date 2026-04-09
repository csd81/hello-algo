/**
 * File: iteration.c
 * Created Time: 2023-09-09
 * Author: Gonglja (glj0@outlook.com), MwumLi (mwumli@hotmail.com)
 */

#include "../utils/common.h"

/* for ciklus */
int forLoop(int n) {
    int res = 0;
    // Összegzés: 1, 2, ..., n-1, n
    for (int i = 1; i <= n; i++) {
        res += i;
    }
    return res;
}

/* while ciklus */
int whileLoop(int n) {
    int res = 0;
    int i = 1; // Feltételváltozó inicializálása
    // Összegzés: 1, 2, ..., n-1, n
    while (i <= n) {
        res += i;
        i++; // Feltételváltozó frissítése
    }
    return res;
}

/* while ciklus (két frissítéssel) */
int whileLoopII(int n) {
    int res = 0;
    int i = 1; // Feltételváltozó inicializálása
    // Összegzés: 1, 4, 10, ...
    while (i <= n) {
        res += i;
        // Feltételváltozó frissítése
        i++;
        i *= 2;
    }
    return res;
}

/* Egymásba ágyazott for ciklus */
char *nestedForLoop(int n) {
    // n * n a pontok száma, az "(i, j), " karakterlánc max hossza 6+10*2, plusz hely a null karakter \0-nak
    int size = n * n * 26 + 1;
    char *res = malloc(size * sizeof(char));
    // i = 1, 2, ..., n-1, n ciklus
    for (int i = 1; i <= n; i++) {
        // j = 1, 2, ..., n-1, n ciklus
        for (int j = 1; j <= n; j++) {
            char tmp[26];
            snprintf(tmp, sizeof(tmp), "(%d, %d), ", i, j);
            strncat(res, tmp, size - strlen(res) - 1);
        }
    }
    return res;
}

/* Vezérlő kód */
int main() {
    int n = 5;
    int res;

    res = forLoop(n);
    printf("\nFor loop sum result res = %d\n", res);

    res = whileLoop(n);
    printf("\nWhile loop sum result res = %d\n", res);

    res = whileLoopII(n);
    printf("\nWhile loop (two updates) sum result res = %d\n", res);

    char *resStr = nestedForLoop(n);
    printf("\nNested for loop traversal result %s\r\n", resStr);
    free(resStr);

    return 0;
}
