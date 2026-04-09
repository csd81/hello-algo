/**
 * File: hanota.c
 * Created Time: 2023-10-01
 * Author: Zuoxun (845242523@qq.com), lucas(superrat6@gmail.com)
 */

#include "../utils/common.h"

// Legfeljebb 1000 permutációt feltételezünk
#define MAX_SIZE 1000

/* Korong mozgatása */
void move(int *src, int *srcSize, int *tar, int *tarSize) {
    // Korong kivétele az src tetejéről
    int pan = src[*srcSize - 1];
    src[*srcSize - 1] = 0;
    (*srcSize)--;
    // A korong elhelyezése a tar tetejére
    tar[*tarSize] = pan;
    (*tarSize)++;
}

/* Hanoi-torony f(i) részprobléma megoldása */
void dfs(int i, int *src, int *srcSize, int *buf, int *bufSize, int *tar, int *tarSize) {
    // Ha csak egy korong marad az src-ben, közvetlenül mozgassa a tar-ra
    if (i == 1) {
        move(src, srcSize, tar, tarSize);
        return;
    }
    // f(i-1) részprobléma: a felső i-1 korong áthelyezése src-ről buf-ra, tar segítségével
    dfs(i - 1, src, srcSize, tar, tarSize, buf, bufSize);
    // f(1) részprobléma: a maradék korong áthelyezése src-ről tar-ra
    move(src, srcSize, tar, tarSize);
    // f(i-1) részprobléma: a felső i-1 korong áthelyezése buf-ról tar-ra, src segítségével
    dfs(i - 1, buf, bufSize, src, srcSize, tar, tarSize);
}

/* Hanoi-torony megoldása */
void solveHanota(int *A, int *ASize, int *B, int *BSize, int *C, int *CSize) {
    // A felső n korong áthelyezése A-ról C-re, B segítségével
    dfs(*ASize, A, ASize, B, BSize, C, CSize);
}

/* Vezérlő kód */
int main() {
    // A lista vége a rúd teteje
    int a[] = {5, 4, 3, 2, 1};
    int b[MAX_SIZE] = {0};
    int c[MAX_SIZE] = {0};

    int ASize = sizeof(a) / sizeof(a[0]);
    int BSize = 0;
    int CSize = 0;

    printf("\nInitial state:");
    printf("\nA = ");
    printArray(a, ASize);
    printf("B = ");
    printArray(b, BSize);
    printf("C = ");
    printArray(c, CSize);

    solveHanota(a, &ASize, b, &BSize, c, &CSize);

    printf("\nAfter disk movement:");
    printf("A = ");
    printArray(a, ASize);
    printf("B = ");
    printArray(b, BSize);
    printf("C = ");
    printArray(c, CSize);

    return 0;
}
