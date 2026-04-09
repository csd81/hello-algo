/**
 * File: subset_sum_i_naive.js
 * Created Time: 2023-07-30
 * Author: yuan0221 (yl1452491917@gmail.com)
 */

/* Visszalépéses algoritmus: Részhalmazösszeg I */
function backtrack(state, target, total, choices, res) {
    // Ha a részhalmazösszeg egyenlő target-tel, rögzítjük a megoldást
    if (total === target) {
        res.push([...state]);
        return;
    }
    // Bejárjuk az összes választási lehetőséget
    for (let i = 0; i < choices.length; i++) {
        // Metszés: ha a részhalmazösszeg meghaladja a target-et, kihagyjuk ezt a választást
        if (total + choices[i] > target) {
            continue;
        }
        // Kísérlet: választás megtétele, az elemösszeg total frissítése
        state.push(choices[i]);
        // Folytatjuk a következő kiválasztási körrel
        backtrack(state, target, total + choices[i], choices, res);
        // Visszalépés: a választás visszavonása, visszaállítás az előző állapotra
        state.pop();
    }
}

/* Részhalmazösszeg I megoldása (ismétlődő részhalmazokat tartalmaz) */
function subsetSumINaive(nums, target) {
    const state = []; // Állapot (részhalmaz)
    const total = 0; // Részhalmazösszeg
    const res = []; // Eredménylista (részhalmazlista)
    backtrack(state, target, total, nums, res);
    return res;
}

/* Tesztkód */
const nums = [3, 4, 5];
const target = 9;
const res = subsetSumINaive(nums, target);
console.log(`Input array nums = ${JSON.stringify(nums)}, target = ${target}`);
console.log(`All subsets with sum equal to ${target} res = ${JSON.stringify(res)}`);
console.log('Please note that this method outputs results containing duplicate sets');
