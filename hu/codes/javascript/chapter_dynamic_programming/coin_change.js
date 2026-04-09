/**
 * File: coin_change.js
 * Created Time: 2023-08-23
 * Author: Gaofer Chou (gaofer-chou@qq.com)
 */

/* Pénzváltás: Dinamikus programozás */
function coinChangeDP(coins, amt) {
    const n = coins.length;
    const MAX = amt + 1;
    // Inicializáljuk a dp táblát
    const dp = Array.from({ length: n + 1 }, () =>
        Array.from({ length: amt + 1 }, () => 0)
    );
    // Állapotátmenet: első sor és első oszlop
    for (let a = 1; a <= amt; a++) {
        dp[0][a] = MAX;
    }
    // Állapotátmenet: többi sor és oszlop
    for (let i = 1; i <= n; i++) {
        for (let a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // Ha meghaladja a célösszeget, nem választjuk az i-edik érmét
                dp[i][a] = dp[i - 1][a];
            } else {
                // A kisebb érték az i-edik érme ki nem választása és kiválasztása között
                dp[i][a] = Math.min(dp[i - 1][a], dp[i][a - coins[i - 1]] + 1);
            }
        }
    }
    return dp[n][amt] !== MAX ? dp[n][amt] : -1;
}

/* Pénzváltás: Helytakarékos dinamikus programozás */
function coinChangeDPComp(coins, amt) {
    const n = coins.length;
    const MAX = amt + 1;
    // Inicializáljuk a dp táblát
    const dp = Array.from({ length: amt + 1 }, () => MAX);
    dp[0] = 0;
    // Állapotátmenet
    for (let i = 1; i <= n; i++) {
        for (let a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // Ha meghaladja a célösszeget, nem választjuk az i-edik érmét
                dp[a] = dp[a];
            } else {
                // A kisebb érték az i-edik érme ki nem választása és kiválasztása között
                dp[a] = Math.min(dp[a], dp[a - coins[i - 1]] + 1);
            }
        }
    }
    return dp[amt] !== MAX ? dp[amt] : -1;
}

/* Tesztkód */
const coins = [1, 2, 5];
const amt = 4;

// Dinamikus programozás
let res = coinChangeDP(coins, amt);
console.log(`Minimum coins needed to make target amount is ${res}`);

// Helytakarékos dinamikus programozás
res = coinChangeDPComp(coins, amt);
console.log(`Minimum coins needed to make target amount is ${res}`);
