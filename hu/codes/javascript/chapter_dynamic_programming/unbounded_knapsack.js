/**
 * File: unbounded_knapsack.js
 * Created Time: 2023-08-23
 * Author: Gaofer Chou (gaofer-chou@qq.com)
 */

/* Korlátlan hátizsák: Dinamikus programozás */
function unboundedKnapsackDP(wgt, val, cap) {
    const n = wgt.length;
    // Inicializáljuk a dp táblát
    const dp = Array.from({ length: n + 1 }, () =>
        Array.from({ length: cap + 1 }, () => 0)
    );
    // Állapotátmenet
    for (let i = 1; i <= n; i++) {
        for (let c = 1; c <= cap; c++) {
            if (wgt[i - 1] > c) {
                // Ha meghaladja a hátizsák kapacitását, nem választjuk az i-edik elemet
                dp[i][c] = dp[i - 1][c];
            } else {
                // A nagyobb érték az i-edik elem ki nem választása és kiválasztása között
                dp[i][c] = Math.max(
                    dp[i - 1][c],
                    dp[i][c - wgt[i - 1]] + val[i - 1]
                );
            }
        }
    }
    return dp[n][cap];
}

/* Korlátlan hátizsák: Helytakarékos dinamikus programozás */
function unboundedKnapsackDPComp(wgt, val, cap) {
    const n = wgt.length;
    // Inicializáljuk a dp táblát
    const dp = Array.from({ length: cap + 1 }, () => 0);
    // Állapotátmenet
    for (let i = 1; i <= n; i++) {
        for (let c = 1; c <= cap; c++) {
            if (wgt[i - 1] > c) {
                // Ha meghaladja a hátizsák kapacitását, nem választjuk az i-edik elemet
                dp[c] = dp[c];
            } else {
                // A nagyobb érték az i-edik elem ki nem választása és kiválasztása között
                dp[c] = Math.max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[cap];
}

/* Tesztkód */
const wgt = [1, 2, 3];
const val = [5, 11, 15];
const cap = 4;

// Dinamikus programozás
let res = unboundedKnapsackDP(wgt, val, cap);
console.log(`Maximum item value not exceeding knapsack capacity is ${res}`);

// Helytakarékos dinamikus programozás
res = unboundedKnapsackDPComp(wgt, val, cap);
console.log(`Maximum item value not exceeding knapsack capacity is ${res}`);
