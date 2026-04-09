/**
 * File : n_queens.c
 * Created Time: 2023-09-25
 * Author : lucas (superrat6@gmail.com)
 */

#include "../utils/common.h"

#define MAX_SIZE 100

/* Visszalépéses algoritmus: N királynő */
void backtrack(int row, int n, char state[MAX_SIZE][MAX_SIZE], char ***res, int *resSize, bool cols[MAX_SIZE],
               bool diags1[2 * MAX_SIZE - 1], bool diags2[2 * MAX_SIZE - 1]) {
    // Ha minden sor el van helyezve, rögzítse a megoldást
    if (row == n) {
        res[*resSize] = (char **)malloc(sizeof(char *) * n);
        for (int i = 0; i < n; ++i) {
            res[*resSize][i] = (char *)malloc(sizeof(char) * (n + 1));
            strcpy(res[*resSize][i], state[i]);
        }
        (*resSize)++;
        return;
    }
    // Az összes oszlop bejárása
    for (int col = 0; col < n; col++) {
        // A cellához tartozó főátló és mellékátló kiszámítása
        int diag1 = row - col + n - 1;
        int diag2 = row + col;
        // Vágás: ne engedjük meg, hogy a cella oszlopában, főátlójában és mellékátlójában királyné legyen
        if (!cols[col] && !diags1[diag1] && !diags2[diag2]) {
            // Kísérlet: királynő elhelyezése ebbe a cellába
            state[row][col] = 'Q';
            cols[col] = diags1[diag1] = diags2[diag2] = true;
            // A következő sor elhelyezése
            backtrack(row + 1, n, state, res, resSize, cols, diags1, diags2);
            // Visszalépés: a cella visszaállítása üres cellává
            state[row][col] = '#';
            cols[col] = diags1[diag1] = diags2[diag2] = false;
        }
    }
}

/* N királynő megoldása */
char ***nQueens(int n, int *returnSize) {
    char state[MAX_SIZE][MAX_SIZE];
    // n*n-es sakktábla inicializálása, ahol 'Q' a királynőt, '#' az üres cellát jelöli
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            state[i][j] = '#';
        }
        state[i][n] = '\0';
    }
    bool cols[MAX_SIZE] = {false};           // Jelzi, hogy van-e királynő az oszlopban
    bool diags1[2 * MAX_SIZE - 1] = {false}; // Jelzi, hogy van-e királynő a főátlón
    bool diags2[2 * MAX_SIZE - 1] = {false}; // Jelzi, hogy van-e királynő a mellékátlón

    char ***res = (char ***)malloc(sizeof(char **) * MAX_SIZE);
    *returnSize = 0;
    backtrack(0, n, state, res, returnSize, cols, diags1, diags2);
    return res;
}

/* Vezérlő kód */
int main() {
    int n = 4;
    int returnSize;
    char ***res = nQueens(n, &returnSize);

    printf("Input board size is %d\n", n);
    printf("Total queen placement solutions: %d\n", returnSize);
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("[");
            for (int k = 0; res[i][j][k] != '\0'; ++k) {
                printf("%c", res[i][j][k]);
                if (res[i][j][k + 1] != '\0') {
                    printf(", ");
                }
            }
            printf("]\n");
        }
        printf("---------------------\n");
    }

    // Memória felszabadítása
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < n; ++j) {
            free(res[i][j]);
        }
        free(res[i]);
    }
    free(res);

    return 0;
}
