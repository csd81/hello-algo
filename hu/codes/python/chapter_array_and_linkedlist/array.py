"""
File: array.py
Created Time: 2022-11-25
Author: krahets (krahets@163.com)
"""

import random


def random_access(nums: list[int]) -> int:
    """Véletlenszerű hozzáférés elemhez"""
    # Véletlenszerűen választ egy számot a [0, len(nums)-1] intervallumból
    random_index = random.randint(0, len(nums) - 1)
    # A véletlenszerű elemet lekéri és visszaadja
    random_num = nums[random_index]
    return random_num


# Megjegyzés: a Python listája dinamikus tömb, közvetlenül bővíthető
# Tanulási célból ez a függvény a listát megváltoztathatatlan hosszúságú tömbként kezeli
def extend(nums: list[int], enlarge: int) -> list[int]:
    """Tömb hosszának bővítése"""
    # Bővített hosszúságú tömb inicializálása
    res = [0] * (len(nums) + enlarge)
    # Az eredeti tömb összes elemét az új tömbbe másolja
    for i in range(len(nums)):
        res[i] = nums[i]
    # A bővített új tömböt visszaadja
    return res


def insert(nums: list[int], num: int, index: int):
    """A num elemet az index pozícióba szúrja be a tömbben"""
    # Az index pozíciótól kezdve minden elemet egy hellyel hátrébb mozgat
    for i in range(len(nums) - 1, index, -1):
        nums[i] = nums[i - 1]
    # A num értéket az index pozícióba rendeli
    nums[index] = num


def remove(nums: list[int], index: int):
    """Az index pozícióban lévő elemet törli"""
    # Az index utáni összes elemet egy hellyel előrébb mozgat
    for i in range(index, len(nums) - 1):
        nums[i] = nums[i + 1]


def traverse(nums: list[int]):
    """Tömb bejárása"""
    count = 0
    # Tömb bejárása index szerint
    for i in range(len(nums)):
        count += nums[i]
    # Tömb elemeinek közvetlen bejárása
    for num in nums:
        count += num
    # Adat-index és elemek egyidejű bejárása
    for i, num in enumerate(nums):
        count += nums[i]
        count += num


def find(nums: list[int], target: int) -> int:
    """A megadott elem keresése a tömbben"""
    for i in range(len(nums)):
        if nums[i] == target:
            return i
    return -1


"""Fő kód"""
if __name__ == "__main__":
    # Tömb inicializálása
    arr = [0] * 5
    print("Tömb arr =", arr)
    nums = [1, 3, 2, 5, 4]
    print("Tömb nums =", nums)

    # Véletlenszerű hozzáférés
    random_num: int = random_access(nums)
    print("Véletlenszerű elem lekérése a nums-ból:", random_num)

    # Hossz bővítése
    nums: list[int] = extend(nums, 3)
    print("A tömb hosszának 8-ra bővítése után nums =", nums)

    # Elem beszúrása
    insert(nums, 6, 3)
    print("A 6-os szám 3-as indexre szúrása után nums =", nums)

    # Elem törlése
    remove(nums, 2)
    print("A 2-es indexű elem törlése után nums =", nums)

    # Tömb bejárása
    traverse(nums)

    # Elem keresése
    index: int = find(nums, 3)
    print("A 3-as elem keresése a nums-ban, index =", index)
