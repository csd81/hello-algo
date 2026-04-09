"""
File: my_list.py
Created Time: 2022-11-25
Author: krahets (krahets@163.com)
"""


class MyList:
    """Lista osztály"""

    def __init__(self):
        """Konstruktor"""
        self._capacity: int = 10  # Lista kapacitása
        self._arr: list[int] = [0] * self._capacity  # Tömb (lista elemeit tárolja)
        self._size: int = 0  # Lista hossza (jelenlegi elemszám)
        self._extend_ratio: int = 2  # A lista kapacitásának bővítési szorzója

    def size(self) -> int:
        """Lista hosszának lekérése (jelenlegi elemszám)"""
        return self._size

    def capacity(self) -> int:
        """Lista kapacitásának lekérése"""
        return self._capacity

    def get(self, index: int) -> int:
        """Elem elérése"""
        # Ha az index határon kívül van, kivételt dob, az alábbiak szerint
        if index < 0 or index >= self._size:
            raise IndexError("Index határon kívül")
        return self._arr[index]

    def set(self, num: int, index: int):
        """Elem frissítése"""
        if index < 0 or index >= self._size:
            raise IndexError("Index határon kívül")
        self._arr[index] = num

    def add(self, num: int):
        """Elem hozzáadása a véghez"""
        # Ha az elemek száma meghaladja a kapacitást, bővítési mechanizmust vált ki
        if self.size() == self.capacity():
            self.extend_capacity()
        self._arr[self._size] = num
        self._size += 1

    def insert(self, num: int, index: int):
        """Elem beszúrása a közepére"""
        if index < 0 or index >= self._size:
            raise IndexError("Index határon kívül")
        # Ha az elemek száma meghaladja a kapacitást, bővítési mechanizmust vált ki
        if self._size == self.capacity():
            self.extend_capacity()
        # Az index pozíciótól kezdve minden elemet egy hellyel hátrébb mozgat
        for j in range(self._size - 1, index - 1, -1):
            self._arr[j + 1] = self._arr[j]
        self._arr[index] = num
        # Az elemszám frissítése
        self._size += 1

    def remove(self, index: int) -> int:
        """Elem törlése"""
        if index < 0 or index >= self._size:
            raise IndexError("Index határon kívül")
        num = self._arr[index]
        # Az index utáni összes elemet egy hellyel előrébb mozgat
        for j in range(index, self._size - 1):
            self._arr[j] = self._arr[j + 1]
        # Az elemszám frissítése
        self._size -= 1
        # A törölt elemet visszaadja
        return num

    def extend_capacity(self):
        """Lista kapacitásának bővítése"""
        # Egy új tömböt hoz létre, amely _extend_ratio-szorosára bővíti az eredeti tömböt, majd az eredetit az újba másolja
        self._arr = self._arr + [0] * self.capacity() * (self._extend_ratio - 1)
        # Lista kapacitásának frissítése
        self._capacity = len(self._arr)

    def to_array(self) -> list[int]:
        """Érvényes hosszúságú lista visszaadása"""
        return self._arr[: self._size]


"""Fő kód"""
if __name__ == "__main__":
    # Lista inicializálása
    nums = MyList()
    # Elemek hozzáadása a véghez
    nums.add(1)
    nums.add(3)
    nums.add(2)
    nums.add(5)
    nums.add(4)
    print(f"Lista nums = {nums.to_array()}, kapacitás = {nums.capacity()}, hossz = {nums.size()}")

    # Elem beszúrása a közepére
    nums.insert(6, index=3)
    print("A 6-os szám 3-as indexre szúrása után nums =", nums.to_array())

    # Elem törlése
    nums.remove(3)
    print("A 3-as indexű elem törlése után nums =", nums.to_array())

    # Elem elérése
    num = nums.get(1)
    print("Az 1-es indexű elem elérése, num =", num)

    # Elem frissítése
    nums.set(0, 1)
    print("Az 1-es indexű elem 0-ra frissítése után nums =", nums.to_array())

    # Bővítési mechanizmus tesztelése
    for i in range(10):
        # i = 5-nél a lista hossza meghaladja a kapacitást, és bővítési mechanizmus aktiválódik
        nums.add(i)
    print(f"Bővítés utáni lista {nums.to_array()}, kapacitás = {nums.capacity()}, hossz = {nums.size()}")
