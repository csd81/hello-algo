/**
 * File: permutations_ii.js
 * Created Time: 2023-05-13
 * Author: Justin (xiefahit@gmail.com)
 */

/* Visszalépéses algoritmus: Permutációk II */
function backtrack(state, choices, selected, res) {
    // Ha az állapot hossza egyenlő az elemek számával, rögzítjük a megoldást
    if (state.length === choices.length) {
        res.push([...state]);
        return;
    }
    // Bejárjuk az összes választási lehetőséget
    const duplicated = new Set();
    choices.forEach((choice, i) => {
        // Metszés: nem engedünk meg elemismétlést, és nem engedünk meg egyenlő elemek ismételt kiválasztását
        if (!selected[i] && !duplicated.has(choice)) {
            // Kísérlet: választás megtétele, állapot frissítése
            duplicated.add(choice); // Rögzítjük a kiválasztott elem értékét
            selected[i] = true;
            state.push(choice);
            // Folytatjuk a következő kiválasztási körrel
            backtrack(state, choices, selected, res);
            // Visszalépés: a választás visszavonása, visszaállítás az előző állapotra
            selected[i] = false;
            state.pop();
        }
    });
}

/* Permutációk II */
function permutationsII(nums) {
    const res = [];
    backtrack([], nums, Array(nums.length).fill(false), res);
    return res;
}

// Tesztkód
const nums = [1, 2, 2];
const res = permutationsII(nums);

console.log(`Input array nums = ${JSON.stringify(nums)}`);
console.log(`All permutations res = ${JSON.stringify(res)}`);
