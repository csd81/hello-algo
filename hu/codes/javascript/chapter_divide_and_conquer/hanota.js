/**
 * File: hanota.js
 * Created Time: 2023-07-30
 * Author: yuan0221 (yl1452491917@gmail.com)
 */

/* Egy korong mozgatása */
function move(src, tar) {
    // Kiveszünk egy korongot az src tetejéről
    const pan = src.pop();
    // A korongot a tar tetejére helyezzük
    tar.push(pan);
}

/* A Hanoi-torony f(i) feladatának megoldása */
function dfs(i, src, buf, tar) {
    // Ha csak egy korong maradt az src-n, közvetlenül a tar-ra mozgatjuk
    if (i === 1) {
        move(src, tar);
        return;
    }
    // Részprobléma f(i-1): a felső i-1 korongot a src-ről a buf-ra mozgatjuk a tar segítségével
    dfs(i - 1, src, tar, buf);
    // Részprobléma f(1): a maradék korongot a src-ről a tar-ra mozgatjuk
    move(src, tar);
    // Részprobléma f(i-1): a felső i-1 korongot a buf-ról a tar-ra mozgatjuk a src segítségével
    dfs(i - 1, buf, src, tar);
}

/* A Hanoi-torony feladatának megoldása */
function solveHanota(A, B, C) {
    const n = A.length;
    // A felső n korongot A-ról C-re mozgatjuk B segítségével
    dfs(n, A, B, C);
}

/* Tesztkód */
// A lista vége a rúd teteje
const A = [5, 4, 3, 2, 1];
const B = [];
const C = [];
console.log('In initial state:');
console.log(`A = ${JSON.stringify(A)}`);
console.log(`B = ${JSON.stringify(B)}`);
console.log(`C = ${JSON.stringify(C)}`);

solveHanota(A, B, C);

console.log('After disk movement is complete:');
console.log(`A = ${JSON.stringify(A)}`);
console.log(`B = ${JSON.stringify(B)}`);
console.log(`C = ${JSON.stringify(C)}`);
