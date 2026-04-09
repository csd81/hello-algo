/**
 * File: preorder_traversal_iii_compact.c
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

/* Előrendű bejárás: 3. példa */
void preOrder(TreeNode *root) {
    // Vágás
    if (root == NULL || root->val == 3) {
        return;
    }
    // Kísérlet
    path[pathSize++] = root;
    if (root->val == 7) {
        // Megoldás rögzítése
        for (int i = 0; i < pathSize; i++) {
            res[resSize][i] = path[i];
        }
        resSize++;
    }
    preOrder(root->left);
    preOrder(root->right);
    // Visszalépés
    pathSize--;
}

/* Vezérlő kód */
int main() {
    int arr[] = {1, 7, 3, 4, 5, 6, 7};
    TreeNode *root = arrayToTree(arr, sizeof(arr) / sizeof(arr[0]));
    printf("\nInitialize binary tree\n");
    printTree(root);

    // Előrendű bejárás
    preOrder(root);

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
