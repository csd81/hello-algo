"""
File: array_queue.py
Created Time: 2022-12-01
Author: Peng Chen (pengchzn@gmail.com)
"""


class ArrayQueue:
    """Körkörös tömbön alapuló sor implementáció"""

    def __init__(self, size: int):
        """Konstruktor"""
        self._nums: list[int] = [0] * size  # A sor elemeit tároló tömb
        self._front: int = 0  # Sor elejére mutató pointer
        self._size: int = 0  # Sor hossza

    def capacity(self) -> int:
        """A sor kapacitásának lekérése"""
        return len(self._nums)

    def size(self) -> int:
        """A sor hosszának lekérése"""
        return self._size

    def is_empty(self) -> bool:
        """Ellenőrzi, hogy a sor üres-e"""
        return self._size == 0

    def push(self, num: int):
        """Sorba állás (enqueue)"""
        if self._size == self.capacity():
            raise IndexError("A sor tele van")
        # Hátsó pointer kiszámítása, a hátsó index + 1-re mutat
        # Moduló operátorral a hátsó pointer körbe fordul a tömb végén
        rear: int = (self._front + self._size) % self.capacity()
        # A num értéket a sor végéhez adja
        self._nums[rear] = num
        self._size += 1

    def pop(self) -> int:
        """Sorból kivétel (dequeue)"""
        num: int = self.peek()
        # Az elülső pointer egy hellyel hátrább lép; ha túllép a végén, visszatér a tömb elejére
        self._front = (self._front + 1) % self.capacity()
        self._size -= 1
        return num

    def peek(self) -> int:
        """A sor elejét adja vissza"""
        if self.is_empty():
            raise IndexError("A sor üres")
        return self._nums[self._front]

    def to_list(self) -> list[int]:
        """Lista visszaadása nyomtatáshoz"""
        res = [0] * self.size()
        j: int = self._front
        for i in range(self.size()):
            res[i] = self._nums[(j % self.capacity())]
            j += 1
        return res


"""Fő kód"""
if __name__ == "__main__":
    # Sor inicializálása
    queue = ArrayQueue(10)

    # Elemek sorba állítása
    queue.push(1)
    queue.push(3)
    queue.push(2)
    queue.push(5)
    queue.push(4)
    print("sor =", queue.to_list())

    # A sor elején lévő elem elérése
    peek: int = queue.peek()
    print("Sor eleje peek =", peek)

    # Elem kivétele a sorból
    pop: int = queue.pop()
    print("Kivett elem pop =", pop)
    print("Kivétel után sor =", queue.to_list())

    # A sor hosszának lekérése
    size: int = queue.size()
    print("Sor hossza size =", size)

    # Ellenőrzi, hogy a sor üres-e
    is_empty: bool = queue.is_empty()
    print("A sor üres-e =", is_empty)

    # Körkörös tömb tesztelése
    for i in range(10):
        queue.push(i)
        queue.pop()
        print("Forduló", i, "sorba állás + kivétel után sor = ", queue.to_list())
