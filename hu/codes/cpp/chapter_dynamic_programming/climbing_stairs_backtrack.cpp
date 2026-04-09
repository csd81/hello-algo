
/**
 * File: climbing_stairs_backtrack.cpp
 * Created Time: 2023-06-30
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Visszalépés */
void backtrack(vector<int> &choices, int state, int n, vector<int> &res) {
    // Ha elértük az n-edik lépcsőt, a megoldások számát 1-gyel növeljük
    if (state == n)
        res[0]++;
    // Az összes lehetőség bejárása
    for (auto &choice : choices) {
        // Vágás: nem szabad túllépni az n-edik lépcsőt
        if (state + choice > n)
            continue;
        // Próbálkozás: lehetőség kiválasztása, állapot frissítése
        backtrack(choices, state + choice, n, res);
        // Visszalépés
    }
}

/* Lépcsőmászás: Visszalépés */
int climbingStairsBacktrack(int n) {
    vector<int> choices = {1, 2}; // 1 vagy 2 lépcsőt lehet felmenni egyszerre
    int state = 0;                // A 0. lépcsőről indulunk
    vector<int> res = {0};        // res[0]-t használjuk a megoldások számának rögzítéséhez
    backtrack(choices, state, n, res);
    return res[0];
}

/* Driver Code */
int main() {
    int n = 9;

    int res = climbingStairsBacktrack(n);
    cout << "Climbing " << n << " stairs has " << res << " solutions" << endl;

    return 0;
}
