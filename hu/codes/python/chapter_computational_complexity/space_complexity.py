"""
File: space_complexity.py
Created Time: 2022-11-25
Author: krahets (krahets@163.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import ListNode, TreeNode, print_tree


def function() -> int:
    """Függvény"""
    # Néhány műveletet végez
    return 0


def constant(n: int):
    """Konstans rend"""
    # Konstansok, változók, objektumok O(1) tárhelyet foglalnak
    a = 0
    nums = [0] * 10000
    node = ListNode(0)
    # A ciklus változói O(1) tárhelyet foglalnak
    for _ in range(n):
        c = 0
    # A ciklus függvényei O(1) tárhelyet foglalnak
    for _ in range(n):
        function()


def linear(n: int):
    """Lineáris rend"""
    # Egy n hosszúságú lista O(n) tárhelyet foglal
    nums = [0] * n
    # Egy n méretű hash tábla O(n) tárhelyet foglal
    hmap = dict[int, str]()
    for i in range(n):
        hmap[i] = str(i)


def linear_recur(n: int):
    """Lineáris rend (rekurzív megvalósítás)"""
    print("Rekurzió n =", n)
    if n == 1:
        return
    linear_recur(n - 1)


def quadratic(n: int):
    """Négyzetes rend"""
    # Egy 2D lista O(n^2) tárhelyet foglal
    num_matrix = [[0] * n for _ in range(n)]


def quadratic_recur(n: int) -> int:
    """Négyzetes rend (rekurzív megvalósítás)"""
    if n <= 0:
        return 0
    # A nums tömb hossza: n, n-1, ..., 2, 1
    nums = [0] * n
    return quadratic_recur(n - 1)


def build_tree(n: int) -> TreeNode | None:
    """Exponenciális rend (teljes bináris fa felépítése)"""
    if n == 0:
        return None
    root = TreeNode(0)
    root.left = build_tree(n - 1)
    root.right = build_tree(n - 1)
    return root


"""Fő kód"""
if __name__ == "__main__":
    n = 5
    # Konstans rend
    constant(n)
    # Lineáris rend
    linear(n)
    linear_recur(n)
    # Négyzetes rend
    quadratic(n)
    quadratic_recur(n)
    # Exponenciális rend
    root = build_tree(n)
    print_tree(root)
