"""
File: stack.py
Created Time: 2022-11-29
Author: Peng Chen (pengchzn@gmail.com)
"""

"""Fő kód"""
if __name__ == "__main__":
    # Verem inicializálása
    # A Pythonban nincs beépített verem osztály, listát használunk veremként
    stack: list[int] = []

    # Elemek betolása a verembe
    stack.append(1)
    stack.append(3)
    stack.append(2)
    stack.append(5)
    stack.append(4)
    print("verem =", stack)

    # A verem tetején lévő elem elérése
    peek: int = stack[-1]
    print("Verem teteje elem peek =", peek)

    # Elem kivétele a veremből
    pop: int = stack.pop()
    print("Kivett elem pop =", pop)
    print("Pop után verem =", stack)

    # A verem hosszának lekérése
    size: int = len(stack)
    print("Verem hossza size =", size)

    # Ellenőrzi, hogy üres-e
    is_empty: bool = len(stack) == 0
    print("A verem üres-e =", is_empty)
