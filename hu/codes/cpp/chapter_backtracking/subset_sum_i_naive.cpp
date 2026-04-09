/**
 * File: subset_sum_i_naive.cpp
 * Created Time: 2023-06-21
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Visszalépéses algoritmus: I. részösszeg */
void backtrack(vector<int> &state, int target, int total, vector<int> &choices, vector<vector<int>> &res) {
    // Ha a részösszeg egyenlő a targettel, rögzítjük a megoldást
    if (total == target) {
        res.push_back(state);
        return;
    }
    // Az összes lehetőség bejárása
    for (size_t i = 0; i < choices.size(); i++) {
        // Vágás: ha a részösszeg meghaladja a targetet, kihagyjuk ezt a lehetőséget
        if (total + choices[i] > target) {
            continue;
        }
        // Próbálkozás: lehetőség kiválasztása, total elemösszeg frissítése
        state.push_back(choices[i]);
        // Következő kiválasztási kör végrehajtása
        backtrack(state, target, total + choices[i], choices, res);
        // Visszalépés: lehetőség visszavonása, előző állapot visszaállítása
        state.pop_back();
    }
}

/* I. részösszeg megoldása (duplikált részhalmazokkal együtt) */
vector<vector<int>> subsetSumINaive(vector<int> &nums, int target) {
    vector<int> state;       // Állapot (részhalmaz)
    int total = 0;           // Részösszeg
    vector<vector<int>> res; // Eredménylista (részhalmazlista)
    backtrack(state, target, total, nums, res);
    return res;
}

/* Driver Code */
int main() {
    vector<int> nums = {3, 4, 5};
    int target = 9;

    vector<vector<int>> res = subsetSumINaive(nums, target);

    cout << "Input array nums = ";
    printVector(nums);
    cout << "target = " << target << endl;
    cout << "All subsets with sum equal to " << target << " are res = " << endl;
    printVectorMatrix(res);

    return 0;
}
