/**
 * File: subset_sum_i_naive.c
 * Created Time: 2023-07-28
 * Author: Gonglja (glj0@outlook.com)
 */

#include "../utils/common.h"

#define MAX_SIZE 100
#define MAX_RES_SIZE 100

// Állapot (részhalmaz)
int state[MAX_SIZE];
int stateSize = 0;

// Eredménylista (részhalmaz lista)
int res[MAX_RES_SIZE][MAX_SIZE];
int resColSizes[MAX_RES_SIZE];
int resSize = 0;

/* Visszalépéses algoritmus: Részhalmazok összege I */
void backtrack(int target, int total, int *choices, int choicesSize) {
    // Ha a részhalmazok összege egyenlő a céllal, rögzítse a megoldást
    if (total == target) {
        for (int i = 0; i < stateSize; i++) {
            res[resSize][i] = state[i];
        }
        resColSizes[resSize++] = stateSize;
        return;
    }
    // Az összes lehetőség bejárása
    for (int i = 0; i < choicesSize; i++) {
        // Vágás: ha a részhalmazok összege meghaladja a célt, hagyja ki ezt a lehetőséget
        if (total + choices[i] > target) {
            continue;
        }
        // Kísérlet: választás végrehajtása, az elemek összegének (total) frissítése
        state[stateSize++] = choices[i];
        // Továbblépés a következő kiválasztási körre
        backtrack(target, total + choices[i], choices, choicesSize);
        // Visszalépés: választás visszavonása, visszaállítás az előző állapotba
        stateSize--;
    }
}

/* Részhalmazok összege I megoldása (duplikált részhalmazokat is tartalmaz) */
void subsetSumINaive(int *nums, int numsSize, int target) {
    resSize = 0; // Megoldások számának inicializálása 0-ra
    backtrack(target, 0, nums, numsSize);
}

/* Vezérlő kód */
int main() {
    int nums[] = {3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    subsetSumINaive(nums, numsSize, target);

    printf("Input array nums = ");
    printArray(nums, numsSize);
    printf("target = %d\n", target);
    printf("All subsets with sum equal to %d res = \n", target);
    for (int i = 0; i < resSize; i++) {
        printArray(res[i], resColSizes[i]);
    }

    return 0;
}
