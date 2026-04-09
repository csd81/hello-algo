/**
 * File: recursion.java
 * Created Time: 2023-08-24
 * Author: krahets (krahets@163.com)
 */

package chapter_computational_complexity;

import java.util.Stack;

public class recursion {
    /* Rekurzió */
    static int recur(int n) {
        // Leállási feltétel
        if (n == 1)
            return 1;
        // Rekurzió: rekurzív hívás
        int res = recur(n - 1);
        // Visszatérés: eredmény visszaadása
        return n + res;
    }

    /* Rekurzió szimulálása iterációval */
    static int forLoopRecur(int n) {
        // Explicit verem használata a rendszerhívási verem szimulálásához
        Stack<Integer> stack = new Stack<>();
        int res = 0;
        // Rekurzió: rekurzív hívás
        for (int i = n; i > 0; i--) {
            // "Rekurzió" szimulálása "push"-sal
            stack.push(i);
        }
        // Visszatérés: eredmény visszaadása
        while (!stack.isEmpty()) {
            // "Visszatérés" szimulálása "pop"-pal
            res += stack.pop();
        }
        // res = 1+2+3+...+n
        return res;
    }

    /* Farok-rekurzió */
    static int tailRecur(int n, int res) {
        // Leállási feltétel
        if (n == 0)
            return res;
        // Farok-rekurzív hívás
        return tailRecur(n - 1, res + n);
    }

    /* Fibonacci-sorozat: rekurzió */
    static int fib(int n) {
        // Leállási feltétel f(1) = 0, f(2) = 1
        if (n == 1 || n == 2)
            return n - 1;
        // Rekurzív hívás f(n) = f(n-1) + f(n-2)
        int res = fib(n - 1) + fib(n - 2);
        // f(n) eredmény visszaadása
        return res;
    }

    /* Főprogram */
    public static void main(String[] args) {
        int n = 5;
        int res;

        res = recur(n);
        System.out.println("\nRecursive function sum result res = " + res);

        res = forLoopRecur(n);
        System.out.println("\nUsing iteration to simulate recursive sum result res = " + res);

        res = tailRecur(n, 0);
        System.out.println("\nTail recursive function sum result res = " + res);

        res = fib(n);
        System.out.println("\nThe " + n + "th term of the Fibonacci sequence is " + res);
    }
}
