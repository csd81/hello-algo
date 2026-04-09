"""
File: heap.py
Created Time: 2023-02-23
Author: krahets (krahets@163.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import print_heap

import heapq


def test_push(heap: list, val: int, flag: int = 1):
    heapq.heappush(heap, flag * val)  # Elem bekerül a kupacba
    print(f"\nA(z) {val} elem kupacba kerülése után")
    print_heap([flag * val for val in heap])


def test_pop(heap: list, flag: int = 1):
    val = flag * heapq.heappop(heap)  # A kupac tetejének eleme kilép
    print(f"\nA(z) {val} tetőelem kilépése után")
    print_heap([flag * val for val in heap])


"""Fő kód"""
if __name__ == "__main__":
    # Min-kupac inicializálása
    min_heap, flag = [], 1
    # Max-kupac inicializálása
    max_heap, flag = [], -1

    print("\nA következő tesztesetek max-kupacra vonatkoznak")
    # A Python heapq modulja alapértelmezés szerint min-kupacot valósít meg
    # Az elemek előjelének megfordításával a méretbeli sorrend is megfordul, így max-kupacot kapunk
    # Ebben a példában flag = 1 min-kupacnak, flag = -1 max-kupacnak felel meg

    # Elemek betolása a kupacba
    test_push(max_heap, 1, flag)
    test_push(max_heap, 3, flag)
    test_push(max_heap, 2, flag)
    test_push(max_heap, 5, flag)
    test_push(max_heap, 4, flag)

    # Tetőelem lekérése
    peek: int = flag * max_heap[0]
    print(f"\nA tetőelem: {peek}")

    # Tetőelem kilépése
    test_pop(max_heap, flag)
    test_pop(max_heap, flag)
    test_pop(max_heap, flag)
    test_pop(max_heap, flag)
    test_pop(max_heap, flag)

    # Kupac méretének lekérése
    size: int = len(max_heap)
    print(f"\nA kupac elemeinek száma: {size}")

    # Ellenőrzi, hogy a kupac üres-e
    is_empty: bool = not max_heap
    print(f"\nA kupac üres-e: {is_empty}")

    # Lista beadása és kupac felépítése
    # Időbonyolultság O(n), nem O(nlogn)
    min_heap = [1, 3, 2, 5, 4]
    heapq.heapify(min_heap)
    print("\nLista beadása és min-kupac felépítése után")
    print_heap(min_heap)
