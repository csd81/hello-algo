/**
 * File: recursion.js
 * Created Time: 2023-08-28
 * Author: Gaofer Chou (gaofer-chou@qq.com)
 */

/* Rekurzió */
function recur(n) {
    // Leállási feltétel
    if (n === 1) return 1;
    // Rekurzió: rekurzív hívás
    const res = recur(n - 1);
    // Visszatérés: eredmény visszaadása
    return n + res;
}

/* Rekurzió szimulálása iterációval */
function forLoopRecur(n) {
    // Explicit vermet használunk a rendszer hívási verme szimulálásához
    const stack = [];
    let res = 0;
    // Rekurzió: rekurzív hívás
    for (let i = n; i > 0; i--) {
        // "Rekurzió" szimulálása "push"-sal
        stack.push(i);
    }
    // Visszatérés: eredmény visszaadása
    while (stack.length) {
        // "Visszatérés" szimulálása "pop"-pal
        res += stack.pop();
    }
    // res = 1+2+3+...+n
    return res;
}

/* Farok rekurzió */
function tailRecur(n, res) {
    // Leállási feltétel
    if (n === 0) return res;
    // Farok rekurzív hívás
    return tailRecur(n - 1, res + n);
}

/* Fibonacci-sorozat: rekurzió */
function fib(n) {
    // Leállási feltétel f(1) = 0, f(2) = 1
    if (n === 1 || n === 2) return n - 1;
    // Rekurzív hívás f(n) = f(n-1) + f(n-2)
    const res = fib(n - 1) + fib(n - 2);
    // Eredmény visszaadása f(n)
    return res;
}

/* Tesztkód */
const n = 5;
let res;

res = recur(n);
console.log(`Recursion sum result res = ${res}`);

res = forLoopRecur(n);
console.log(`Using iteration to simulate recursion sum result res = ${res}`);

res = tailRecur(n, 0);
console.log(`Tail recursion sum result res = ${res}`);

res = fib(n);
console.log(`The ${n}th Fibonacci number is ${res}`);

