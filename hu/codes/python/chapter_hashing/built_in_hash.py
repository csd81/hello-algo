"""
File: built_in_hash.py
Created Time: 2023-06-15
Author: krahets (krahets@163.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import ListNode

"""Fő kód"""
if __name__ == "__main__":
    num = 3
    hash_num = hash(num)
    print(f"A(z) {num} egész szám hash értéke: {hash_num}")

    bol = True
    hash_bol = hash(bol)
    print(f"A(z) {bol} logikai érték hash értéke: {hash_bol}")

    dec = 3.14159
    hash_dec = hash(dec)
    print(f"A(z) {dec} tizedes tört hash értéke: {hash_dec}")

    str = "Hello algo"
    hash_str = hash(str)
    print(f"A(z) {str} karakterlánc hash értéke: {hash_str}")

    tup = (12836, "Xiao Ha")
    hash_tup = hash(tup)
    print(f"A(z) {tup} tuple hash értéke: {hash(hash_tup)}")

    obj = ListNode(0)
    hash_obj = hash(obj)
    print(f"A(z) {obj} csomópont objektum hash értéke: {hash_obj}")
