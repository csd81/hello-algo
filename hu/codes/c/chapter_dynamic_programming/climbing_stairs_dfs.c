/**
 * File: climbing_stairs_dfs.c
 * Created Time: 2023-09-19
 * Author: huawuque404 (huawuque404@163.com)
 */

#include "../utils/common.h"

/* Keresés */
int dfs(int i) {
    // Ismert dp[1] és dp[2] értékek, visszaadja azokat
    if (i == 1 || i == 2)
        return i;
    // dp[i] = dp[i-1] + dp[i-2]
    int count = dfs(i - 1) + dfs(i - 2);
    return count;
}

/* Lépcsőmászás: keresés */
int climbingStairsDFS(int n) {
    return dfs(n);
}

/* Vezérlő kód */
int main() {
    int n = 9;

    int res = climbingStairsDFS(n);
    printf("Climbing %d stairs has %d solutions\n", n, res);

    return 0;
}
