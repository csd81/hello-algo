/**
 * File: binary_search_recur.js
 * Created Time: 2023-07-30
 * Author: yuan0221 (yl1452491917@gmail.com)
 */

/* Bináris keresés: f(i, j) feladat */
function dfs(nums, target, i, j) {
    // Ha az intervallum üres, a célelem nem található, visszaadjuk -1-et
    if (i > j) {
        return -1;
    }
    // Kiszámítjuk a középső indexet m
    const m = i + ((j - i) >> 1);
    if (nums[m] < target) {
        // Rekurzió az f(m+1, j) részproblémára
        return dfs(nums, target, m + 1, j);
    } else if (nums[m] > target) {
        // Rekurzió az f(i, m-1) részproblémára
        return dfs(nums, target, i, m - 1);
    } else {
        // Megtaláltuk a célelemet, visszaadjuk az indexét
        return m;
    }
}

/* Bináris keresés */
function binarySearch(nums, target) {
    const n = nums.length;
    // Megoldjuk az f(0, n-1) feladatot
    return dfs(nums, target, 0, n - 1);
}

/* Tesztkód */
const target = 6;
const nums = [1, 3, 6, 8, 12, 15, 23, 26, 31, 35];
// Bináris keresés (mindkét oldalon zárt intervallum)
const index = binarySearch(nums, target);
console.log(`Index of target element 6 is ${index}`);
