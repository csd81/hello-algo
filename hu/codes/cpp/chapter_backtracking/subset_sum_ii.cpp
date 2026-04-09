/**
 * File: subset_sum_ii.cpp
 * Created Time: 2023-06-21
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Visszalépéses algoritmus: II. részösszeg */
void backtrack(vector<int> &state, int target, vector<int> &choices, int start, vector<vector<int>> &res) {
    // Ha a részösszeg egyenlő a targettel, rögzítjük a megoldást
    if (target == 0) {
        res.push_back(state);
        return;
    }
    // Az összes lehetőség bejárása
    // 2. vágás: start-tól kezdve bejárva elkerüljük a duplikált részhalmazok generálását
    // 3. vágás: start-tól kezdve bejárva elkerüljük ugyanazon elem ismételt kiválasztását
    for (int i = start; i < choices.size(); i++) {
        // 1. vágás: ha a részösszeg meghaladja a targetet, közvetlenül befejezzük a ciklust
        // Ez azért van, mert a tömb rendezett, és a későbbi elemek nagyobbak, tehát a részösszeg biztosan meghaladja a targetet
        if (target - choices[i] < 0) {
            break;
        }
        // 4. vágás: ha ez az elem egyenlő a bal oldali elemmel, ez a keresési ág duplikált, közvetlenül kihagyjuk
        if (i > start && choices[i] == choices[i - 1]) {
            continue;
        }
        // Próbálkozás: lehetőség kiválasztása, target és start frissítése
        state.push_back(choices[i]);
        // Következő kiválasztási kör végrehajtása
        backtrack(state, target - choices[i], choices, i + 1, res);
        // Visszalépés: lehetőség visszavonása, előző állapot visszaállítása
        state.pop_back();
    }
}

/* II. részösszeg megoldása */
vector<vector<int>> subsetSumII(vector<int> &nums, int target) {
    vector<int> state;              // Állapot (részhalmaz)
    sort(nums.begin(), nums.end()); // nums rendezése
    int start = 0;                  // Bejárás kezdőpontja
    vector<vector<int>> res;        // Eredménylista (részhalmazlista)
    backtrack(state, target, nums, start, res);
    return res;
}

/* Driver Code */
int main() {
    vector<int> nums = {4, 4, 5};
    int target = 9;

    vector<vector<int>> res = subsetSumII(nums, target);

    cout << "Input array nums = ";
    printVector(nums);
    cout << "target = " << target << endl;
    cout << "All subsets with sum equal to " << target << " are res = " << endl;
    printVectorMatrix(res);

    return 0;
}
