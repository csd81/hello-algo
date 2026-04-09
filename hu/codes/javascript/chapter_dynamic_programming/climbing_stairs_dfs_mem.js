/**
 * File: climbing_stairs_dfs_mem.js
 * Created Time: 2023-07-26
 * Author: yuan0221 (yl1452491917@gmail.com)
 */

/* Memoizált keresés */
function dfs(i, mem) {
    // dp[1] és dp[2] ismert, visszaadjuk őket
    if (i === 1 || i === 2) return i;
    // Ha van dp[i] bejegyzés, közvetlenül visszaadjuk
    if (mem[i] != -1) return mem[i];
    // dp[i] = dp[i-1] + dp[i-2]
    const count = dfs(i - 1, mem) + dfs(i - 2, mem);
    // Rögzítjük dp[i]-t
    mem[i] = count;
    return count;
}

/* Lépcsőmászás: Memoizált keresés */
function climbingStairsDFSMem(n) {
    // mem[i] rögzíti az i-edik lépcsőfokra való feljutás összes megoldásának számát, -1 jelzi, hogy nincs bejegyzés
    const mem = new Array(n + 1).fill(-1);
    return dfs(n, mem);
}

/* Tesztkód */
const n = 9;
const res = climbingStairsDFSMem(n);
console.log(`Climbing ${n} stairs has ${res} solutions`);
