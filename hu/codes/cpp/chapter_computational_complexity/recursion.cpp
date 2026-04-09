/**
 * File: recursion.cpp
 * Created Time: 2023-08-24
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* Rekurzió */
int recur(int n) {
    // Megállási feltétel
    if (n == 1)
        return 1;
    // Rekurzív hívás
    int res = recur(n - 1);
    // Visszatérési érték: eredmény visszaadása
    return n + res;
}

/* Rekurzió szimulálása iterációval */
int forLoopRecur(int n) {
    // Explicit verem használata a rendszer hívási vermének szimulálásához
    stack<int> stack;
    int res = 0;
    // Rekurzív hívás szimulálása
    for (int i = n; i > 0; i--) {
        // "Rekurzív hívás" szimulálása "push" művelettel
        stack.push(i);
    }
    // Visszatérési érték szimulálása
    while (!stack.empty()) {
        // "Visszatérés" szimulálása "pop" művelettel
        res += stack.top();
        stack.pop();
    }
    // res = 1+2+3+...+n
    return res;
}

/* Farokrekurzió */
int tailRecur(int n, int res) {
    // Megállási feltétel
    if (n == 0)
        return res;
    // Farokrekurzív hívás
    return tailRecur(n - 1, res + n);
}

/* Fibonacci-sorozat: rekurzió */
int fib(int n) {
    // Megállási feltétel: f(1) = 0, f(2) = 1
    if (n == 1 || n == 2)
        return n - 1;
    // Rekurzív hívás: f(n) = f(n-1) + f(n-2)
    int res = fib(n - 1) + fib(n - 2);
    // f(n) eredmény visszaadása
    return res;
}

/* Főprogram */
int main() {
    int n = 5;
    int res;

    res = recur(n);
    cout << "\nRecursive function sum result res = " << res << endl;

    res = forLoopRecur(n);
    cout << "\nUsing iteration to simulate recursive sum result res = " << res << endl;

    res = tailRecur(n, 0);
    cout << "\nTail recursive function sum result res = " << res << endl;

    res = fib(n);
    cout << "\nThe " << n << "th term of the Fibonacci sequence is " << res << endl;

    return 0;
}
