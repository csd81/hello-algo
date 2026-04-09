/**
 * File: climbing_stairs_dfs.js
 * Created Time: 2023-07-26
 * Author: yuan0221 (yl1452491917@gmail.com)
 */

/* Keresés */
function dfs(i) {
    // dp[1] és dp[2] ismert, visszaadjuk őket
    if (i === 1 || i === 2) return i;
    // dp[i] = dp[i-1] + dp[i-2]
    const count = dfs(i - 1) + dfs(i - 2);
    return count;
}

/* Lépcsőmászás: Keresés */
function climbingStairsDFS(n) {
    return dfs(n);
}

/* Tesztkód */
const n = 9;
const res = climbingStairsDFS(n);
console.log(`Climbing ${n} stairs has ${res} solutions`);
