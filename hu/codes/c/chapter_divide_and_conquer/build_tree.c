/**
 * File : build_tree.c
 * Created Time: 2023-10-16
 * Author : lucas (superrat6@gmail.com)
 */

#include "../utils/common.h"

// Feltételezzük, hogy minden elem kisebb mint 1000
#define MAX_SIZE 1000

/* Bináris fa felépítése: oszd meg és uralkodj */
TreeNode *dfs(int *preorder, int *inorderMap, int i, int l, int r, int size) {
    // Leáll, ha a részfa intervalluma üres
    if (r - l < 0)
        return NULL;
    // Gyökércsomópont inicializálása
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = preorder[i];
    root->left = NULL;
    root->right = NULL;
    // m lekérdezése a bal és jobb részfa elválasztásához
    int m = inorderMap[preorder[i]];
    // Részprobléma: bal részfa felépítése
    root->left = dfs(preorder, inorderMap, i + 1, l, m - 1, size);
    // Részprobléma: jobb részfa felépítése
    root->right = dfs(preorder, inorderMap, i + 1 + m - l, m + 1, r, size);
    // A gyökércsomópont visszaadása
    return root;
}

/* Bináris fa felépítése */
TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    // Hash tábla inicializálása, az inorder elemeknek az indexekhez való leképezését tárolja
    int *inorderMap = (int *)malloc(sizeof(int) * MAX_SIZE);
    for (int i = 0; i < inorderSize; i++) {
        inorderMap[inorder[i]] = i;
    }
    TreeNode *root = dfs(preorder, inorderMap, 0, 0, inorderSize - 1, inorderSize);
    free(inorderMap);
    return root;
}

/* Vezérlő kód */
int main() {
    int preorder[] = {3, 9, 2, 1, 7};
    int inorder[] = {9, 3, 1, 2, 7};
    int preorderSize = sizeof(preorder) / sizeof(preorder[0]);
    int inorderSize = sizeof(inorder) / sizeof(inorder[0]);
    printf("Preorder traversal = ");
    printArray(preorder, preorderSize);
    printf("Inorder traversal = ");
    printArray(inorder, inorderSize);

    TreeNode *root = buildTree(preorder, preorderSize, inorder, inorderSize);
    printf("The constructed binary tree is:\n");
    printTree(root);

    freeMemoryTree(root);
    return 0;
}
