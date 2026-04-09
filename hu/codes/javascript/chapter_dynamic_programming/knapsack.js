/**
 * File: knapsack.js
 * Created Time: 2023-08-23
 * Author: Gaofer Chou (gaofer-chou@qq.com)
 */

/* 0-1 hátizsák: Nyers erő keresés */
function knapsackDFS(wgt, val, i, c) {
    // Ha az összes elem ki lett választva vagy a hátizsáknak nincs maradék kapacitása, visszaadjuk a 0 értéket
    if (i === 0 || c === 0) {
        return 0;
    }
    // Ha meghaladja a hátizsák kapacitását, csak azt választhatjuk, hogy nem tesszük be
    if (wgt[i - 1] > c) {
        return knapsackDFS(wgt, val, i - 1, c);
    }
    // Kiszámítjuk az i-edik elem be nem tételének és betételének maximális értékét
    const no = knapsackDFS(wgt, val, i - 1, c);
    const yes = knapsackDFS(wgt, val, i - 1, c - wgt[i - 1]) + val[i - 1];
    // Visszaadjuk a két lehetőség közül a nagyobb értéket
    return Math.max(no, yes);
}

/* 0-1 hátizsák: Memoizált keresés */
function knapsackDFSMem(wgt, val, mem, i, c) {
    // Ha az összes elem ki lett választva vagy a hátizsáknak nincs maradék kapacitása, visszaadjuk a 0 értéket
    if (i === 0 || c === 0) {
        return 0;
    }
    // Ha van bejegyzés, közvetlenül visszaadjuk
    if (mem[i][c] !== -1) {
        return mem[i][c];
    }
    // Ha meghaladja a hátizsák kapacitását, csak azt választhatjuk, hogy nem tesszük be
    if (wgt[i - 1] > c) {
        return knapsackDFSMem(wgt, val, mem, i - 1, c);
    }
    // Kiszámítjuk az i-edik elem be nem tételének és betételének maximális értékét
    const no = knapsackDFSMem(wgt, val, mem, i - 1, c);
    const yes =
        knapsackDFSMem(wgt, val, mem, i - 1, c - wgt[i - 1]) + val[i - 1];
    // Rögzítjük és visszaadjuk a két lehetőség közül a nagyobb értéket
    mem[i][c] = Math.max(no, yes);
    return mem[i][c];
}

/* 0-1 hátizsák: Dinamikus programozás */
function knapsackDP(wgt, val, cap) {
    const n = wgt.length;
    // Inicializáljuk a dp táblát
    const dp = Array(n + 1)
        .fill(0)
        .map(() => Array(cap + 1).fill(0));
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
                    dp[i - 1][c - wgt[i - 1]] + val[i - 1]
                );
            }
        }
    }
    return dp[n][cap];
}

/* 0-1 hátizsák: Helytakarékos dinamikus programozás */
function knapsackDPComp(wgt, val, cap) {
    const n = wgt.length;
    // Inicializáljuk a dp táblát
    const dp = Array(cap + 1).fill(0);
    // Állapotátmenet
    for (let i = 1; i <= n; i++) {
        // Fordított sorrendben járjuk be
        for (let c = cap; c >= 1; c--) {
            if (wgt[i - 1] <= c) {
                // A nagyobb érték az i-edik elem ki nem választása és kiválasztása között
                dp[c] = Math.max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[cap];
}

/* Tesztkód */
const wgt = [10, 20, 30, 40, 50];
const val = [50, 120, 150, 210, 240];
const cap = 50;
const n = wgt.length;

// Nyers erő keresés
let res = knapsackDFS(wgt, val, n, cap);
console.log(`Maximum item value not exceeding knapsack capacity is ${res}`);

// Memoizált keresés
const mem = Array.from({ length: n + 1 }, () =>
    Array.from({ length: cap + 1 }, () => -1)
);
res = knapsackDFSMem(wgt, val, mem, n, cap);
console.log(`Maximum item value not exceeding knapsack capacity is ${res}`);

// Dinamikus programozás
res = knapsackDP(wgt, val, cap);
console.log(`Maximum item value not exceeding knapsack capacity is ${res}`);

// Helytakarékos dinamikus programozás
res = knapsackDPComp(wgt, val, cap);
console.log(`Maximum item value not exceeding knapsack capacity is ${res}`);
