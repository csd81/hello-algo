"""
File: linkedlist_queue.py
Created Time: 2022-12-01
Author: Peng Chen (pengchzn@gmail.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import ListNode


class LinkedListQueue:
    """Láncolt listán alapuló sor implementáció"""

    def __init__(self):
        """Konstruktor"""
        self._front: ListNode | None = None  # Fejcsomópont (sor eleje)
        self._rear: ListNode | None = None  # Farokcsomópont (sor vége)
        self._size: int = 0

    def size(self) -> int:
        """A sor hosszának lekérése"""
        return self._size

    def is_empty(self) -> bool:
        """Ellenőrzi, hogy a sor üres-e"""
        return self._size == 0

    def push(self, num: int):
        """Sorba állás (enqueue)"""
        # A num értéket a farokcsomópont után adja hozzá
        node = ListNode(num)
        # Ha a sor üres, mind az elülső, mind a hátsó pointer a csomópontra mutat
        if self._front is None:
            self._front = node
            self._rear = node
        # Ha a sor nem üres, a csomópontot a farokcsomópont után adja hozzá
        else:
            self._rear.next = node
            self._rear = node
        self._size += 1

    def pop(self) -> int:
        """Sorból kivétel (dequeue)"""
        num = self.peek()
        # Fejcsomópont törlése
        self._front = self._front.next
        self._size -= 1
        return num

    def peek(self) -> int:
        """A sor elejét adja vissza"""
        if self.is_empty():
            raise IndexError("A sor üres")
        return self._front.val

    def to_list(self) -> list[int]:
        """Lista formájú konverzió nyomtatáshoz"""
        queue = []
        temp = self._front
        while temp:
            queue.append(temp.val)
            temp = temp.next
        return queue


"""Fő kód"""
if __name__ == "__main__":
    # Sor inicializálása
    queue = LinkedListQueue()

    # Elemek sorba állítása
    queue.push(1)
    queue.push(3)
    queue.push(2)
    queue.push(5)
    queue.push(4)
    print("sor =", queue.to_list())

    # A sor elején lévő elem elérése
    peek: int = queue.peek()
    print("Sor eleje front =", peek)

    # Elem kivétele a sorból
    pop_front: int = queue.pop()
    print("Kivett elem pop =", pop_front)
    print("Kivétel után sor =", queue.to_list())

    # A sor hosszának lekérése
    size: int = queue.size()
    print("Sor hossza size =", size)

    # Ellenőrzi, hogy a sor üres-e
    is_empty: bool = queue.is_empty()
    print("A sor üres-e =", is_empty)
