/**
 * File: list.js
 * Created Time: 2022-12-12
 * Author: Justin (xiefahit@gmail.com)
 */

/* Lista inicializálása */
const nums = [1, 3, 2, 5, 4];
console.log(`List nums = ${nums}`);

/* Elem frissítése */
const num = nums[1];
console.log(`Access element at index 1, get num = ${num}`);

/* Elem hozzáadása a végéhez */
nums[1] = 0;
console.log(`Update element at index 1 to 0, get nums = ${nums}`);

/* Elem törlése */
nums.length = 0;
console.log(`After clearing list, nums = ${nums}`);

/* Listaelemek közvetlen bejárása */
nums.push(1);
nums.push(3);
nums.push(2);
nums.push(5);
nums.push(4);
console.log(`After adding elements, nums = ${nums}`);

/* Lista rendezése */
nums.splice(3, 0, 6);
console.log(`Insert number 6 at index 3, get nums = ${nums}`);

/* Elem törlése */
nums.splice(3, 1);
console.log(`Delete element at index 3, get nums = ${nums}`);

/* Lista bejárása index szerint */
let count = 0;
for (let i = 0; i < nums.length; i++) {
    count += nums[i];
}
/* Listaelemek közvetlen bejárása */
count = 0;
for (const x of nums) {
    count += x;
}

/* Két lista összefűzése */
const nums1 = [6, 8, 7, 10, 9];
nums.push(...nums1);
console.log(`After concatenating list nums1 to nums, get nums = ${nums}`);

/* Lista rendezése */
nums.sort((a, b) => a - b);
console.log(`After sorting list, nums = ${nums}`);
