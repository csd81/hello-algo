/**
 * File: permutations_ii.c
 * Created Time: 2023-10-17
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.h"

// Legfeljebb 1000 permutációt, maximum 1000-es elemértéket feltételezünk
#define MAX_SIZE 1000

/* Visszalépéses algoritmus: Permutációk II */
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
    bool duplicated[MAX_SIZE] = {false};
    for (int i = 0; i < choicesSize; i++) {
        int choice = choices[i];
        // Vágás: ne engedjük meg az elemek ismételt kiválasztását és az egyenlő elemek ismételt kiválasztását sem
        if (!selected[i] && !duplicated[choice]) {
            // Kísérlet: választás végrehajtása, állapot frissítése
            duplicated[choice] = true; // A kiválasztott elemérték rögzítése
            selected[i] = true;
            state[stateSize] = choice;
            // Továbblépés a következő kiválasztási körre
            backtrack(state, stateSize + 1, choices, choicesSize, selected, res, resSize);
            // Visszalépés: választás visszavonása, visszaállítás az előző állapotba
            selected[i] = false;
        }
    }
}

/* Permutációk II */
int **permutationsII(int *nums, int numsSize, int *returnSize) {
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
    int nums[] = {1, 1, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int **res = permutationsII(nums, numsSize, &returnSize);

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
