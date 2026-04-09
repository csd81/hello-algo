"""
File: array_deque.py
Created Time: 2023-03-01
Author: krahets (krahets@163.com)
"""


class ArrayDeque:
    """Körkörös tömbön alapuló kétirányú sor implementáció"""

    def __init__(self, capacity: int):
        """Konstruktor"""
        self._nums: list[int] = [0] * capacity
        self._front: int = 0
        self._size: int = 0

    def capacity(self) -> int:
        """A kétirányú sor kapacitásának lekérése"""
        return len(self._nums)

    def size(self) -> int:
        """A kétirányú sor hosszának lekérése"""
        return self._size

    def is_empty(self) -> bool:
        """Ellenőrzi, hogy a kétirányú sor üres-e"""
        return self._size == 0

    def index(self, i: int) -> int:
        """Körkörös tömb indexének kiszámítása"""
        # Moduló operátorral a tömb eleje és vége összekapcsolódik
        # Ha i túlmegy a tömb végén, visszatér az elejére
        # Ha i túlmegy a tömb elejére, visszatér a végére
        return (i + self.capacity()) % self.capacity()

    def push_first(self, num: int):
        """Sor elejéhez való sorba állás"""
        if self._size == self.capacity():
            print("A kétirányú sor tele van")
            return
        # Az elülső pointer egy hellyel balra lép
        # Moduló operátorral az elülső pointer körbe fordul a tömb végére, ha túlmegy az elejére
        self._front = self.index(self._front - 1)
        # A num értéket a sor elejéhez adja
        self._nums[self._front] = num
        self._size += 1

    def push_last(self, num: int):
        """Sor végéhez való sorba állás"""
        if self._size == self.capacity():
            print("A kétirányú sor tele van")
            return
        # Hátsó pointer kiszámítása, a hátsó index + 1-re mutat
        rear = self.index(self._front + self._size)
        # A num értéket a sor végéhez adja
        self._nums[rear] = num
        self._size += 1

    def pop_first(self) -> int:
        """Sor elejéről való kivétel"""
        num = self.peek_first()
        # Az elülső pointer egy hellyel hátrább lép
        self._front = self.index(self._front + 1)
        self._size -= 1
        return num

    def pop_last(self) -> int:
        """Sor végéről való kivétel"""
        num = self.peek_last()
        self._size -= 1
        return num

    def peek_first(self) -> int:
        """A sor elejének eleme"""
        if self.is_empty():
            raise IndexError("A kétirányú sor üres")
        return self._nums[self._front]

    def peek_last(self) -> int:
        """A sor végének eleme"""
        if self.is_empty():
            raise IndexError("A kétirányú sor üres")
        # Az utolsó elem indexének kiszámítása
        last = self.index(self._front + self._size - 1)
        return self._nums[last]

    def to_array(self) -> list[int]:
        """Tömb visszaadása nyomtatáshoz"""
        # Csak az érvényes hossztartományon belüli lista elemeit konvertálja
        res = []
        for i in range(self._size):
            res.append(self._nums[self.index(self._front + i)])
        return res


"""Fő kód"""
if __name__ == "__main__":
    # Kétirányú sor inicializálása
    deque = ArrayDeque(10)
    deque.push_last(3)
    deque.push_last(2)
    deque.push_last(5)
    print("kétirányú sor deque =", deque.to_array())

    # Elemek elérése
    peek_first: int = deque.peek_first()
    print("Sor eleje peek_first =", peek_first)
    peek_last: int = deque.peek_last()
    print("Sor vége peek_last =", peek_last)

    # Elemek sorba állítása
    deque.push_last(4)
    print("A 4-es elem sor végéhez adása után deque =", deque.to_array())
    deque.push_first(1)
    print("Az 1-es elem sor elejéhez adása után deque =", deque.to_array())

    # Elemek kivétele
    pop_last: int = deque.pop_last()
    print("Sor végéről kivett elem =", pop_last, ", sor végéről kivétel után deque =", deque.to_array())
    pop_first: int = deque.pop_first()
    print("Sor elejéről kivett elem =", pop_first, ", sor elejéről kivétel után deque =", deque.to_array())

    # A kétirányú sor hosszának lekérése
    size: int = deque.size()
    print("Kétirányú sor hossza size =", size)

    # Ellenőrzi, hogy a kétirányú sor üres-e
    is_empty: bool = deque.is_empty()
    print("A kétirányú sor üres-e =", is_empty)
