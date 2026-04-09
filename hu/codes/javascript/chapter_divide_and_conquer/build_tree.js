/**
 * File: build_tree.js
 * Created Time: 2023-07-30
 * Author: yuan0221 (yl1452491917@gmail.com)
 */

const { printTree } = require('../modules/PrintUtil');
const { TreeNode } = require('../modules/TreeNode');

/* Bináris fa felépítése: oszd meg és uralkodj */
function dfs(preorder, inorderMap, i, l, r) {
    // Ha a részfa intervalluma üres, leállunk
    if (r - l < 0) return null;
    // A gyökércsomópont inicializálása
    const root = new TreeNode(preorder[i]);
    // m lekérdezése a bal és jobb részfák szétválasztásához
    const m = inorderMap.get(preorder[i]);
    // Részprobléma: bal részfa felépítése
    root.left = dfs(preorder, inorderMap, i + 1, l, m - 1);
    // Részprobléma: jobb részfa felépítése
    root.right = dfs(preorder, inorderMap, i + 1 + m - l, m + 1, r);
    // A gyökércsomópontot visszaadjuk
    return root;
}

/* Bináris fa felépítése */
function buildTree(preorder, inorder) {
    // Hash tábla inicializálása, az inorder elemek és indexek leképezésének tárolása
    let inorderMap = new Map();
    for (let i = 0; i < inorder.length; i++) {
        inorderMap.set(inorder[i], i);
    }
    const root = dfs(preorder, inorderMap, 0, 0, inorder.length - 1);
    return root;
}

/* Tesztkód */
const preorder = [3, 9, 2, 1, 7];
const inorder = [9, 3, 1, 2, 7];
console.log('Preorder traversal = ' + JSON.stringify(preorder));
console.log('Inorder traversal = ' + JSON.stringify(inorder));
const root = buildTree(preorder, inorder);
console.log('The constructed binary tree is:');
printTree(root);
