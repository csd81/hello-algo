/**
 * File: climbing_stairs_backtrack.js
 * Created Time: 2023-07-26
 * Author: yuan0221 (yl1452491917@gmail.com)
 */

/* Visszalépés */
function backtrack(choices, state, n, res) {
    // Ha felértünk az n-edik lépcsőfokra, a megoldások számát 1-gyel növeljük
    if (state === n) res.set(0, res.get(0) + 1);
    // Bejárjuk az összes választási lehetőséget
    for (const choice of choices) {
        // Metszés: nem engedünk meg n-nél tovább menni
        if (state + choice > n) continue;
        // Kísérlet: választás megtétele, állapot frissítése
        backtrack(choices, state + choice, n, res);
        // Visszalépés
    }
}

/* Lépcsőmászás: Visszalépés */
function climbingStairsBacktrack(n) {
    const choices = [1, 2]; // Választhatunk 1 vagy 2 lépcsőfokot
    const state = 0; // A 0. lépcsőfoktól kezdjük
    const res = new Map();
    res.set(0, 0); // res[0] értékével rögzítjük a megoldások számát
    backtrack(choices, state, n, res);
    return res.get(0);
}

/* Tesztkód */
const n = 9;
const res = climbingStairsBacktrack(n);
console.log(`Climbing ${n} stairs has ${res} solutions`);
