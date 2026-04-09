"""
File: top_k.py
Created Time: 2023-06-10
Author: krahets (krahets@163.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import print_heap

import heapq


def top_k_heap(nums: list[int], k: int) -> list[int]:
    """A tömb k legnagyobb elemének megkeresése kupac alapján"""
    # Min-kupac inicializálása
    heap = []
    # A tömb első k elemét beteszi a kupacba
    for i in range(k):
        heapq.heappush(heap, nums[i])
    # A (k+1)-edik elemtől kezdve a kupac méretét k-n tartja
    for i in range(k, len(nums)):
        # Ha az aktuális elem nagyobb a tetőelemnél, a tetőelem kilép, az aktuális elem belép
        if nums[i] > heap[0]:
            heapq.heappop(heap)
            heapq.heappush(heap, nums[i])
    return heap


"""Fő kód"""
if __name__ == "__main__":
    nums = [1, 7, 6, 3, 2]
    k = 3

    res = top_k_heap(nums, k)
    print(f"A(z) {k} legnagyobb elem:")
    print_heap(res)
