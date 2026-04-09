/**
 * File: knapsack.c
 * Created Time: 2023-10-02
 * Author: Zuoxun (845242523@qq.com)
 */

#include "../utils/common.h"

/* Maximum érték meghatározása */
int myMax(int a, int b) {
    return a > b ? a : b;
}

/* 0-1 hátizsák: nyers erő keresés */
int knapsackDFS(int wgt[], int val[], int i, int c) {
    // Ha minden tárgyat kiválasztottak, vagy a hátizsákban nincs szabad kapacitás, visszaad 0-t
    if (i == 0 || c == 0) {
        return 0;
    }
    // Ha meghaladja a hátizsák kapacitását, csak a mellőzés lehetséges
    if (wgt[i - 1] > c) {
        return knapsackDFS(wgt, val, i - 1, c);
    }
    // Az i-edik tárgy be nem rakásának és berakásának maximális értékét számítja ki
    int no = knapsackDFS(wgt, val, i - 1, c);
    int yes = knapsackDFS(wgt, val, i - 1, c - wgt[i - 1]) + val[i - 1];
    // A két lehetőség közül a nagyobb értéket adja vissza
    return myMax(no, yes);
}

/* 0-1 hátizsák: memorizálásos keresés */
int knapsackDFSMem(int wgt[], int val[], int memCols, int **mem, int i, int c) {
    // Ha minden tárgyat kiválasztottak, vagy a hátizsákban nincs szabad kapacitás, visszaad 0-t
    if (i == 0 || c == 0) {
        return 0;
    }
    // Ha létezik rekord, közvetlenül visszaadja
    if (mem[i][c] != -1) {
        return mem[i][c];
    }
    // Ha meghaladja a hátizsák kapacitását, csak a mellőzés lehetséges
    if (wgt[i - 1] > c) {
        return knapsackDFSMem(wgt, val, memCols, mem, i - 1, c);
    }
    // Az i-edik tárgy be nem rakásának és berakásának maximális értékét számítja ki
    int no = knapsackDFSMem(wgt, val, memCols, mem, i - 1, c);
    int yes = knapsackDFSMem(wgt, val, memCols, mem, i - 1, c - wgt[i - 1]) + val[i - 1];
    // A két lehetőség közül a nagyobb értéket rögzíti és visszaadja
    mem[i][c] = myMax(no, yes);
    return mem[i][c];
}

/* 0-1 hátizsák: dinamikus programozás */
int knapsackDP(int wgt[], int val[], int cap, int wgtSize) {
    int n = wgtSize;
    // dp tábla inicializálása
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = calloc(cap + 1, sizeof(int));
    }
    // Állapotátmenet
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= cap; c++) {
            if (wgt[i - 1] > c) {
                // Ha meghaladja a hátizsák kapacitását, ne válassza az i-edik tárgyat
                dp[i][c] = dp[i - 1][c];
            } else {
                // A nagyobb érték: az i-edik tárgy nem kiválasztása és kiválasztása között
                dp[i][c] = myMax(dp[i - 1][c], dp[i - 1][c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    int res = dp[n][cap];
    // Memória felszabadítása
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    return res;
}

/* 0-1 hátizsák: helytakarékos dinamikus programozás */
int knapsackDPComp(int wgt[], int val[], int cap, int wgtSize) {
    int n = wgtSize;
    // dp tábla inicializálása
    int *dp = calloc(cap + 1, sizeof(int));
    // Állapotátmenet
    for (int i = 1; i <= n; i++) {
        // Fordított sorrendű bejárás
        for (int c = cap; c >= 1; c--) {
            if (wgt[i - 1] <= c) {
                // A nagyobb érték: az i-edik tárgy nem kiválasztása és kiválasztása között
                dp[c] = myMax(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    int res = dp[cap];
    // Memória felszabadítása
    free(dp);
    return res;
}

/* Vezérlő kód */
int main() {
    int wgt[] = {10, 20, 30, 40, 50};
    int val[] = {50, 120, 150, 210, 240};
    int cap = 50;
    int n = sizeof(wgt) / sizeof(wgt[0]);
    int wgtSize = n;

    // Nyers erő keresés
    int res = knapsackDFS(wgt, val, n, cap);
    printf("Maximum item value not exceeding knapsack capacity is %d\n", res);

    // Memorizálásos keresés
    int **mem = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        mem[i] = malloc((cap + 1) * sizeof(int));
        memset(mem[i], -1, (cap + 1) * sizeof(int));
    }
    res = knapsackDFSMem(wgt, val, cap + 1, mem, n, cap);
    printf("Maximum item value not exceeding knapsack capacity is %d\n", res);
    // Memória felszabadítása
    for (int i = 0; i <= n; i++) {
        free(mem[i]);
    }
    free(mem);

    // Dinamikus programozás
    res = knapsackDP(wgt, val, cap, wgtSize);
    printf("Maximum item value not exceeding knapsack capacity is %d\n", res);

    // Helytakarékos dinamikus programozás
    res = knapsackDPComp(wgt, val, cap, wgtSize);
    printf("Maximum item value not exceeding knapsack capacity is %d\n", res);

    return 0;
}
