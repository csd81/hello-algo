/**
 * File: binary_search_recur.cpp
 * Created Time: 2023-07-17
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Bináris keresés: f(i, j) feladat */
int dfs(vector<int> &nums, int target, int i, int j) {
    // Ha az intervallum üres, nincs target elem, -1-et adunk vissza
    if (i > j) {
        return -1;
    }
    // A középpont indexének kiszámítása
    int m = (i + j) / 2;
    if (nums[m] < target) {
        // f(m+1, j) részfeladat rekurzív megoldása
        return dfs(nums, target, m + 1, j);
    } else if (nums[m] > target) {
        // f(i, m-1) részfeladat rekurzív megoldása
        return dfs(nums, target, i, m - 1);
    } else {
        // Megtaláltuk a target elemet, visszaadjuk az indexét
        return m;
    }
}

/* Bináris keresés */
int binarySearch(vector<int> &nums, int target) {
    int n = nums.size();
    // f(0, n-1) feladat megoldása
    return dfs(nums, target, 0, n - 1);
}

/* Főprogram */
int main() {
    int target = 6;
    vector<int> nums = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};

    // Bináris keresés (mindkét oldalon zárt intervallum)
    int index = binarySearch(nums, target);
    cout << "Index of target element 6 = " << index << endl;

    return 0;
}