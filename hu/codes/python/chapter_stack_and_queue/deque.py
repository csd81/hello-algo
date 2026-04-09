"""
File: deque.py
Created Time: 2022-11-29
Author: Peng Chen (pengchzn@gmail.com)
"""

from collections import deque

"""Fő kód"""
if __name__ == "__main__":
    # Kétirányú sor inicializálása
    deq: deque[int] = deque()

    # Elemek sorba állítása
    deq.append(2)  # Hozzáadás a sor végéhez
    deq.append(5)
    deq.append(4)
    deq.appendleft(3)  # Hozzáadás a sor elejéhez
    deq.appendleft(1)
    print("kétirányú sor deque =", deq)

    # Elemek elérése
    front: int = deq[0]  # A sor elejének eleme
    print("Sor eleje front =", front)
    rear: int = deq[-1]  # A sor végének eleme
    print("Sor vége rear =", rear)

    # Elemek kivétele
    pop_front: int = deq.popleft()  # Az sor elejéről kivétel
    print("Sor elejéről kivett elem pop_front =", pop_front)
    print("Sor elejéről kivétel után deque =", deq)
    pop_rear: int = deq.pop()  # A sor végéről kivétel
    print("Sor végéről kivett elem pop_rear =", pop_rear)
    print("Sor végéről kivétel után deque =", deq)

    # A kétirányú sor hosszának lekérése
    size: int = len(deq)
    print("Kétirányú sor hossza size =", size)

    # Ellenőrzi, hogy a kétirányú sor üres-e
    is_empty: bool = len(deq) == 0
    print("A kétirányú sor üres-e =", is_empty)
