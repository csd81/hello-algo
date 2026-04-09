/**
 * File: permutations_i.cpp
 * Created Time: 2023-04-24
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Visszalépéses algoritmus: I. permutáció */
void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res) {
    // Ha az állapot hossza megegyezik az elemek számával, rögzítjük a megoldást
    if (state.size() == choices.size()) {
        res.push_back(state);
        return;
    }
    // Az összes lehetőség bejárása
    for (int i = 0; i < choices.size(); i++) {
        int choice = choices[i];
        // Vágás: elemek ismételt kiválasztása nem engedélyezett
        if (!selected[i]) {
            // Próbálkozás: lehetőség kiválasztása, állapot frissítése
            selected[i] = true;
            state.push_back(choice);
            // Következő kiválasztási kör végrehajtása
            backtrack(state, choices, selected, res);
            // Visszalépés: lehetőség visszavonása, előző állapot visszaállítása
            selected[i] = false;
            state.pop_back();
        }
    }
}

/* I. permutáció */
vector<vector<int>> permutationsI(vector<int> nums) {
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backtrack(state, nums, selected, res);
    return res;
}

/* Driver Code */
int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> res = permutationsI(nums);

    cout << "Input array nums = ";
    printVector(nums);
    cout << "All permutations res = ";
    printVectorMatrix(res);

    return 0;
}
