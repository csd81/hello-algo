/**
 * File: preorder_traversal_iii_compact.js
 * Created Time: 2023-05-09
 * Author: Justin (xiefahit@gmail.com)
 */

const { arrToTree } = require('../modules/TreeNode');
const { printTree } = require('../modules/PrintUtil');

/* Előrendű bejárás: 3. példa */
function preOrder(root, path, res) {
    // Metszés
    if (root === null || root.val === 3) {
        return;
    }
    // Kísérlet
    path.push(root);
    if (root.val === 7) {
        // Megoldás rögzítése
        res.push([...path]);
    }
    preOrder(root.left, path, res);
    preOrder(root.right, path, res);
    // Visszalépés
    path.pop();
}

// Tesztkód
const root = arrToTree([1, 7, 3, 4, 5, 6, 7]);
console.log('\nInitialize binary tree');
printTree(root);

// Előrendű bejárás
const path = [];
const res = [];
preOrder(root, path, res);

console.log('\nOutput all paths from root node to node 7, paths do not include nodes with value 3');
res.forEach((path) => {
    console.log(path.map((node) => node.val));
});
