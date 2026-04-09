/**
 * File: permutations_ii.cpp
 * Created Time: 2023-04-24
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Visszalépéses algoritmus: II. permutáció */
void backtrack(vector<int> &state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res) {
    // Ha az állapot hossza megegyezik az elemek számával, rögzítjük a megoldást
    if (state.size() == choices.size()) {
        res.push_back(state);
        return;
    }
    // Az összes lehetőség bejárása
    unordered_set<int> duplicated;
    for (int i = 0; i < choices.size(); i++) {
        int choice = choices[i];
        // Vágás: elemek ismételt kiválasztása és egyenlő elemek ismételt kiválasztása nem engedélyezett
        if (!selected[i] && duplicated.find(choice) == duplicated.end()) {
            // Próbálkozás: lehetőség kiválasztása, állapot frissítése
            duplicated.emplace(choice); // A kiválasztott elem értékének rögzítése
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

/* II. permutáció */
vector<vector<int>> permutationsII(vector<int> nums) {
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backtrack(state, nums, selected, res);
    return res;
}

/* Driver Code */
int main() {
    vector<int> nums = {1, 1, 2};

    vector<vector<int>> res = permutationsII(nums);

    cout << "Input array nums = ";
    printVector(nums);
    cout << "All permutations res = ";
    printVectorMatrix(res);

    return 0;
}
