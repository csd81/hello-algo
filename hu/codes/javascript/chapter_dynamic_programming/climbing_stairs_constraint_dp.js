/**
 * File: climbing_stairs_constraint_dp.js
 * Created Time: 2023-08-23
 * Author: Gaofer Chou (gaofer-chou@qq.com)
 */

/* Lépcsőmászás feltétellel: Dinamikus programozás */
function climbingStairsConstraintDP(n) {
    if (n === 1 || n === 2) {
        return 1;
    }
    // Inicializáljuk a dp táblát, a részproblémák megoldásainak tárolásához
    const dp = Array.from(new Array(n + 1), () => new Array(3));
    // Kezdeti állapot: a legkisebb részprobléma megoldásának előbeállítása
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;
    // Állapotátmenet: a kisebb részproblémákból fokozatosan megoldjuk a nagyobbakat
    for (let i = 3; i <= n; i++) {
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    }
    return dp[n][1] + dp[n][2];
}

/* Tesztkód */
const n = 9;
const res = climbingStairsConstraintDP(n);
console.log(`Climbing ${n} stairs has ${res} solutions`);
