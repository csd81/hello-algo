/**
 * File: n_queens.cpp
 * Created Time: 2023-05-04
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Visszalépéses algoritmus: N vezér */
void backtrack(int row, int n, vector<vector<string>> &state, vector<vector<vector<string>>> &res, vector<bool> &cols,
               vector<bool> &diags1, vector<bool> &diags2) {
    // Ha minden sor el van helyezve, rögzítjük a megoldást
    if (row == n) {
        res.push_back(state);
        return;
    }
    // Az összes oszlop bejárása
    for (int col = 0; col < n; col++) {
        // Az adott cellához tartozó főátló és mellékátló kiszámítása
        int diag1 = row - col + n - 1;
        int diag2 = row + col;
        // Vágás: nem engedélyezett, hogy vezér legyen az adott cella oszlopában, főátlójában és mellékátlójában
        if (!cols[col] && !diags1[diag1] && !diags2[diag2]) {
            // Próbálkozás: vezér elhelyezése az adott cellában
            state[row][col] = "Q";
            cols[col] = diags1[diag1] = diags2[diag2] = true;
            // Következő sor elhelyezése
            backtrack(row + 1, n, state, res, cols, diags1, diags2);
            // Visszalépés: az adott cella visszaállítása üres cellává
            state[row][col] = "#";
            cols[col] = diags1[diag1] = diags2[diag2] = false;
        }
    }
}

/* N vezér megoldása */
vector<vector<vector<string>>> nQueens(int n) {
    // n*n sakktábla inicializálása, ahol 'Q' vezért, '#' üres cellát jelöl
    vector<vector<string>> state(n, vector<string>(n, "#"));
    vector<bool> cols(n, false);           // Rögzíti, hogy van-e vezér az oszlopban
    vector<bool> diags1(2 * n - 1, false); // Rögzíti, hogy van-e vezér a főátlón
    vector<bool> diags2(2 * n - 1, false); // Rögzíti, hogy van-e vezér a mellékátlón
    vector<vector<vector<string>>> res;

    backtrack(0, n, state, res, cols, diags1, diags2);

    return res;
}

/* Driver Code */
int main() {
    int n = 4;
    vector<vector<vector<string>>> res = nQueens(n);

    cout << "Input board size is " << n << endl;
    cout << "Total queen placement solutions: " << res.size() << endl;
    for (const vector<vector<string>> &state : res) {
        cout << "--------------------" << endl;
        for (const vector<string> &row : state) {
            printVector(row);
        }
    }

    return 0;
}
