/**
 * File: worst_best_time_complexity.js
 * Created Time: 2023-01-05
 * Author: RiverTwilight (contact@rene.wang)
 */

/* Generál egy { 1, 2, ..., n } elemeket tartalmazó, kevert sorrendű tömböt */
function randomNumbers(n) {
    const nums = Array(n);
    // Generálja a nums = { 1, 2, 3, ..., n } tömböt
    for (let i = 0; i < n; i++) {
        nums[i] = i + 1;
    }
    // Véletlenszerűen összekeveri a tömbelemeket
    for (let i = 0; i < n; i++) {
        const r = Math.floor(Math.random() * (i + 1));
        const temp = nums[i];
        nums[i] = nums[r];
        nums[r] = temp;
    }
    return nums;
}

/* Megkeresi az 1-es szám indexét a nums tömbben */
function findOne(nums) {
    for (let i = 0; i < nums.length; i++) {
        // Ha az 1-es elem a tömb elején van, a legjobb esetbeli időbonyolultság O(1) érhető el
        // Ha az 1-es elem a tömb végén van, a legrosszabb esetbeli időbonyolultság O(n) érhető el
        if (nums[i] === 1) {
            return i;
        }
    }
    return -1;
}

/* Tesztkód */
for (let i = 0; i < 10; i++) {
    const n = 100;
    const nums = randomNumbers(n);
    const index = findOne(nums);
    console.log('\nArray [ 1, 2, ..., n ] after shuffling = [' + nums.join(', ') + ']');
    console.log('Index of number 1 is ' + index);
}
