"""
File: worst_best_time_complexity.py
Created Time: 2022-11-25
Author: krahets (krahets@163.com)
"""

import random


def random_numbers(n: int) -> list[int]:
    """Véletlenszerűen kevert, 1, 2, ..., n elemeket tartalmazó tömb generálása"""
    # nums = 1, 2, 3, ..., n tömb generálása
    nums = [i for i in range(1, n + 1)]
    # A tömb elemeit véletlenszerűen megkeveri
    random.shuffle(nums)
    return nums


def find_one(nums: list[int]) -> int:
    """Az 1-es szám indexének megkeresése a nums tömbben"""
    for i in range(len(nums)):
        # Ha az 1-es elem a tömb elején van, legjobb esetű időbonyolultság O(1) érhető el
        # Ha az 1-es elem a tömb végén van, legrosszabb esetű időbonyolultság O(n) érhető el
        if nums[i] == 1:
            return i
    return -1


"""Fő kód"""
if __name__ == "__main__":
    for i in range(10):
        n = 100
        nums: list[int] = random_numbers(n)
        index: int = find_one(nums)
        print("\nA megkevert [ 1, 2, ..., n ] tömb =", nums)
        print("Az 1-es szám indexe:", index)
