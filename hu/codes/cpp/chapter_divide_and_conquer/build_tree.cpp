/**
 * File: build_tree.cpp
 * Created Time: 2023-07-17
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Bináris fa felépítése: oszd meg és uralkodj */
TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorderMap, int i, int l, int r) {
    // Leáll, ha a részfa intervalluma üres
    if (r - l < 0)
        return NULL;
    // A gyökércsomópont inicializálása
    TreeNode *root = new TreeNode(preorder[i]);
    // m lekérdezése a bal és jobb részfák szétválasztásához
    int m = inorderMap[preorder[i]];
    // Részfeladat: bal részfa felépítése
    root->left = dfs(preorder, inorderMap, i + 1, l, m - 1);
    // Részfeladat: jobb részfa felépítése
    root->right = dfs(preorder, inorderMap, i + 1 + m - l, m + 1, r);
    // A gyökércsomópont visszaadása
    return root;
}

/* Bináris fa felépítése */
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // Hash tábla inicializálása, az inorder elemek és indexek leképezésének tárolása
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    TreeNode *root = dfs(preorder, inorderMap, 0, 0, inorder.size() - 1);
    return root;
}

/* Driver Code */
int main() {
    vector<int> preorder = {3, 9, 2, 1, 7};
    vector<int> inorder = {9, 3, 1, 2, 7};
    cout << "Preorder traversal = ";
    printVector(preorder);
    cout << "Inorder traversal = ";
    printVector(inorder);

    TreeNode *root = buildTree(preorder, inorder);
    cout << "The constructed binary tree is:\n";
    printTree(root);

    return 0;
}
