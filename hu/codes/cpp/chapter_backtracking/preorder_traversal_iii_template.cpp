/**
 * File: preorder_traversal_iii_template.cpp
 * Created Time: 2023-04-16
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Ellenőrzi, hogy az aktuális állapot megoldás-e */
bool isSolution(vector<TreeNode *> &state) {
    return !state.empty() && state.back()->val == 7;
}

/* Megoldás rögzítése */
void recordSolution(vector<TreeNode *> &state, vector<vector<TreeNode *>> &res) {
    res.push_back(state);
}

/* Ellenőrzi, hogy a lehetőség érvényes-e az aktuális állapotban */
bool isValid(vector<TreeNode *> &state, TreeNode *choice) {
    return choice != nullptr && choice->val != 3;
}

/* Állapot frissítése */
void makeChoice(vector<TreeNode *> &state, TreeNode *choice) {
    state.push_back(choice);
}

/* Állapot visszaállítása */
void undoChoice(vector<TreeNode *> &state, TreeNode *choice) {
    state.pop_back();
}

/* Visszalépéses algoritmus: 3. példa */
void backtrack(vector<TreeNode *> &state, vector<TreeNode *> &choices, vector<vector<TreeNode *>> &res) {
    // Ellenőrzés, hogy ez megoldás-e
    if (isSolution(state)) {
        // Megoldás rögzítése
        recordSolution(state, res);
    }
    // Az összes lehetőség bejárása
    for (TreeNode *choice : choices) {
        // Vágás: ellenőrzi, hogy a lehetőség érvényes-e
        if (isValid(state, choice)) {
            // Próbálkozás: lehetőség kiválasztása, állapot frissítése
            makeChoice(state, choice);
            // Következő kiválasztási kör végrehajtása
            vector<TreeNode *> nextChoices{choice->left, choice->right};
            backtrack(state, nextChoices, res);
            // Visszalépés: lehetőség visszavonása, előző állapot visszaállítása
            undoChoice(state, choice);
        }
    }
}

/* Főprogram */
int main() {
    TreeNode *root = vectorToTree(vector<int>{1, 7, 3, 4, 5, 6, 7});
    cout << "\nInitialize binary tree" << endl;
    printTree(root);

    // Visszalépéses algoritmus
    vector<TreeNode *> state;
    vector<TreeNode *> choices = {root};
    vector<vector<TreeNode *>> res;
    backtrack(state, choices, res);

    cout << "\nOutput all paths from root node to node 7, requiring paths do not include nodes with value 3" << endl;
    for (vector<TreeNode *> &path : res) {
        vector<int> vals;
        for (TreeNode *node : path) {
            vals.push_back(node->val);
        }
        printVector(vals);
    }
}
