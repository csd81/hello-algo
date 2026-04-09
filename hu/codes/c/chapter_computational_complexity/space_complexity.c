/**
 * File: space_complexity.c
 * Created Time: 2023-04-15
 * Author: Gonglja (glj0@outlook.com)
 */

#include "../utils/common.h"

/* Függvény */
int func() {
    // Bizonyos műveletek elvégzése
    return 0;
}

/* Konstans rend */
void constant(int n) {
    // Konstansok, változók, objektumok O(1) helyet foglalnak
    const int a = 0;
    int b = 0;
    int nums[1000];
    ListNode *node = newListNode(0);
    free(node);
    // A ciklusban lévő változók O(1) helyet foglalnak
    for (int i = 0; i < n; i++) {
        int c = 0;
    }
    // A ciklusban lévő függvények O(1) helyet foglalnak
    for (int i = 0; i < n; i++) {
        func();
    }
}

/* Hash tábla */
typedef struct {
    int key;
    int val;
    UT_hash_handle hh; // uthash.h segítségével megvalósítva
} HashTable;

/* Lineáris rend */
void linear(int n) {
    // n hosszú tömb O(n) helyet foglal
    int *nums = malloc(sizeof(int) * n);
    free(nums);

    // n hosszú lista O(n) helyet foglal
    ListNode **nodes = malloc(sizeof(ListNode *) * n);
    for (int i = 0; i < n; i++) {
        nodes[i] = newListNode(i);
    }
    // Memória felszabadítása
    for (int i = 0; i < n; i++) {
        free(nodes[i]);
    }
    free(nodes);

    // n hosszú hash tábla O(n) helyet foglal
    HashTable *h = NULL;
    for (int i = 0; i < n; i++) {
        HashTable *tmp = malloc(sizeof(HashTable));
        tmp->key = i;
        tmp->val = i;
        HASH_ADD_INT(h, key, tmp);
    }

    // Memória felszabadítása
    HashTable *curr, *tmp;
    HASH_ITER(hh, h, curr, tmp) {
        HASH_DEL(h, curr);
        free(curr);
    }
}

/* Lineáris rend (rekurzív megvalósítás) */
void linearRecur(int n) {
    printf("Recursion n = %d\r\n", n);
    if (n == 1)
        return;
    linearRecur(n - 1);
}

/* Exponenciális rend */
void quadratic(int n) {
    // 2D lista O(n^2) helyet foglal
    int **numMatrix = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        int *tmp = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            tmp[j] = 0;
        }
        numMatrix[i] = tmp;
    }

    // Memória felszabadítása
    for (int i = 0; i < n; i++) {
        free(numMatrix[i]);
    }
    free(numMatrix);
}

/* Négyzetes rend (rekurzív megvalósítás) */
int quadraticRecur(int n) {
    if (n <= 0)
        return 0;
    int *nums = malloc(sizeof(int) * n);
    printf("In recursion n = %d, nums length = %d\r\n", n, n);
    int res = quadraticRecur(n - 1);
    free(nums);
    return res;
}

/* Vezérlő kód */
TreeNode *buildTree(int n) {
    if (n == 0)
        return NULL;
    TreeNode *root = newTreeNode(0);
    root->left = buildTree(n - 1);
    root->right = buildTree(n - 1);
    return root;
}

/* Vezérlő kód */
int main() {
    int n = 5;
    // Konstans rend
    constant(n);
    // Lineáris rend
    linear(n);
    linearRecur(n);
    // Exponenciális rend
    quadratic(n);
    quadraticRecur(n);
    // Exponenciális rend
    TreeNode *root = buildTree(n);
    printTree(root);

    // Memória felszabadítása
    freeMemoryTree(root);

    return 0;
}
