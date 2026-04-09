/**
 * File: climbing_stairs_dfs_mem.c
 * Created Time: 2023-09-19
 * Author: huawuque404 (huawuque404@163.com)
 */

#include "../utils/common.h"

/* Memorizálásos keresés */
int dfs(int i, int *mem) {
    // Ismert dp[1] és dp[2] értékek, visszaadja azokat
    if (i == 1 || i == 2)
        return i;
    // Ha dp[i] rekord létezik, közvetlenül visszaadja azt
    if (mem[i] != -1)
        return mem[i];
    // dp[i] = dp[i-1] + dp[i-2]
    int count = dfs(i - 1, mem) + dfs(i - 2, mem);
    // dp[i] rögzítése
    mem[i] = count;
    return count;
}

/* Lépcsőmászás: memorizálásos keresés */
int climbingStairsDFSMem(int n) {
    // mem[i] tárolja az i-edik lépcsőfokra való feljutás összes megoldásának számát, -1 azt jelenti, hogy nincs rekord
    int *mem = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        mem[i] = -1;
    }
    int result = dfs(n, mem);
    free(mem);
    return result;
}

/* Vezérlő kód */
int main() {
    int n = 9;

    int res = climbingStairsDFSMem(n);
    printf("Climbing %d stairs has %d solutions\n", n, res);

    return 0;
}
