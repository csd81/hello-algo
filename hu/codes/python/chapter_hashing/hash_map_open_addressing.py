"""
File: hash_map_open_addressing.py
Created Time: 2023-06-13
Author: krahets (krahets@163.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from chapter_hashing.array_hash_map import Pair


class HashMapOpenAddressing:
    """Nyílt címzéssel ütközéskezelő hash tábla"""

    def __init__(self):
        """Konstruktor"""
        self.size = 0  # Kulcs-érték párok száma
        self.capacity = 4  # Hash tábla kapacitása
        self.load_thres = 2.0 / 3.0  # Bővítést kiváltó terhelési tényező küszöbértéke
        self.extend_ratio = 2  # Bővítési szorzó
        self.buckets: list[Pair | None] = [None] * self.capacity  # Vödör tömb
        self.TOMBSTONE = Pair(-1, "-1")  # Törlésjelző

    def hash_func(self, key: int) -> int:
        """Hash függvény"""
        return key % self.capacity

    def load_factor(self) -> float:
        """Terhelési tényező"""
        return self.size / self.capacity

    def find_bucket(self, key: int) -> int:
        """A kulcshoz tartozó vödör indexének keresése"""
        index = self.hash_func(key)
        first_tombstone = -1
        # Lineáris próba, üres vödörnél megáll
        while self.buckets[index] is not None:
            # Ha megtalálja a kulcsot, visszaadja a megfelelő vödör indexét
            if self.buckets[index].key == key:
                # Ha korábban törlésjelzőt talált, a kulcs-érték párt arra az indexre helyezi
                if first_tombstone != -1:
                    self.buckets[first_tombstone] = self.buckets[index]
                    self.buckets[index] = self.TOMBSTONE
                    return first_tombstone  # Az áthelyezett vödör indexét adja vissza
                return index  # Vödör indexét adja vissza
            # Az első törlésjelző rögzítése
            if first_tombstone == -1 and self.buckets[index] is self.TOMBSTONE:
                first_tombstone = index
            # Vödör indexének kiszámítása, körbe fordul ha túlmegy a végén
            index = (index + 1) % self.capacity
        # Ha a kulcs nem létezik, a beszúrási indexet adja vissza
        return index if first_tombstone == -1 else first_tombstone

    def get(self, key: int) -> str:
        """Lekérdezési művelet"""
        # A kulcshoz tartozó vödör indexének keresése
        index = self.find_bucket(key)
        # Ha megtalálja a kulcs-érték párt, visszaadja a megfelelő értéket
        if self.buckets[index] not in [None, self.TOMBSTONE]:
            return self.buckets[index].val
        # Ha a kulcs-érték pár nem létezik, None-t ad vissza
        return None

    def put(self, key: int, val: str):
        """Hozzáadási művelet"""
        # Ha a terhelési tényező meghaladja a küszöböt, bővítést végez
        if self.load_factor() > self.load_thres:
            self.extend()
        # A kulcshoz tartozó vödör indexének keresése
        index = self.find_bucket(key)
        # Ha megtalálja a kulcs-érték párt, felülírja az értéket és visszatér
        if self.buckets[index] not in [None, self.TOMBSTONE]:
            self.buckets[index].val = val
            return
        # Ha a kulcs-érték pár nem létezik, hozzáadja
        self.buckets[index] = Pair(key, val)
        self.size += 1

    def remove(self, key: int):
        """Törlési művelet"""
        # A kulcshoz tartozó vödör indexének keresése
        index = self.find_bucket(key)
        # Ha megtalálja a kulcs-érték párt, törlésjelzővel helyettesíti
        if self.buckets[index] not in [None, self.TOMBSTONE]:
            self.buckets[index] = self.TOMBSTONE
            self.size -= 1

    def extend(self):
        """Hash tábla bővítése"""
        # Az eredeti hash tábla ideiglenes tárolása
        buckets_tmp = self.buckets
        # A bővített új hash tábla inicializálása
        self.capacity *= self.extend_ratio
        self.buckets = [None] * self.capacity
        self.size = 0
        # Kulcs-érték párok áthelyezése az eredeti hash táblából az újba
        for pair in buckets_tmp:
            if pair not in [None, self.TOMBSTONE]:
                self.put(pair.key, pair.val)

    def print(self):
        """Hash tábla kiírása"""
        for pair in self.buckets:
            if pair is None:
                print("None")
            elif pair is self.TOMBSTONE:
                print("TOMBSTONE")
            else:
                print(pair.key, "->", pair.val)


"""Fő kód"""
if __name__ == "__main__":
    # Hash tábla inicializálása
    hashmap = HashMapOpenAddressing()

    # Hozzáadás
    # Kulcs-érték pár (kulcs, érték) hozzáadása a hash táblához
    hashmap.put(12836, "Xiao Ha")
    hashmap.put(15937, "Xiao Luo")
    hashmap.put(16750, "Xiao Suan")
    hashmap.put(13276, "Xiao Fa")
    hashmap.put(10583, "Xiao Ya")
    print("\nHozzáadás után a hash tábla:\nKulcs -> Érték")
    hashmap.print()

    # Lekérdezés
    # Kulcs beírása a hash táblába az érték lekérdezéséhez
    name = hashmap.get(13276)
    print("\nA 13276-os diákigazolvány alapján a név: " + name)

    # Törlés
    # Kulcs-érték pár (kulcs, érték) törlése a hash táblából
    hashmap.remove(16750)
    print("\nA 16750-es törlése után a hash tábla:\nKulcs -> Érték")
    hashmap.print()
