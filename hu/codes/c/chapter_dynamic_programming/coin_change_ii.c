/**
 * File: coin_change_ii.c
 * Created Time: 2023-10-02
 * Author: Zuoxun (845242523@qq.com)
 */

#include "../utils/common.h"

/* Érmék váltása II: dinamikus programozás */
int coinChangeIIDP(int coins[], int amt, int coinsSize) {
    int n = coinsSize;
    // dp tábla inicializálása
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = calloc(amt + 1, sizeof(int));
    }
    // Az első oszlop inicializálása
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    // Állapotátmenet
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // Ha meghaladja a célösszeget, ne válassza az i-edik érmét
                dp[i][a] = dp[i - 1][a];
            } else {
                // A két lehetőség összege: az i-edik érme nem kiválasztása és kiválasztása
                dp[i][a] = dp[i - 1][a] + dp[i][a - coins[i - 1]];
            }
        }
    }
    int res = dp[n][amt];
    // Memória felszabadítása
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}

/* Érmék váltása II: helytakarékos dinamikus programozás */
int coinChangeIIDPComp(int coins[], int amt, int coinsSize) {
    int n = coinsSize;
    // dp tábla inicializálása
    int *dp = calloc(amt + 1, sizeof(int));
    dp[0] = 1;
    // Állapotátmenet
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // Ha meghaladja a célösszeget, ne válassza az i-edik érmét
                dp[a] = dp[a];
            } else {
                // A két lehetőség összege: az i-edik érme nem kiválasztása és kiválasztása
                dp[a] = dp[a] + dp[a - coins[i - 1]];
            }
        }
    }
    int res = dp[amt];
    // Memória felszabadítása
    free(dp);
    return res;
}

/* Vezérlő kód */
int main() {
    int coins[] = {1, 2, 5};
    int coinsSize = sizeof(coins) / sizeof(coins[0]);
    int amt = 5;

    // Dinamikus programozás
    int res = coinChangeIIDP(coins, amt, coinsSize);
    printf("Number of coin combinations to make target amount is %d\n", res);

    // Helytakarékos dinamikus programozás
    res = coinChangeIIDPComp(coins, amt, coinsSize);
    printf("Number of coin combinations to make target amount is %d\n", res);

    return 0;
}
