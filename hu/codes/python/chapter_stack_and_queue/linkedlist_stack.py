"""
File: linkedlist_stack.py
Created Time: 2022-11-29
Author: Peng Chen (pengchzn@gmail.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import ListNode


class LinkedListStack:
    """Láncolt listán alapuló verem implementáció"""

    def __init__(self):
        """Konstruktor"""
        self._peek: ListNode | None = None
        self._size: int = 0

    def size(self) -> int:
        """A verem hosszának lekérése"""
        return self._size

    def is_empty(self) -> bool:
        """Ellenőrzi, hogy a verem üres-e"""
        return self._size == 0

    def push(self, val: int):
        """Push (elem betolása)"""
        node = ListNode(val)
        node.next = self._peek
        self._peek = node
        self._size += 1

    def pop(self) -> int:
        """Pop (elem kivétele)"""
        num = self.peek()
        self._peek = self._peek.next
        self._size -= 1
        return num

    def peek(self) -> int:
        """A verem tetején lévő elem elérése"""
        if self.is_empty():
            raise IndexError("A verem üres")
        return self._peek.val

    def to_list(self) -> list[int]:
        """Lista visszaadása nyomtatáshoz"""
        arr = []
        node = self._peek
        while node:
            arr.append(node.val)
            node = node.next
        arr.reverse()
        return arr


"""Fő kód"""
if __name__ == "__main__":
    # Verem inicializálása
    stack = LinkedListStack()

    # Elemek betolása a verembe
    stack.push(1)
    stack.push(3)
    stack.push(2)
    stack.push(5)
    stack.push(4)
    print("verem =", stack.to_list())

    # A verem tetején lévő elem elérése
    peek: int = stack.peek()
    print("Verem teteje elem peek =", peek)

    # Elem kivétele a veremből
    pop: int = stack.pop()
    print("Kivett elem pop =", pop)
    print("Pop után verem =", stack.to_list())

    # A verem hosszának lekérése
    size: int = stack.size()
    print("Verem hossza size =", size)

    # Ellenőrzi, hogy üres-e
    is_empty: bool = stack.is_empty()
    print("A verem üres-e =", is_empty)
