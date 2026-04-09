/**
 * File: recursion.c
 * Created Time: 2023-09-09
 * Author: Gonglja (glj0@outlook.com)
 */

#include "../utils/common.h"

/* Rekurzió */
int recur(int n) {
    // Leállási feltétel
    if (n == 1)
        return 1;
    // Rekurzív hívás
    int res = recur(n - 1);
    // Visszatérés: az eredmény visszaadása
    return n + res;
}

/* Rekurzió szimulálása iterációval */
int forLoopRecur(int n) {
    int stack[1000]; // Nagy tömb használata a verem szimulálásához
    int top = -1;    // Verem tetejének indexe
    int res = 0;
    // Rekurzív hívás szimulálása
    for (int i = n; i > 0; i--) {
        // "Rekurzió" szimulálása "push" művelettel
        stack[1 + top++] = i;
    }
    // Visszatérés szimulálása
    while (top >= 0) {
        // "Visszatérés" szimulálása "pop" művelettel
        res += stack[top--];
    }
    // res = 1+2+3+...+n
    return res;
}

/* Farokrekurzió */
int tailRecur(int n, int res) {
    // Leállási feltétel
    if (n == 0)
        return res;
    // Farokrekurzív hívás
    return tailRecur(n - 1, res + n);
}

/* Fibonacci-sorozat: rekurzió */
int fib(int n) {
    // Leállási feltétel f(1) = 0, f(2) = 1
    if (n == 1 || n == 2)
        return n - 1;
    // Rekurzív hívás f(n) = f(n-1) + f(n-2)
    int res = fib(n - 1) + fib(n - 2);
    // f(n) eredmény visszaadása
    return res;
}

/* Vezérlő kód */
int main() {
    int n = 5;
    int res;

    res = recur(n);
    printf("\nRecursion sum result res = %d\n", res);

    res = forLoopRecur(n);
    printf("\nUsing iteration to simulate recursion sum result res = %d\n", res);

    res = tailRecur(n, 0);
    printf("\nTail recursion sum result res = %d\n", res);

    res = fib(n);
    printf("\nThe %dth Fibonacci number is %d\n", n, res);

    return 0;
}
