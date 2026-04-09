/**
 * File: worst_best_time_complexity.c
 * Created Time: 2023-01-03
 * Author: codingonion (coderonion@gmail.com)
 */

#include "../utils/common.h"

/* { 1, 2, ..., n } elemeket tartalmazó, véletlenszerűen kevert tömb generálása */
int *randomNumbers(int n) {
    // Halommemória foglalása (1D változó hosszú tömb létrehozása: n db int típusú elem)
    int *nums = (int *)malloc(n * sizeof(int));
    // nums = { 1, 2, 3, ..., n } tömb generálása
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }
    // Tömbelemek véletlenszerű megkeverése
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    return nums;
}

/* Az 1-es szám indexének keresése a nums tömbben */
int findOne(int *nums, int n) {
    for (int i = 0; i < n; i++) {
        // Ha az 1-es elem a tömb elején van, a legjobb időbonyolultság O(1) teljesül
        // Ha az 1-es elem a tömb végén van, a legrosszabb időbonyolultság O(n) teljesül
        if (nums[i] == 1)
            return i;
    }
    return -1;
}

/* Vezérlő kód */
int main(int argc, char *argv[]) {
    // Véletlenszám generátor inicializálása
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++) {
        int n = 100;
        int *nums = randomNumbers(n);
        int index = findOne(nums, n);
        printf("\nArray [ 1, 2, ..., n ] after shuffling = ");
        printArray(nums, n);
        printf("Index of number 1 is %d\n", index);
        // Halommemória felszabadítása
        if (nums != NULL) {
            free(nums);
            nums = NULL;
        }
    }

    return 0;
}
