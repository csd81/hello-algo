/**
 * File: n_queens.js
 * Created Time: 2023-05-13
 * Author: Justin (xiefahit@gmail.com)
 */

/* Visszalépéses algoritmus: N királynő */
function backtrack(row, n, state, res, cols, diags1, diags2) {
    // Ha minden sor el van helyezve, rögzítjük a megoldást
    if (row === n) {
        res.push(state.map((row) => row.slice()));
        return;
    }
    // Bejárjuk az összes oszlopot
    for (let col = 0; col < n; col++) {
        // Kiszámítjuk a cellához tartozó főátlót és mellékátlót
        const diag1 = row - col + n - 1;
        const diag2 = row + col;
        // Metszés: nem engedünk királynőt a cella oszlopában, főátlójában és mellékátlójában
        if (!cols[col] && !diags1[diag1] && !diags2[diag2]) {
            // Kísérlet: a királynőt ebbe a cellába helyezzük
            state[row][col] = 'Q';
            cols[col] = diags1[diag1] = diags2[diag2] = true;
            // A következő sort helyezzük el
            backtrack(row + 1, n, state, res, cols, diags1, diags2);
            // Visszalépés: a cellát üres cellává állítjuk vissza
            state[row][col] = '#';
            cols[col] = diags1[diag1] = diags2[diag2] = false;
        }
    }
}

/* N királynő megoldása */
function nQueens(n) {
    // Inicializálunk egy n*n sakktáblát, ahol 'Q' jelöli a királynőt és '#' az üres cellát
    const state = Array.from({ length: n }, () => Array(n).fill('#'));
    const cols = Array(n).fill(false); // Rögzíti, hogy van-e királynő az oszlopban
    const diags1 = Array(2 * n - 1).fill(false); // Rögzíti, hogy van-e királynő a főátlón
    const diags2 = Array(2 * n - 1).fill(false); // Rögzíti, hogy van-e királynő a mellékátlón
    const res = [];

    backtrack(0, n, state, res, cols, diags1, diags2);
    return res;
}

// Tesztkód
const n = 4;
const res = nQueens(n);

console.log(`Input board size is ${n}`);
console.log(`Total queen placement solutions: ${res.length}`);
res.forEach((state) => {
    console.log('--------------------');
    state.forEach((row) => console.log(row));
});
