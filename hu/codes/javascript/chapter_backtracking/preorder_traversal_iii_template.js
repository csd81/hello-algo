/**
 * File: preorder_traversal_iii_template.js
 * Created Time: 2023-05-09
 * Author: Justin (xiefahit@gmail.com)
 */

const { arrToTree } = require('../modules/TreeNode');
const { printTree } = require('../modules/PrintUtil');

/* Ellenőrzi, hogy a jelenlegi állapot megoldás-e */
function isSolution(state) {
    return state && state[state.length - 1]?.val === 7;
}

/* Megoldás rögzítése */
function recordSolution(state, res) {
    res.push([...state]);
}

/* Ellenőrzi, hogy a választás érvényes-e a jelenlegi állapotban */
function isValid(state, choice) {
    return choice !== null && choice.val !== 3;
}

/* Állapot frissítése */
function makeChoice(state, choice) {
    state.push(choice);
}

/* Állapot visszaállítása */
function undoChoice(state) {
    state.pop();
}

/* Visszalépéses algoritmus: 3. példa */
function backtrack(state, choices, res) {
    // Ellenőrzi, hogy megoldás-e
    if (isSolution(state)) {
        // Megoldás rögzítése
        recordSolution(state, res);
    }
    // Bejárjuk az összes választási lehetőséget
    for (const choice of choices) {
        // Metszés: ellenőrzi, hogy a választás érvényes-e
        if (isValid(state, choice)) {
            // Kísérlet: választás megtétele, állapot frissítése
            makeChoice(state, choice);
            // Folytatjuk a következő kiválasztási körrel
            backtrack(state, [choice.left, choice.right], res);
            // Visszalépés: a választás visszavonása, visszaállítás az előző állapotra
            undoChoice(state);
        }
    }
}

// Tesztkód
const root = arrToTree([1, 7, 3, 4, 5, 6, 7]);
console.log('\nInitialize binary tree');
printTree(root);

// Visszalépéses algoritmus
const res = [];
backtrack([], [root], res);

console.log('\nOutput all paths from root node to node 7, requiring paths do not include nodes with value 3');
res.forEach((path) => {
    console.log(path.map((node) => node.val));
});
