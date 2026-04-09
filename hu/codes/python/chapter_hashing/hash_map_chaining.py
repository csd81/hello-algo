"""
File: hash_map_chaining.py
Created Time: 2023-06-13
Author: krahets (krahets@163.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from chapter_hashing.array_hash_map import Pair


class HashMapChaining:
    """Láncolással ütközéskezelő hash tábla"""

    def __init__(self):
        """Konstruktor"""
        self.size = 0  # Kulcs-érték párok száma
        self.capacity = 4  # Hash tábla kapacitása
        self.load_thres = 2.0 / 3.0  # Bővítést kiváltó terhelési tényező küszöbértéke
        self.extend_ratio = 2  # Bővítési szorzó
        self.buckets = [[] for _ in range(self.capacity)]  # Vödör tömb

    def hash_func(self, key: int) -> int:
        """Hash függvény"""
        return key % self.capacity

    def load_factor(self) -> float:
        """Terhelési tényező"""
        return self.size / self.capacity

    def get(self, key: int) -> str | None:
        """Lekérdezési művelet"""
        index = self.hash_func(key)
        bucket = self.buckets[index]
        # A vödörön végigmegy, ha megtalálja a kulcsot, visszaadja a megfelelő értéket
        for pair in bucket:
            if pair.key == key:
                return pair.val
        # Ha a kulcs nem található, None-t ad vissza
        return None

    def put(self, key: int, val: str):
        """Hozzáadási művelet"""
        # Ha a terhelési tényező meghaladja a küszöböt, bővítést végez
        if self.load_factor() > self.load_thres:
            self.extend()
        index = self.hash_func(key)
        bucket = self.buckets[index]
        # A vödörön végigmegy, ha megtalálja a megadott kulcsot, frissíti a megfelelő értéket és visszatér
        for pair in bucket:
            if pair.key == key:
                pair.val = val
                return
        # Ha a kulcs nem létezik, a kulcs-érték párt a végéhez fűzi
        pair = Pair(key, val)
        bucket.append(pair)
        self.size += 1

    def remove(self, key: int):
        """Törlési művelet"""
        index = self.hash_func(key)
        bucket = self.buckets[index]
        # A vödörön végigmegy és eltávolítja a kulcs-érték párt
        for pair in bucket:
            if pair.key == key:
                bucket.remove(pair)
                self.size -= 1
                break

    def extend(self):
        """Hash tábla bővítése"""
        # Az eredeti hash tábla ideiglenes tárolása
        buckets = self.buckets
        # A bővített új hash tábla inicializálása
        self.capacity *= self.extend_ratio
        self.buckets = [[] for _ in range(self.capacity)]
        self.size = 0
        # Kulcs-érték párok áthelyezése az eredeti hash táblából az újba
        for bucket in buckets:
            for pair in bucket:
                self.put(pair.key, pair.val)

    def print(self):
        """Hash tábla kiírása"""
        for bucket in self.buckets:
            res = []
            for pair in bucket:
                res.append(str(pair.key) + " -> " + pair.val)
            print(res)


"""Fő kód"""
if __name__ == "__main__":
    # Hash tábla inicializálása
    hashmap = HashMapChaining()

    # Hozzáadás
    # Kulcs-érték pár (kulcs, érték) hozzáadása a hash táblához
    hashmap.put(12836, "Xiao Ha")
    hashmap.put(15937, "Xiao Luo")
    hashmap.put(16750, "Xiao Suan")
    hashmap.put(13276, "Xiao Fa")
    hashmap.put(10583, "Xiao Ya")
    print("\nHozzáadás után a hash tábla:\n[Kulcs1 -> Érték1, Kulcs2 -> Érték2, ...]")
    hashmap.print()

    # Lekérdezés
    # Kulcs beírása a hash táblába az érték lekérdezéséhez
    name = hashmap.get(13276)
    print("\nA 13276-os diákigazolvány alapján a név: " + name)

    # Törlés
    # Kulcs-érték pár (kulcs, érték) törlése a hash táblából
    hashmap.remove(12836)
    print("\nA 12836-os törlése után a hash tábla:\n[Kulcs1 -> Érték1, Kulcs2 -> Érték2, ...]")
    hashmap.print()
