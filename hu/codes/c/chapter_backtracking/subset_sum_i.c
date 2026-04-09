/**
 * File: subset_sum_i.c
 * Created Time: 2023-07-29
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
void backtrack(int target, int *choices, int choicesSize, int start) {
    // Ha a részhalmazok összege egyenlő a céllal, rögzítse a megoldást
    if (target == 0) {
        for (int i = 0; i < stateSize; ++i) {
            res[resSize][i] = state[i];
        }
        resColSizes[resSize++] = stateSize;
        return;
    }
    // Az összes lehetőség bejárása
    // 2. vágás: a start-tól kezdve bejárva elkerüljük a duplikált részhalmazok generálását
    for (int i = start; i < choicesSize; i++) {
        // 1. vágás: ha a részhalmazok összege meghaladja a célt, a ciklus azonnal véget ér
        // Ez azért lehetséges, mert a tömb rendezett, és a későbbi elemek nagyobbak, így a részhalmazok összege biztosan meghaladja a célt
        if (target - choices[i] < 0) {
            break;
        }
        // Kísérlet: választás végrehajtása, cél és start frissítése
        state[stateSize] = choices[i];
        stateSize++;
        // Továbblépés a következő kiválasztási körre
        backtrack(target - choices[i], choices, choicesSize, i);
        // Visszalépés: választás visszavonása, visszaállítás az előző állapotba
        stateSize--;
    }
}

/* Összehasonlító függvény */
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

/* Részhalmazok összege I megoldása */
void subsetSumI(int *nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp); // nums rendezése
    int start = 0;                           // Bejárás kezdőpontja
    backtrack(target, nums, numsSize, start);
}

/* Vezérlő kód */
int main() {
    int nums[] = {3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;

    subsetSumI(nums, numsSize, target);

    printf("Input array nums = ");
    printArray(nums, numsSize);
    printf("target = %d\n", target);
    printf("All subsets with sum equal to %d res = \n", target);
    for (int i = 0; i < resSize; ++i) {
        printArray(res[i], resColSizes[i]);
    }

    return 0;
}
