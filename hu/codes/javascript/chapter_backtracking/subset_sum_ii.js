/**
 * File: subset_sum_ii.js
 * Created Time: 2023-07-30
 * Author: yuan0221 (yl1452491917@gmail.com)
 */

/* Visszalépéses algoritmus: Részhalmazösszeg II */
function backtrack(state, target, choices, start, res) {
    // Ha a részhalmazösszeg egyenlő target-tel, rögzítjük a megoldást
    if (target === 0) {
        res.push([...state]);
        return;
    }
    // Bejárjuk az összes választási lehetőséget
    // 2. metszés: start-tól kezdve járjuk be az ismétlődő részhalmazok elkerülése érdekében
    // 3. metszés: start-tól kezdve járjuk be az ugyanazon elem ismételt kiválasztásának elkerülése érdekében
    for (let i = start; i < choices.length; i++) {
        // 1. metszés: ha a részhalmazösszeg meghaladja a target-et, a ciklust közvetlenül befejezzük
        // Mivel a tömb rendezett, a későbbi elemek nagyobbak, így a részhalmazösszeg biztosan meghaladja a target-et
        if (target - choices[i] < 0) {
            break;
        }
        // 4. metszés: ha ez az elem egyenlő a bal szomszéddal, ez a keresési ág duplikált, kihagyjuk
        if (i > start && choices[i] === choices[i - 1]) {
            continue;
        }
        // Kísérlet: választás megtétele, target és start frissítése
        state.push(choices[i]);
        // Folytatjuk a következő kiválasztási körrel
        backtrack(state, target - choices[i], choices, i + 1, res);
        // Visszalépés: a választás visszavonása, visszaállítás az előző állapotra
        state.pop();
    }
}

/* Részhalmazösszeg II megoldása */
function subsetSumII(nums, target) {
    const state = []; // Állapot (részhalmaz)
    nums.sort((a, b) => a - b); // nums rendezése
    const start = 0; // Bejárás kezdőpontja
    const res = []; // Eredménylista (részhalmazlista)
    backtrack(state, target, nums, start, res);
    return res;
}

/* Tesztkód */
const nums = [4, 4, 5];
const target = 9;
const res = subsetSumII(nums, target);
console.log(`Input array nums = ${JSON.stringify(nums)}, target = ${target}`);
console.log(`All subsets with sum equal to ${target} res = ${JSON.stringify(res)}`);
