/**
 * File: preorder_traversal_iii_template.c
 * Created Time: 2023-06-04
 * Author: Gonglja (glj0@outlook.com)
 */

#include "../utils/common.h"

// Feltételezzük, hogy az útvonal és az eredmény hossza nem haladja meg a 100-at
#define MAX_SIZE 100
#define MAX_RES_SIZE 100

TreeNode *path[MAX_SIZE];
TreeNode *res[MAX_RES_SIZE][MAX_SIZE];
int pathSize = 0, resSize = 0;

/* Ellenőrzi, hogy az aktuális állapot megoldás-e */
bool isSolution(void) {
    return pathSize > 0 && path[pathSize - 1]->val == 7;
}

/* Megoldás rögzítése */
void recordSolution(void) {
    for (int i = 0; i < pathSize; i++) {
        res[resSize][i] = path[i];
    }
    resSize++;
}

/* Ellenőrzi, hogy a választás érvényes-e az aktuális állapotban */
bool isValid(TreeNode *choice) {
    return choice != NULL && choice->val != 3;
}

/* Állapot frissítése */
void makeChoice(TreeNode *choice) {
    path[pathSize++] = choice;
}

/* Állapot visszaállítása */
void undoChoice(void) {
    pathSize--;
}

/* Visszalépéses algoritmus: 3. példa */
void backtrack(TreeNode *choices[2]) {
    // Ellenőrzés, hogy megoldás-e
    if (isSolution()) {
        // Megoldás rögzítése
        recordSolution();
    }
    // Az összes lehetőség bejárása
    for (int i = 0; i < 2; i++) {
        TreeNode *choice = choices[i];
        // Vágás: ellenőrzi, hogy a választás érvényes-e
        if (isValid(choice)) {
            // Kísérlet: választás végrehajtása, állapot frissítése
            makeChoice(choice);
            // Továbblépés a következő kiválasztási körre
            TreeNode *nextChoices[2] = {choice->left, choice->right};
            backtrack(nextChoices);
            // Visszalépés: választás visszavonása, visszaállítás az előző állapotba
            undoChoice();
        }
    }
}

/* Vezérlő kód */
int main() {
    int arr[] = {1, 7, 3, 4, 5, 6, 7};
    TreeNode *root = arrayToTree(arr, sizeof(arr) / sizeof(arr[0]));
    printf("\nInitialize binary tree\n");
    printTree(root);

    // Visszalépéses algoritmus
    TreeNode *choices[2] = {root, NULL};
    backtrack(choices);

    printf("\nOutput all paths from root to node 7, excluding nodes with value 3\n");
    for (int i = 0; i < resSize; ++i) {
        int *vals = malloc(MAX_SIZE * sizeof(int));
        int size = 0;
        for (int j = 0; res[i][j] != NULL; ++j) {
            vals[size++] = res[i][j]->val;
        }
        printArray(vals, size);
        free(vals);
    }

    // Memória felszabadítása
    freeMemoryTree(root);
    return 0;
}
