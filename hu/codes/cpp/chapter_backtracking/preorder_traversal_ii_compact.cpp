/**
 * File: preorder_traversal_ii_compact.cpp
 * Created Time: 2023-04-16
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

vector<TreeNode *> path;
vector<vector<TreeNode *>> res;

/* Preorder bejárás: 2. példa */
void preOrder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    // Próbálkozás
    path.push_back(root);
    if (root->val == 7) {
        // Megoldás rögzítése
        res.push_back(path);
    }
    preOrder(root->left);
    preOrder(root->right);
    // Visszalépés
    path.pop_back();
}

/* Főprogram */
int main() {
    TreeNode *root = vectorToTree(vector<int>{1, 7, 3, 4, 5, 6, 7});
    cout << "\nInitialize binary tree" << endl;
    printTree(root);

    // Preorder bejárás
    preOrder(root);

    cout << "\nOutput all paths from root node to node 7" << endl;
    for (vector<TreeNode *> &path : res) {
        vector<int> vals;
        for (TreeNode *node : path) {
            vals.push_back(node->val);
        }
        printVector(vals);
    }
}
