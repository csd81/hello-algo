/**
 * File: climbing_stairs_dp.c
 * Created Time: 2023-09-19
 * Author: huawuque404 (huawuque404@163.com)
 */

#include "../utils/common.h"

/* Lépcsőmászás: dinamikus programozás */
int climbingStairsDP(int n) {
    if (n == 1 || n == 2)
        return n;
    // dp tábla inicializálása, a részproblémák megoldásainak tárolásához
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    // Kezdőállapot: a legkisebb részprobléma megoldásának előre beállítása
    dp[1] = 1;
    dp[2] = 2;
    // Állapotátmenet: fokozatosan oldja meg a nagyobb részproblémákat a kisebbekből
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int result = dp[n];
    free(dp);
    return result;
}

/* Lépcsőmászás: helytakarékos dinamikus programozás */
int climbingStairsDPComp(int n) {
    if (n == 1 || n == 2)
        return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}

/* Vezérlő kód */
int main() {
    int n = 9;

    int res = climbingStairsDP(n);
    printf("Climbing %d stairs has %d solutions\n", n, res);

    res = climbingStairsDPComp(n);
    printf("Climbing %d stairs has %d solutions\n", n, res);

    return 0;
}
