"""
File: iteration.py
Created Time: 2023-08-24
Author: krahets (krahets@163.com)
"""


def for_loop(n: int) -> int:
    """for ciklus"""
    res = 0
    # Összegzés: 1, 2, ..., n-1, n
    for i in range(1, n + 1):
        res += i
    return res


def while_loop(n: int) -> int:
    """while ciklus"""
    res = 0
    i = 1  # Feltételváltozó inicializálása
    # Összegzés: 1, 2, ..., n-1, n
    while i <= n:
        res += i
        i += 1  # Feltételváltozó frissítése
    return res


def while_loop_ii(n: int) -> int:
    """while ciklus (kétszeres frissítés)"""
    res = 0
    i = 1  # Feltételváltozó inicializálása
    # Összegzés: 1, 4, 10, ...
    while i <= n:
        res += i
        # Feltételváltozó frissítése
        i += 1
        i *= 2
    return res


def nested_for_loop(n: int) -> str:
    """Egymásba ágyazott for ciklus"""
    res = ""
    # i = 1, 2, ..., n-1, n ciklus
    for i in range(1, n + 1):
        # j = 1, 2, ..., n-1, n ciklus
        for j in range(1, n + 1):
            res += f"({i}, {j}), "
    return res


"""Fő kód"""
if __name__ == "__main__":
    n = 5
    res = for_loop(n)
    print(f"\nA for ciklus összegzési eredménye res = {res}")

    res = while_loop(n)
    print(f"\nA while ciklus összegzési eredménye res = {res}")

    res = while_loop_ii(n)
    print(f"\nA while ciklus (kétszeres frissítés) összegzési eredménye res = {res}")

    res = nested_for_loop(n)
    print(f"\nAz egymásba ágyazott for ciklus bejárási eredménye {res}")
