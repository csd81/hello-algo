/**
 * File: binary_search_recur.c
 * Created Time: 2023-10-01
 * Author: Zuoxun (845242523@qq.com)
 */

#include "../utils/common.h"

/* Bináris keresés: f(i, j) részprobléma */
int dfs(int nums[], int target, int i, int j) {
    // Ha az intervallum üres, nincs célelem, visszaad -1-et
    if (i > j) {
        return -1;
    }
    // Középpont index m kiszámítása
    int m = (i + j) / 2;
    if (nums[m] < target) {
        // Rekurzió az f(m+1, j) részproblémára
        return dfs(nums, target, m + 1, j);
    } else if (nums[m] > target) {
        // Rekurzió az f(i, m-1) részproblémára
        return dfs(nums, target, i, m - 1);
    } else {
        // Célelem megtalálva, visszaadja az indexét
        return m;
    }
}

/* Bináris keresés */
int binarySearch(int nums[], int target, int numsSize) {
    int n = numsSize;
    // Az f(0, n-1) részprobléma megoldása
    return dfs(nums, target, 0, n - 1);
}

/* Vezérlő kód */
int main() {
    int target = 6;
    int nums[] = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    // Bináris keresés (mindkét oldalról zárt intervallum)
    int index = binarySearch(nums, target, numsSize);
    printf("Index of target element 6 = %d\n", index);

    return 0;
}
