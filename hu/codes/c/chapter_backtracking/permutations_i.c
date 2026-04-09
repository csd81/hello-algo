/**
 * File: permutations_i.c
 * Created Time: 2023-06-04
 * Author: Gonglja (glj0@outlook.com), krahets (krahets@163.com)
 */

#include "../utils/common.h"

// Legfeljebb 1000 permutációt feltételezünk
#define MAX_SIZE 1000

/* Visszalépéses algoritmus: Permutációk I */
void backtrack(int *state, int stateSize, int *choices, int choicesSize, bool *selected, int **res, int *resSize) {
    // Ha az állapot hossza egyenlő az elemek számával, rögzítse a megoldást
    if (stateSize == choicesSize) {
        res[*resSize] = (int *)malloc(choicesSize * sizeof(int));
        for (int i = 0; i < choicesSize; i++) {
            res[*resSize][i] = state[i];
        }
        (*resSize)++;
        return;
    }
    // Az összes lehetőség bejárása
    for (int i = 0; i < choicesSize; i++) {
        int choice = choices[i];
        // Vágás: ne engedjük meg az elemek ismételt kiválasztását
        if (!selected[i]) {
            // Kísérlet: választás végrehajtása, állapot frissítése
            selected[i] = true;
            state[stateSize] = choice;
            // Továbblépés a következő kiválasztási körre
            backtrack(state, stateSize + 1, choices, choicesSize, selected, res, resSize);
            // Visszalépés: választás visszavonása, visszaállítás az előző állapotba
            selected[i] = false;
        }
    }
}

/* Permutációk I */
int **permutationsI(int *nums, int numsSize, int *returnSize) {
    int *state = (int *)malloc(numsSize * sizeof(int));
    bool *selected = (bool *)malloc(numsSize * sizeof(bool));
    for (int i = 0; i < numsSize; i++) {
        selected[i] = false;
    }
    int **res = (int **)malloc(MAX_SIZE * sizeof(int *));
    *returnSize = 0;

    backtrack(state, 0, nums, numsSize, selected, res, returnSize);

    free(state);
    free(selected);

    return res;
}

/* Vezérlő kód */
int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int **res = permutationsI(nums, numsSize, &returnSize);

    printf("Input array nums = ");
    printArray(nums, numsSize);
    printf("\nAll permutations res = \n");
    for (int i = 0; i < returnSize; i++) {
        printArray(res[i], numsSize);
    }

    // Memória felszabadítása
    for (int i = 0; i < returnSize; i++) {
        free(res[i]);
    }
    free(res);

    return 0;
}
