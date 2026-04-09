/**
 * File: min_cost_climbing_stairs_dp.c
 * Created Time: 2023-10-02
 * Author: Zuoxun (845242523@qq.com)
 */

#include "../utils/common.h"

/* Minimum érték meghatározása */
int myMin(int a, int b) {
    return a < b ? a : b;
}

/* Minimális költségű lépcsőmászás: dinamikus programozás */
int minCostClimbingStairsDP(int cost[], int costSize) {
    int n = costSize - 1;
    if (n == 1 || n == 2)
        return cost[n];
    // dp tábla inicializálása, a részproblémák megoldásainak tárolásához
    int *dp = calloc(n + 1, sizeof(int));
    // Kezdőállapot: a legkisebb részprobléma megoldásának előre beállítása
    dp[1] = cost[1];
    dp[2] = cost[2];
    // Állapotátmenet: fokozatosan oldja meg a nagyobb részproblémákat a kisebbekből
    for (int i = 3; i <= n; i++) {
        dp[i] = myMin(dp[i - 1], dp[i - 2]) + cost[i];
    }
    int res = dp[n];
    // Memória felszabadítása
    free(dp);
    return res;
}

/* Minimális költségű lépcsőmászás: helytakarékos dinamikus programozás */
int minCostClimbingStairsDPComp(int cost[], int costSize) {
    int n = costSize - 1;
    if (n == 1 || n == 2)
        return cost[n];
    int a = cost[1], b = cost[2];
    for (int i = 3; i <= n; i++) {
        int tmp = b;
        b = myMin(a, tmp) + cost[i];
        a = tmp;
    }
    return b;
}

/* Vezérlő kód */
int main() {
    int cost[] = {0, 1, 10, 1, 1, 1, 10, 1, 1, 10, 1};
    int costSize = sizeof(cost) / sizeof(cost[0]);
    printf("Input stair cost list is:");
    printArray(cost, costSize);

    int res = minCostClimbingStairsDP(cost, costSize);
    printf("Minimum cost to climb stairs is %d\n", res);

    res = minCostClimbingStairsDPComp(cost, costSize);
    printf("Minimum cost to climb stairs is %d\n", res);

    return 0;
}
