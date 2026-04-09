/**
 * File: iteration.js
 * Created Time: 2023-08-28
 * Author: Gaofer Chou (gaofer-chou@qq.com)
 */

/* for ciklus */
function forLoop(n) {
    let res = 0;
    // Összegzés: 1, 2, ..., n-1, n
    for (let i = 1; i <= n; i++) {
        res += i;
    }
    return res;
}

/* while ciklus */
function whileLoop(n) {
    let res = 0;
    let i = 1; // Feltételváltozó inicializálása
    // Összegzés: 1, 2, ..., n-1, n
    while (i <= n) {
        res += i;
        i++; // Feltételváltozó frissítése
    }
    return res;
}

/* while ciklus (két frissítéssel) */
function whileLoopII(n) {
    let res = 0;
    let i = 1; // Feltételváltozó inicializálása
    // Összegzés: 1, 4, 10, ...
    while (i <= n) {
        res += i;
        // Feltételváltozó frissítése
        i++;
        i *= 2;
    }
    return res;
}

/* Egymásba ágyazott for ciklus */
function nestedForLoop(n) {
    let res = '';
    // i ciklus: 1, 2, ..., n-1, n
    for (let i = 1; i <= n; i++) {
        // j ciklus: 1, 2, ..., n-1, n
        for (let j = 1; j <= n; j++) {
            res += `(${i}, ${j}), `;
        }
    }
    return res;
}

/* Tesztkód */
const n = 5;
let res;

res = forLoop(n);
console.log(`For loop sum result res = ${res}`);

res = whileLoop(n);
console.log(`While loop sum result res = ${res}`);

res = whileLoopII(n);
console.log(`While loop (two updates) sum result res = ${res}`);

const resStr = nestedForLoop(n);
console.log(`Nested for loop traversal result ${resStr}`);
