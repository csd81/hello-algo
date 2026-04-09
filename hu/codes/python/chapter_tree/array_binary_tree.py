"""
File: array_binary_tree.py
Created Time: 2023-07-19
Author: krahets (krahets@163.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import TreeNode, list_to_tree, print_tree


class ArrayBinaryTree:
    """Tömbbel reprezentált bináris fa osztály"""

    def __init__(self, arr: list[int | None]):
        """Konstruktor"""
        self._tree = list(arr)

    def size(self):
        """Lista kapacitása"""
        return len(self._tree)

    def val(self, i: int) -> int | None:
        """Az i indexű csomópont értékének lekérése"""
        # Ha az index határon kívül van, None-t ad vissza, üres pozíciót jelölve
        if i < 0 or i >= self.size():
            return None
        return self._tree[i]

    def left(self, i: int) -> int | None:
        """Az i indexű csomópont bal gyermekének indexe"""
        return 2 * i + 1

    def right(self, i: int) -> int | None:
        """Az i indexű csomópont jobb gyermekének indexe"""
        return 2 * i + 2

    def parent(self, i: int) -> int | None:
        """Az i indexű csomópont szülőjének indexe"""
        return (i - 1) // 2

    def level_order(self) -> list[int]:
        """Szintenkénti bejárás"""
        self.res = []
        # A tömböt közvetlenül bejárja
        for i in range(self.size()):
            if self.val(i) is not None:
                self.res.append(self.val(i))
        return self.res

    def dfs(self, i: int, order: str):
        """Mélységi bejárás"""
        if self.val(i) is None:
            return
        # Előrendű bejárás
        if order == "pre":
            self.res.append(self.val(i))
        self.dfs(self.left(i), order)
        # Közrendű bejárás
        if order == "in":
            self.res.append(self.val(i))
        self.dfs(self.right(i), order)
        # Utórendű bejárás
        if order == "post":
            self.res.append(self.val(i))

    def pre_order(self) -> list[int]:
        """Előrendű bejárás"""
        self.res = []
        self.dfs(0, order="pre")
        return self.res

    def in_order(self) -> list[int]:
        """Közrendű bejárás"""
        self.res = []
        self.dfs(0, order="in")
        return self.res

    def post_order(self) -> list[int]:
        """Utórendű bejárás"""
        self.res = []
        self.dfs(0, order="post")
        return self.res


"""Fő kód"""
if __name__ == "__main__":
    # Bináris fa inicializálása
    # Tömbből közvetlenül bináris fát generáló függvény használata
    arr = [1, 2, 3, 4, None, 6, 7, 8, 9, None, None, 12, None, None, 15]
    root = list_to_tree(arr)
    print("\nBináris fa inicializálása\n")
    print("A bináris fa tömb reprezentációja:")
    print(arr)
    print("A bináris fa láncolt lista reprezentációja:")
    print_tree(root)

    # Tömbön alapuló bináris fa osztály
    abt = ArrayBinaryTree(arr)

    # Csomópontok elérése
    i = 1
    l, r, p = abt.left(i), abt.right(i), abt.parent(i)
    print(f"\nAz aktuális csomópont indexe: {i}, értéke: {abt.val(i)}")
    print(f"A bal gyermek indexe: {l}, értéke: {abt.val(l)}")
    print(f"A jobb gyermek indexe: {r}, értéke: {abt.val(r)}")
    print(f"A szülő indexe: {p}, értéke: {abt.val(p)}")

    # Fa bejárása
    res = abt.level_order()
    print("\nSzintenkénti bejárás:", res)
    res = abt.pre_order()
    print("Előrendű bejárás:", res)
    res = abt.in_order()
    print("Közrendű bejárás:", res)
    res = abt.post_order()
    print("Utórendű bejárás:", res)
