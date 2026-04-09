"""
File: my_heap.py
Created Time: 2023-02-23
Author: krahets (krahets@163.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import print_heap


class MaxHeap:
    """Max-kupac"""

    def __init__(self, nums: list[int]):
        """Konstruktor, kupac felépítése a bemeneti lista alapján"""
        # Lista elemeit változtatás nélkül a kupacba adja
        self.max_heap = nums
        # Az összes csomópontra kupacosítást végez, kivéve a levélcsomópontokat
        for i in range(self.parent(self.size() - 1), -1, -1):
            self.sift_down(i)

    def left(self, i: int) -> int:
        """A bal gyermekcsomópont indexének lekérése"""
        return 2 * i + 1

    def right(self, i: int) -> int:
        """A jobb gyermekcsomópont indexének lekérése"""
        return 2 * i + 2

    def parent(self, i: int) -> int:
        """A szülőcsomópont indexének lekérése"""
        return (i - 1) // 2  # Egészrész-osztás

    def swap(self, i: int, j: int):
        """Elemek felcserélése"""
        self.max_heap[i], self.max_heap[j] = self.max_heap[j], self.max_heap[i]

    def size(self) -> int:
        """Kupac méretének lekérése"""
        return len(self.max_heap)

    def is_empty(self) -> bool:
        """Ellenőrzi, hogy a kupac üres-e"""
        return self.size() == 0

    def peek(self) -> int:
        """Tetőelem elérése"""
        return self.max_heap[0]

    def push(self, val: int):
        """Elem betolása a kupacba"""
        # Csomópont hozzáadása
        self.max_heap.append(val)
        # Alulról felfelé kupacosítás
        self.sift_up(self.size() - 1)

    def sift_up(self, i: int):
        """Az i csomóponttól kezdve alulról felfelé kupacosítás"""
        while True:
            # Az i csomópont szülőjének lekérése
            p = self.parent(i)
            # Ha "átlépi a gyökércsomópontot" vagy "a csomópontnak nincs szüksége javításra", kupacosítás vége
            if p < 0 or self.max_heap[i] <= self.max_heap[p]:
                break
            # Két csomópont felcserélése
            self.swap(i, p)
            # Felfelé haladó kupacosítás folytatása
            i = p

    def pop(self) -> int:
        """Elem kiemelése a kupacból"""
        # Üres eset kezelése
        if self.is_empty():
            raise IndexError("A kupac üres")
        # A gyökércsomópontot a jobb szélső levéllel cseréli fel (az első elemet az utolsóval)
        self.swap(0, self.size() - 1)
        # Csomópont törlése
        val = self.max_heap.pop()
        # Felülről lefelé kupacosítás
        self.sift_down(0)
        # Tetőelemet adja vissza
        return val

    def sift_down(self, i: int):
        """Az i csomóponttól kezdve felülről lefelé kupacosítás"""
        while True:
            # Az i, l, r közül a legnagyobb értékű csomópontot keresi, ma-ként jelöli
            l, r, ma = self.left(i), self.right(i), i
            if l < self.size() and self.max_heap[l] > self.max_heap[ma]:
                ma = l
            if r < self.size() and self.max_heap[r] > self.max_heap[ma]:
                ma = r
            # Ha az i csomópont a legnagyobb, vagy az l, r indexek határon kívül vannak, nincs szükség további kupacosításra
            if ma == i:
                break
            # Két csomópont felcserélése
            self.swap(i, ma)
            # Lefelé haladó kupacosítás folytatása
            i = ma

    def print(self):
        """Kupac kiírása (bináris fa)"""
        print_heap(self.max_heap)


"""Fő kód"""
if __name__ == "__main__":
    # Max-kupac inicializálása
    max_heap = MaxHeap([9, 8, 6, 6, 7, 5, 2, 1, 4, 3, 6, 2])
    print("\nLista beadása és kupac felépítése után")
    max_heap.print()

    # Tetőelem lekérése
    peek = max_heap.peek()
    print(f"\nA tetőelem: {peek}")

    # Elem betolása a kupacba
    val = 7
    max_heap.push(val)
    print(f"\nA(z) {val} elem kupacba kerülése után")
    max_heap.print()

    # Tetőelem kiemelése
    peek = max_heap.pop()
    print(f"\nA(z) {peek} tetőelem kilépése után")
    max_heap.print()

    # Kupac méretének lekérése
    size = max_heap.size()
    print(f"\nA kupac elemeinek száma: {size}")

    # Ellenőrzi, hogy a kupac üres-e
    is_empty = max_heap.is_empty()
    print(f"\nA kupac üres-e: {is_empty}")
