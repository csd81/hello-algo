/**
 * File: array.js
 * Created Time: 2022-11-27
 * Author: IsChristina (christinaxia77@foxmail.com)
 */

/* Véletlenszerű hozzáférés elemhez */
function randomAccess(nums) {
    // Véletlenszerűen kiválasztunk egy számot a [0, nums.length) intervallumból
    const random_index = Math.floor(Math.random() * nums.length);
    // Lekérjük és visszaadjuk a véletlenszerű elemet
    const random_num = nums[random_index];
    return random_num;
}

/* Tömb hosszának bővítése */
// Megjegyzés: A JavaScript tömbje dinamikus tömb, közvetlenül bővíthető
// Tanulási célból ez a függvény a tömböt rögzített hosszúságú tömbként kezeli
function extend(nums, enlarge) {
    // Inicializálunk egy bővített hosszúságú tömböt
    const res = new Array(nums.length + enlarge).fill(0);
    // Az eredeti tömb összes elemét átmásoljuk az új tömbbe
    for (let i = 0; i < nums.length; i++) {
        res[i] = nums[i];
    }
    // Visszaadjuk a bővített új tömböt
    return res;
}

/* A num elem beszúrása a tömbben az index pozícióra */
function insert(nums, num, index) {
    // Az index pozíciótól kezdve az összes elemet egy hellyel hátra toljuk
    for (let i = nums.length - 1; i > index; i--) {
        nums[i] = nums[i - 1];
    }
    // A num értéket az index pozícióba írjuk
    nums[index] = num;
}

/* Az index pozícióban lévő elem törlése */
function remove(nums, index) {
    // Az index utáni összes elemet egy hellyel előre toljuk
    for (let i = index; i < nums.length - 1; i++) {
        nums[i] = nums[i + 1];
    }
}

/* Tömb bejárása */
function traverse(nums) {
    let count = 0;
    // Tömb bejárása index szerint
    for (let i = 0; i < nums.length; i++) {
        count += nums[i];
    }
    // Tömbelemek közvetlen bejárása
    for (const num of nums) {
        count += num;
    }
}

/* A megadott elem keresése a tömbben */
function find(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === target) return i;
    }
    return -1;
}

/* Tesztkód */
/* Tömb inicializálása */
const arr = new Array(5).fill(0);
console.log('Array arr =', arr);
let nums = [1, 3, 2, 5, 4];
console.log('Array nums =', nums);

/* Elem beszúrása */
let random_num = randomAccess(nums);
console.log('Get random element in nums', random_num);

/* Tömb bejárása */
nums = extend(nums, 3);
console.log('Extend array length to 8, get nums =', nums);

/* Elem beszúrása */
insert(nums, 6, 3);
console.log('Insert number 6 at index 3, get nums =', nums);

/* Elem törlése */
remove(nums, 2);
console.log('Remove element at index 2, get nums =', nums);

/* Tömb bejárása */
traverse(nums);

/* Elem keresése */
let index = find(nums, 3);
console.log('Find element 3 in nums, get index =', index);
