/**
 * File: hanota.cpp
 * Created Time: 2023-07-17
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Korong áthelyezése */
void move(vector<int> &src, vector<int> &tar) {
    // Korong kivétele az src tetejéről
    int pan = src.back();
    src.pop_back();
    // Korong elhelyezése a tar tetejére
    tar.push_back(pan);
}

/* Hanoi-torony feladat megoldása: f(i) */
void dfs(int i, vector<int> &src, vector<int> &buf, vector<int> &tar) {
    // Ha csak egy korong maradt az src-ben, közvetlenül áthelyezzük a tar-ra
    if (i == 1) {
        move(src, tar);
        return;
    }
    // f(i-1) részfeladat: a felső i-1 korong áthelyezése src-ről buf-ra, tar segítségével
    dfs(i - 1, src, tar, buf);
    // f(1) részfeladat: a maradék korong áthelyezése src-ről tar-ra
    move(src, tar);
    // f(i-1) részfeladat: a felső i-1 korong áthelyezése buf-ról tar-ra, src segítségével
    dfs(i - 1, buf, src, tar);
}

/* Hanoi-torony feladat megoldása */
void solveHanota(vector<int> &A, vector<int> &B, vector<int> &C) {
    int n = A.size();
    // A felső n korong áthelyezése A-ról C-re, B segítségével
    dfs(n, A, B, C);
}

/* Főprogram */
int main() {
    // A lista vége a rúd teteje
    vector<int> A = {5, 4, 3, 2, 1};
    vector<int> B = {};
    vector<int> C = {};

    cout << "Initial state:\n";
    cout << "A =";
    printVector(A);
    cout << "B =";
    printVector(B);
    cout << "C =";
    printVector(C);

    solveHanota(A, B, C);

    cout << "After disk movement:\n";
    cout << "A =";
    printVector(A);
    cout << "B =";
    printVector(B);
    cout << "C =";
    printVector(C);

    return 0;
}
