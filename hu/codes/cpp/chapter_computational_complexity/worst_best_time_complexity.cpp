/**
 * File: worst_best_time_complexity.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* { 1, 2, ..., n } elemekből álló, véletlenszerűen összekevert tömb generálása */
vector<int> randomNumbers(int n) {
    vector<int> nums(n);
    // nums = { 1, 2, 3, ..., n } tömb generálása
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }
    // Rendszer idő használata véletlenszerű mag generálásához
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    // Tömb elemeinek véletlenszerű összekeverése
    shuffle(nums.begin(), nums.end(), default_random_engine(seed));
    return nums;
}

/* Az 1-es szám indexének keresése a nums tömbben */
int findOne(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        // Ha az 1-es elem a tömb elején van, a legjobb időbonyolultság O(1) érhető el
        // Ha az 1-es elem a tömb végén van, a legrosszabb időbonyolultság O(n) érhető el
        if (nums[i] == 1)
            return i;
    }
    return -1;
}

/* Főprogram */
int main() {
    for (int i = 0; i < 1000; i++) {
        int n = 100;
        vector<int> nums = randomNumbers(n);
        int index = findOne(nums);
        cout << "\nArray [ 1, 2, ..., n ] after shuffling = ";
        printVector(nums);
        cout << "Index of number 1 is " << index << endl;
    }
    return 0;
}
