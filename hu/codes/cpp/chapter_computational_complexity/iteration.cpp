/**
 * File: iteration.cpp
 * Created Time: 2023-08-24
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* for ciklus */
int forLoop(int n) {
    int res = 0;
    // 1, 2, ..., n-1, n összege
    for (int i = 1; i <= n; ++i) {
        res += i;
    }
    return res;
}

/* while ciklus */
int whileLoop(int n) {
    int res = 0;
    int i = 1; // Feltételváltozó inicializálása
    // 1, 2, ..., n-1, n összege
    while (i <= n) {
        res += i;
        i++; // Feltételváltozó frissítése
    }
    return res;
}

/* while ciklus (két frissítéssel) */
int whileLoopII(int n) {
    int res = 0;
    int i = 1; // Feltételváltozó inicializálása
    // 1, 4, 10, ... összege
    while (i <= n) {
        res += i;
        // Feltételváltozó frissítése
        i++;
        i *= 2;
    }
    return res;
}

/* Egymásba ágyazott for ciklus */
string nestedForLoop(int n) {
    ostringstream res;
    // i = 1, 2, ..., n-1, n ciklus
    for (int i = 1; i <= n; ++i) {
        // j = 1, 2, ..., n-1, n ciklus
        for (int j = 1; j <= n; ++j) {
            res << "(" << i << ", " << j << "), ";
        }
    }
    return res.str();
}

/* Főprogram */
int main() {
    int n = 5;
    int res;

    res = forLoop(n);
    cout << "\nfor loop sum result res = " << res << endl;

    res = whileLoop(n);
    cout << "\nwhile loop sum result res = " << res << endl;

    res = whileLoopII(n);
    cout << "\nwhile loop (two updates) sum result res = " << res << endl;

    string resStr = nestedForLoop(n);
    cout << "\nDouble for loop traversal result " << resStr << endl;

    return 0;
}
