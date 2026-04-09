/**
 * File: climbing_stairs_backtrack.c
 * Created Time: 2023-09-22
 * Author: huawuque404 (huawuque404@163.com)
 */

#include "../utils/common.h"

/* Visszalépés */
void backtrack(int *choices, int state, int n, int *res, int len) {
    // Ha elértük az n-edik lépcsőfokot, növeljük a megoldások számát 1-gyel
    if (state == n)
        res[0]++;
    // Az összes lehetőség bejárása
    for (int i = 0; i < len; i++) {
        int choice = choices[i];
        // Vágás: nem szabad az n-edik lépcsőfokot meghaladni
        if (state + choice > n)
            continue;
        // Kísérlet: választás végrehajtása, állapot frissítése
        backtrack(choices, state + choice, n, res, len);
        // Visszalépés
    }
}

/* Lépcsőmászás: visszalépés */
int climbingStairsBacktrack(int n) {
    int choices[2] = {1, 2}; // Egyszerre 1 vagy 2 lépcsőfokot lehet mászni
    int state = 0;           // Indulás a 0. lépcsőfokról
    int *res = (int *)malloc(sizeof(int));
    *res = 0; // res[0] tárolja a megoldások számát
    int len = sizeof(choices) / sizeof(int);
    backtrack(choices, state, n, res, len);
    int result = *res;
    free(res);
    return result;
}

/* Vezérlő kód */
int main() {
    int n = 9;

    int res = climbingStairsBacktrack(n);
    printf("Climbing %d stairs has %d solutions\n", n, res);

    return 0;
}
