"""
File: array_stack.py
Created Time: 2022-11-29
Author: Peng Chen (pengchzn@gmail.com)
"""


class ArrayStack:
    """Tömbön alapuló verem implementáció"""

    def __init__(self):
        """Konstruktor"""
        self._stack: list[int] = []

    def size(self) -> int:
        """A verem hosszának lekérése"""
        return len(self._stack)

    def is_empty(self) -> bool:
        """Ellenőrzi, hogy a verem üres-e"""
        return self.size() == 0

    def push(self, item: int):
        """Push (elem betolása)"""
        self._stack.append(item)

    def pop(self) -> int:
        """Pop (elem kivétele)"""
        if self.is_empty():
            raise IndexError("A verem üres")
        return self._stack.pop()

    def peek(self) -> int:
        """A verem tetején lévő elem elérése"""
        if self.is_empty():
            raise IndexError("A verem üres")
        return self._stack[-1]

    def to_list(self) -> list[int]:
        """Lista visszaadása nyomtatáshoz"""
        return self._stack


"""Fő kód"""
if __name__ == "__main__":
    # Verem inicializálása
    stack = ArrayStack()

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
