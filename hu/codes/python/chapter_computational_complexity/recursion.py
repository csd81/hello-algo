"""
File: recursion.py
Created Time: 2023-08-24
Author: krahets (krahets@163.com)
"""


def recur(n: int) -> int:
    """Rekurzió"""
    # Leállási feltétel
    if n == 1:
        return 1
    # Rekurzív hívás
    res = recur(n - 1)
    # Visszatérés: eredmény visszaadása
    return n + res


def for_loop_recur(n: int) -> int:
    """Rekurzió szimulálása iterációval"""
    # Explicit verem használata a rendszerhívási verem szimulálásához
    stack = []
    res = 0
    # Rekurzív hívás szimulálása
    for i in range(n, 0, -1):
        # A "rekurzió" szimulálása "push" művelettel
        stack.append(i)
    # Visszatérés: eredmény visszaadása
    while stack:
        # A "visszatérés" szimulálása "pop" művelettel
        res += stack.pop()
    # res = 1+2+3+...+n
    return res


def tail_recur(n, res):
    """Farokrekurzió"""
    # Leállási feltétel
    if n == 0:
        return res
    # Farokrekurzív hívás
    return tail_recur(n - 1, res + n)


def fib(n: int) -> int:
    """Fibonacci-sorozat: rekurzió"""
    # Leállási feltétel: f(1) = 0, f(2) = 1
    if n == 1 or n == 2:
        return n - 1
    # Rekurzív hívás: f(n) = f(n-1) + f(n-2)
    res = fib(n - 1) + fib(n - 2)
    # f(n) eredmény visszaadása
    return res


"""Fő kód"""
if __name__ == "__main__":
    n = 5
    res = recur(n)
    print(f"\nA rekurzív függvény összegzési eredménye res = {res}")

    res = for_loop_recur(n)
    print(f"\nAz iterációval szimulált rekurzió összegzési eredménye res = {res}")

    res = tail_recur(n, 0)
    print(f"\nA farokrekurzív függvény összegzési eredménye res = {res}")

    res = fib(n)
    print(f"\nA Fibonacci-sorozat {n}. tagja: {res}")
