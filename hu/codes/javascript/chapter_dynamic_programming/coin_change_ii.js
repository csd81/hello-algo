/**
 * File: coin_change_ii.js
 * Created Time: 2023-08-23
 * Author: Gaofer Chou (gaofer-chou@qq.com)
 */

/* Pénzváltás II: Dinamikus programozás */
function coinChangeIIDP(coins, amt) {
    const n = coins.length;
    // Inicializáljuk a dp táblát
    const dp = Array.from({ length: n + 1 }, () =>
        Array.from({ length: amt + 1 }, () => 0)
    );
    // Az első oszlop inicializálása
    for (let i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    // Állapotátmenet
    for (let i = 1; i <= n; i++) {
        for (let a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // Ha meghaladja a célösszeget, nem választjuk az i-edik érmét
                dp[i][a] = dp[i - 1][a];
            } else {
                // A két lehetőség összege: az i-edik érme ki nem választása és kiválasztása
                dp[i][a] = dp[i - 1][a] + dp[i][a - coins[i - 1]];
            }
        }
    }
    return dp[n][amt];
}

/* Pénzváltás II: Helytakarékos dinamikus programozás */
function coinChangeIIDPComp(coins, amt) {
    const n = coins.length;
    // Inicializáljuk a dp táblát
    const dp = Array.from({ length: amt + 1 }, () => 0);
    dp[0] = 1;
    // Állapotátmenet
    for (let i = 1; i <= n; i++) {
        for (let a = 1; a <= amt; a++) {
            if (coins[i - 1] > a) {
                // Ha meghaladja a célösszeget, nem választjuk az i-edik érmét
                dp[a] = dp[a];
            } else {
                // A két lehetőség összege: az i-edik érme ki nem választása és kiválasztása
                dp[a] = dp[a] + dp[a - coins[i - 1]];
            }
        }
    }
    return dp[amt];
}

/* Tesztkód */
const coins = [1, 2, 5];
const amt = 5;

// Dinamikus programozás
let res = coinChangeIIDP(coins, amt);
console.log(`Number of coin combinations to make target amount is ${res}`);

// Helytakarékos dinamikus programozás
res = coinChangeIIDPComp(coins, amt);
console.log(`Number of coin combinations to make target amount is ${res}`);
