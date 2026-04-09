"""
File: queue.py
Created Time: 2022-11-29
Author: Peng Chen (pengchzn@gmail.com)
"""

from collections import deque

"""Fő kód"""
if __name__ == "__main__":
    # Sor inicializálása
    # Pythonban általában a kétirányú sor (deque) osztályt használjuk sorként
    # Bár a queue.Queue() egy megfelelő sor osztály, nem túl kényelmes használni
    que: deque[int] = deque()

    # Elemek sorba állítása
    que.append(1)
    que.append(3)
    que.append(2)
    que.append(5)
    que.append(4)
    print("sor que =", que)

    # A sor elején lévő elem elérése
    front: int = que[0]
    print("Sor eleje front =", front)

    # Elem kivétele a sorból
    pop: int = que.popleft()
    print("Kivett elem pop =", pop)
    print("Kivétel után que =", que)

    # A sor hosszának lekérése
    size: int = len(que)
    print("Sor hossza size =", size)

    # Ellenőrzi, hogy a sor üres-e
    is_empty: bool = len(que) == 0
    print("A sor üres-e =", is_empty)
