"""
File: array_hash_map.py
Created Time: 2022-12-14
Author: msk397 (machangxinq@gmail.com)
"""


class Pair:
    """Kulcs-érték pár"""

    def __init__(self, key: int, val: str):
        self.key = key
        self.val = val


class ArrayHashMap:
    """Tömbön alapuló hash tábla implementáció"""

    def __init__(self):
        """Konstruktor"""
        # Tömb inicializálása 100 vödörrel
        self.buckets: list[Pair | None] = [None] * 100

    def hash_func(self, key: int) -> int:
        """Hash függvény"""
        index = key % 100
        return index

    def get(self, key: int) -> str | None:
        """Lekérdezési művelet"""
        index: int = self.hash_func(key)
        pair: Pair = self.buckets[index]
        if pair is None:
            return None
        return pair.val

    def put(self, key: int, val: str):
        """Hozzáadás és frissítés"""
        pair = Pair(key, val)
        index: int = self.hash_func(key)
        self.buckets[index] = pair

    def remove(self, key: int):
        """Törlési művelet"""
        index: int = self.hash_func(key)
        # None-ra állítja a törlés jelölésére
        self.buckets[index] = None

    def entry_set(self) -> list[Pair]:
        """Az összes kulcs-érték pár lekérése"""
        result: list[Pair] = []
        for pair in self.buckets:
            if pair is not None:
                result.append(pair)
        return result

    def key_set(self) -> list[int]:
        """Az összes kulcs lekérése"""
        result = []
        for pair in self.buckets:
            if pair is not None:
                result.append(pair.key)
        return result

    def value_set(self) -> list[str]:
        """Az összes érték lekérése"""
        result = []
        for pair in self.buckets:
            if pair is not None:
                result.append(pair.val)
        return result

    def print(self):
        """Hash tábla kiírása"""
        for pair in self.buckets:
            if pair is not None:
                print(pair.key, "->", pair.val)


"""Fő kód"""
if __name__ == "__main__":
    # Hash tábla inicializálása
    hmap = ArrayHashMap()

    # Hozzáadás
    # Kulcs-érték pár (kulcs, érték) hozzáadása a hash táblához
    hmap.put(12836, "Xiao Ha")
    hmap.put(15937, "Xiao Luo")
    hmap.put(16750, "Xiao Suan")
    hmap.put(13276, "Xiao Fa")
    hmap.put(10583, "Xiao Ya")
    print("\nHozzáadás után a hash tábla:\nKulcs -> Érték")
    hmap.print()

    # Lekérdezés
    # Kulcs beírása a hash táblába az érték lekérdezéséhez
    name = hmap.get(15937)
    print("\nA 15937-es diákigazolvány alapján a név: " + name)

    # Törlés
    # Kulcs-érték pár (kulcs, érték) törlése a hash táblából
    hmap.remove(10583)
    print("\nA 10583-as törlése után a hash tábla:\nKulcs -> Érték")
    hmap.print()

    # Hash tábla bejárása
    print("\nKulcs-érték párok bejárása Kulcs->Érték")
    for pair in hmap.entry_set():
        print(pair.key, "->", pair.val)

    print("\nCsak kulcsok bejárása")
    for key in hmap.key_set():
        print(key)

    print("\nCsak értékek bejárása")
    for val in hmap.value_set():
        print(val)
