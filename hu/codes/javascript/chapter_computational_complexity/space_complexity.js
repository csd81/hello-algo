/**
 * File: space_complexity.js
 * Created Time: 2023-02-05
 * Author: Justin (xiefahit@gmail.com)
 */

const { ListNode } = require('../modules/ListNode');
const { TreeNode } = require('../modules/TreeNode');
const { printTree } = require('../modules/PrintUtil');

/* Függvény */
function constFunc() {
    // Néhány műveletet hajt végre
    return 0;
}

/* Konstans rend */
function constant(n) {
    // Konstansok, változók, objektumok O(1) helyet foglalnak
    const a = 0;
    const b = 0;
    const nums = new Array(10000);
    const node = new ListNode(0);
    // A ciklusban lévő változók O(1) helyet foglalnak
    for (let i = 0; i < n; i++) {
        const c = 0;
    }
    // A ciklusban lévő függvények O(1) helyet foglalnak
    for (let i = 0; i < n; i++) {
        constFunc();
    }
}

/* Lineáris rend */
function linear(n) {
    // n hosszúságú tömb O(n) helyet használ
    const nums = new Array(n);
    // n hosszúságú lista O(n) helyet foglal
    const nodes = [];
    for (let i = 0; i < n; i++) {
        nodes.push(new ListNode(i));
    }
    // n hosszúságú hash tábla O(n) helyet foglal
    const map = new Map();
    for (let i = 0; i < n; i++) {
        map.set(i, i.toString());
    }
}

/* Lineáris rend (rekurzív implementáció) */
function linearRecur(n) {
    console.log(`Recursion n = ${n}`);
    if (n === 1) return;
    linearRecur(n - 1);
}

/* Exponenciális rend */
function quadratic(n) {
    // A mátrix O(n^2) helyet használ
    const numMatrix = Array(n)
        .fill(null)
        .map(() => Array(n).fill(null));
    // A 2D lista O(n^2) helyet használ
    const numList = [];
    for (let i = 0; i < n; i++) {
        const tmp = [];
        for (let j = 0; j < n; j++) {
            tmp.push(0);
        }
        numList.push(tmp);
    }
}

/* Négyzetes rend (rekurzív implementáció) */
function quadraticRecur(n) {
    if (n <= 0) return 0;
    const nums = new Array(n);
    console.log(`In recursion n = ${n}, nums length = ${nums.length}`);
    return quadraticRecur(n - 1);
}

/* Tesztkód */
function buildTree(n) {
    if (n === 0) return null;
    const root = new TreeNode(0);
    root.left = buildTree(n - 1);
    root.right = buildTree(n - 1);
    return root;
}

/* Tesztkód */
const n = 5;
// Konstans rend
constant(n);
// Lineáris rend
linear(n);
linearRecur(n);
// Exponenciális rend
quadratic(n);
quadraticRecur(n);
// Exponenciális rend
const root = buildTree(n);
printTree(root);
