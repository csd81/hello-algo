/**
 * File: permutations_i.js
 * Created Time: 2023-05-13
 * Author: Justin (xiefahit@gmail.com)
 */

/* Visszalépéses algoritmus: Permutációk I */
function backtrack(state, choices, selected, res) {
    // Ha az állapot hossza egyenlő az elemek számával, rögzítjük a megoldást
    if (state.length === choices.length) {
        res.push([...state]);
        return;
    }
    // Bejárjuk az összes választási lehetőséget
    choices.forEach((choice, i) => {
        // Metszés: nem engedünk meg elemismétlést
        if (!selected[i]) {
            // Kísérlet: választás megtétele, állapot frissítése
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

/* Permutációk I */
function permutationsI(nums) {
    const res = [];
    backtrack([], nums, Array(nums.length).fill(false), res);
    return res;
}

// Tesztkód
const nums = [1, 2, 3];
const res = permutationsI(nums);

console.log(`Input array nums = ${JSON.stringify(nums)}`);
console.log(`All permutations res = ${JSON.stringify(res)}`);
