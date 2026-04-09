/**
 * File: preorder_traversal_i_compact.c
 * Created Time: 2023-05-10
 * Author: Gonglja (glj0@outlook.com)
 */

#include "../utils/common.h"

// Feltételezzük, hogy az eredmény hossza nem haladja meg a 100-at
#define MAX_SIZE 100

TreeNode *res[MAX_SIZE];
int resSize = 0;

/* Előrendű bejárás: 1. példa */
void preOrder(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    if (root->val == 7) {
        // Megoldás rögzítése
        res[resSize++] = root;
    }
    preOrder(root->left);
    preOrder(root->right);
}

/* Vezérlő kód */
int main() {
    int arr[] = {1, 7, 3, 4, 5, 6, 7};
    TreeNode *root = arrayToTree(arr, sizeof(arr) / sizeof(arr[0]));
    printf("\nInitialize binary tree\n");
    printTree(root);

    // Előrendű bejárás
    preOrder(root);

    printf("\nOutput all nodes with value 7\n");
    int *vals = malloc(resSize * sizeof(int));
    for (int i = 0; i < resSize; i++) {
        vals[i] = res[i]->val;
    }
    printArray(vals, resSize);

    // Memória felszabadítása
    freeMemoryTree(root);
    free(vals);
    return 0;
}
