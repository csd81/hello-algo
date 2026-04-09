/**
 * File: climbing_stairs_dp.js
 * Created Time: 2023-07-26
 * Author: yuan0221 (yl1452491917@gmail.com)
 */

/* Lépcsőmászás: Dinamikus programozás */
function climbingStairsDP(n) {
    if (n === 1 || n === 2) return n;
    // Inicializáljuk a dp táblát, a részproblémák megoldásainak tárolásához
    const dp = new Array(n + 1).fill(-1);
    // Kezdeti állapot: a legkisebb részprobléma megoldásának előbeállítása
    dp[1] = 1;
    dp[2] = 2;
    // Állapotátmenet: a kisebb részproblémákból fokozatosan megoldjuk a nagyobbakat
    for (let i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

/* Lépcsőmászás: Helytakarékos dinamikus programozás */
function climbingStairsDPComp(n) {
    if (n === 1 || n === 2) return n;
    let a = 1,
        b = 2;
    for (let i = 3; i <= n; i++) {
        const tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}

/* Tesztkód */
const n = 9;
let res = climbingStairsDP(n);
console.log(`Climbing ${n} stairs has ${res} solutions`);
res = climbingStairsDPComp(n);
console.log(`Climbing ${n} stairs has ${res} solutions`);
