/**
 * File: coin_change.c
 * Created Time: 2023-10-02
 * Author: Zuoxun (845242523@qq.com)
 */

#include "../utils/common.h"

/* Minimum érték meghatározása */
int myMin(int a, int b) {
    return a < b ? a : b;
}

/* Érmék váltása: dinamikus programozás */
int coinChangeDP(int coins[], int amt, int coinsSize) {
    int n = coinsSize;
    int MAX = amt + 1;
    // dp tábla inicializálása
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = calloc(amt + 1, sizeof(int));
    }
    // Állapotátmenet: első sor és első oszlop
    for (int a = 1; a <= amt; a++) {
        dp[0][a] = MAX;
    }
    // Állapotátmenet: többi sor és oszlop
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // Ha meghaladja a célösszeget, ne válassza az i-edik érmét
                dp[i][a] = dp[i - 1][a];
            } else {
                // A kisebb érték: az i-edik érme nem kiválasztása és kiválasztása között
                dp[i][a] = myMin(dp[i - 1][a], dp[i][a - coins[i - 1]] + 1);
            }
        }
    }
    int res = dp[n][amt] != MAX ? dp[n][amt] : -1;
    // Memória felszabadítása
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    return res;
}

/* Érmék váltása: helytakarékos dinamikus programozás */
int coinChangeDPComp(int coins[], int amt, int coinsSize) {
    int n = coinsSize;
    int MAX = amt + 1;
    // dp tábla inicializálása
    int *dp = malloc((amt + 1) * sizeof(int));
    for (int j = 1; j <= amt; j++) {
        dp[j] = MAX;
    }
    dp[0] = 0;

    // Állapotátmenet
    for (int i = 1; i <= n; i++) {
        for (int a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // Ha meghaladja a célösszeget, ne válassza az i-edik érmét
                dp[a] = dp[a];
            } else {
                // A kisebb érték: az i-edik érme nem kiválasztása és kiválasztása között
                dp[a] = myMin(dp[a], dp[a - coins[i - 1]] + 1);
            }
        }
    }
    int res = dp[amt] != MAX ? dp[amt] : -1;
    // Memória felszabadítása
    free(dp);
    return res;
}

/* Vezérlő kód */
int main() {
    int coins[] = {1, 2, 5};
    int coinsSize = sizeof(coins) / sizeof(coins[0]);
    int amt = 4;

    // Dinamikus programozás
    int res = coinChangeDP(coins, amt, coinsSize);
    printf("Minimum number of coins needed to make target amount is %d\n", res);

    // Helytakarékos dinamikus programozás
    res = coinChangeDPComp(coins, amt, coinsSize);
    printf("Minimum number of coins needed to make target amount is %d\n", res);

    return 0;
}
