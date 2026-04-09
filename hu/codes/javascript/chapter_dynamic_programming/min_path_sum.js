/**
 * File: min_path_sum.js
 * Created Time: 2023-08-23
 * Author: Gaofer Chou (gaofer-chou@qq.com)
 */

/* Minimális útvonalösszeg: Nyers erő keresés */
function minPathSumDFS(grid, i, j) {
    // Ha a bal felső cellánál vagyunk, leállítjuk a keresést
    if (i === 0 && j === 0) {
        return grid[0][0];
    }
    // Ha a sor- vagy oszlopindex határon kívül van, +∞ költséget adunk vissza
    if (i < 0 || j < 0) {
        return Infinity;
    }
    // Kiszámítjuk a minimális útvonalköltséget a bal felső saroktól (i-1, j)-ig és (i, j-1)-ig
    const up = minPathSumDFS(grid, i - 1, j);
    const left = minPathSumDFS(grid, i, j - 1);
    // Visszaadjuk a minimális útvonalköltséget a bal felső saroktól (i, j)-ig
    return Math.min(left, up) + grid[i][j];
}

/* Minimális útvonalösszeg: Memoizált keresés */
function minPathSumDFSMem(grid, mem, i, j) {
    // Ha a bal felső cellánál vagyunk, leállítjuk a keresést
    if (i === 0 && j === 0) {
        return grid[0][0];
    }
    // Ha a sor- vagy oszlopindex határon kívül van, +∞ költséget adunk vissza
    if (i < 0 || j < 0) {
        return Infinity;
    }
    // Ha van bejegyzés, közvetlenül visszaadjuk
    if (mem[i][j] !== -1) {
        return mem[i][j];
    }
    // A bal és felső cella minimális útvonalköltsége
    const up = minPathSumDFSMem(grid, mem, i - 1, j);
    const left = minPathSumDFSMem(grid, mem, i, j - 1);
    // Rögzítjük és visszaadjuk a minimális útvonalköltséget a bal felső saroktól (i, j)-ig
    mem[i][j] = Math.min(left, up) + grid[i][j];
    return mem[i][j];
}

/* Minimális útvonalösszeg: Dinamikus programozás */
function minPathSumDP(grid) {
    const n = grid.length,
        m = grid[0].length;
    // Inicializáljuk a dp táblát
    const dp = Array.from({ length: n }, () =>
        Array.from({ length: m }, () => 0)
    );
    dp[0][0] = grid[0][0];
    // Állapotátmenet: első sor
    for (let j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    // Állapotátmenet: első oszlop
    for (let i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    // Állapotátmenet: többi sor és oszlop
    for (let i = 1; i < n; i++) {
        for (let j = 1; j < m; j++) {
            dp[i][j] = Math.min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        }
    }
    return dp[n - 1][m - 1];
}

/* Minimális útvonalösszeg: Helytakarékos dinamikus programozás */
function minPathSumDPComp(grid) {
    const n = grid.length,
        m = grid[0].length;
    // Inicializáljuk a dp táblát
    const dp = new Array(m);
    // Állapotátmenet: első sor
    dp[0] = grid[0][0];
    for (let j = 1; j < m; j++) {
        dp[j] = dp[j - 1] + grid[0][j];
    }
    // Állapotátmenet: többi sor
    for (let i = 1; i < n; i++) {
        // Állapotátmenet: első oszlop
        dp[0] = dp[0] + grid[i][0];
        // Állapotátmenet: többi oszlop
        for (let j = 1; j < m; j++) {
            dp[j] = Math.min(dp[j - 1], dp[j]) + grid[i][j];
        }
    }
    return dp[m - 1];
}

/* Tesztkód */
const grid = [
    [1, 3, 1, 5],
    [2, 2, 4, 2],
    [5, 3, 2, 1],
    [4, 3, 5, 2],
];
const n = grid.length,
    m = grid[0].length;
// Nyers erő keresés
let res = minPathSumDFS(grid, n - 1, m - 1);
console.log(`Minimum path sum from top-left to bottom-right is ${res}`);

// Memoizált keresés
const mem = Array.from({ length: n }, () =>
    Array.from({ length: m }, () => -1)
);
res = minPathSumDFSMem(grid, mem, n - 1, m - 1);
console.log(`Minimum path sum from top-left to bottom-right is ${res}`);

// Dinamikus programozás
res = minPathSumDP(grid);
console.log(`Minimum path sum from top-left to bottom-right is ${res}`);

// Helytakarékos dinamikus programozás
res = minPathSumDPComp(grid);
console.log(`Minimum path sum from top-left to bottom-right is ${res}`);
