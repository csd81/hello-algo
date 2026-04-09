/**
 * File: space_complexity.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Függvény */
int func() {
    // Néhány művelet végrehajtása
    return 0;
}

/* Konstans rend */
void constant(int n) {
    // Konstansok, változók, objektumok O(1) helyet foglalnak
    const int a = 0;
    int b = 0;
    vector<int> nums(10000);
    ListNode node(0);
    // A ciklus változói O(1) helyet foglalnak
    for (int i = 0; i < n; i++) {
        int c = 0;
    }
    // A ciklusban meghívott függvények O(1) helyet foglalnak
    for (int i = 0; i < n; i++) {
        func();
    }
}

/* Lineáris rend */
void linear(int n) {
    // n hosszúságú tömb O(n) helyet foglal
    vector<int> nums(n);
    // n hosszúságú lista O(n) helyet foglal
    vector<ListNode> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(ListNode(i));
    }
    // n hosszúságú hash tábla O(n) helyet foglal
    unordered_map<int, string> map;
    for (int i = 0; i < n; i++) {
        map[i] = to_string(i);
    }
}

/* Lineáris rend (rekurzív implementáció) */
void linearRecur(int n) {
    cout << "Recursion n = " << n << endl;
    if (n == 1)
        return;
    linearRecur(n - 1);
}

/* Négyzetes rend */
void quadratic(int n) {
    // 2D lista O(n^2) helyet foglal
    vector<vector<int>> numMatrix;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            tmp.push_back(0);
        }
        numMatrix.push_back(tmp);
    }
}

/* Négyzetes rend (rekurzív implementáció) */
int quadraticRecur(int n) {
    if (n <= 0)
        return 0;
    vector<int> nums(n);
    cout << "In recursion n = " << n << ", nums length = " << nums.size() << endl;
    return quadraticRecur(n - 1);
}

/* Fa felépítése (exponenciális rend) */
TreeNode *buildTree(int n) {
    if (n == 0)
        return nullptr;
    TreeNode *root = new TreeNode(0);
    root->left = buildTree(n - 1);
    root->right = buildTree(n - 1);
    return root;
}

/* Főprogram */
int main() {
    int n = 5;
    // Konstans rend
    constant(n);
    // Lineáris rend
    linear(n);
    linearRecur(n);
    // Négyzetes rend
    quadratic(n);
    quadraticRecur(n);
    // Exponenciális rend
    TreeNode *root = buildTree(n);
    printTree(root);

    // Memória felszabadítása
    freeMemoryTree(root);

    return 0;
}
