"""
File: linkedlist_deque.py
Created Time: 2023-03-01
Author: krahets (krahets@163.com)
"""


class ListNode:
    """Kétirányú láncolt lista csomópontja"""

    def __init__(self, val: int):
        """Konstruktor"""
        self.val: int = val
        self.next: ListNode | None = None  # Következő csomópontra mutató referencia
        self.prev: ListNode | None = None  # Előző csomópontra mutató referencia


class LinkedListDeque:
    """Kétirányú láncolt listán alapuló kétirányú sor implementáció"""

    def __init__(self):
        """Konstruktor"""
        self._front: ListNode | None = None  # Fejcsomópont (sor eleje)
        self._rear: ListNode | None = None  # Farokcsomópont (sor vége)
        self._size: int = 0  # A kétirányú sor hossza

    def size(self) -> int:
        """A kétirányú sor hosszának lekérése"""
        return self._size

    def is_empty(self) -> bool:
        """Ellenőrzi, hogy a kétirányú sor üres-e"""
        return self._size == 0

    def push(self, num: int, is_front: bool):
        """Sorba állás művelet"""
        node = ListNode(num)
        # Ha a láncolt lista üres, mind a front, mind a rear a csomópontra mutat
        if self.is_empty():
            self._front = self._rear = node
        # Sor elejéhez való sorba állás
        elif is_front:
            # Csomópont hozzáadása a láncolt lista elejéhez
            self._front.prev = node
            node.next = self._front
            self._front = node  # Fejcsomópont frissítése
        # Sor végéhez való sorba állás
        else:
            # Csomópont hozzáadása a láncolt lista végéhez
            self._rear.next = node
            node.prev = self._rear
            self._rear = node  # Farokcsomópont frissítése
        self._size += 1  # Sor hosszának frissítése

    def push_first(self, num: int):
        """Sor elejére való sorba állás"""
        self.push(num, True)

    def push_last(self, num: int):
        """Sor végére való sorba állás"""
        self.push(num, False)

    def pop(self, is_front: bool) -> int:
        """Sorból kivétel művelet"""
        if self.is_empty():
            raise IndexError("A kétirányú sor üres")
        # Sor elejéről való kivétel
        if is_front:
            val: int = self._front.val  # Fejcsomópont értékének ideiglenes tárolása
            # Fejcsomópont törlése
            fnext: ListNode | None = self._front.next
            if fnext is not None:
                fnext.prev = None
                self._front.next = None
            self._front = fnext  # Fejcsomópont frissítése
        # Sor végéről való kivétel
        else:
            val: int = self._rear.val  # Farokcsomópont értékének ideiglenes tárolása
            # Farokcsomópont törlése
            rprev: ListNode | None = self._rear.prev
            if rprev is not None:
                rprev.next = None
                self._rear.prev = None
            self._rear = rprev  # Farokcsomópont frissítése
        self._size -= 1  # Sor hosszának frissítése
        return val

    def pop_first(self) -> int:
        """Sor elejéről való kivétel"""
        return self.pop(True)

    def pop_last(self) -> int:
        """Sor végéről való kivétel"""
        return self.pop(False)

    def peek_first(self) -> int:
        """A sor elejének eleme"""
        if self.is_empty():
            raise IndexError("A kétirányú sor üres")
        return self._front.val

    def peek_last(self) -> int:
        """A sor végének eleme"""
        if self.is_empty():
            raise IndexError("A kétirányú sor üres")
        return self._rear.val

    def to_array(self) -> list[int]:
        """Tömb visszaadása nyomtatáshoz"""
        node = self._front
        res = [0] * self.size()
        for i in range(self.size()):
            res[i] = node.val
            node = node.next
        return res


"""Fő kód"""
if __name__ == "__main__":
    # Kétirányú sor inicializálása
    deque = LinkedListDeque()
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
