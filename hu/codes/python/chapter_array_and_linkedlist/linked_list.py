"""
File: linked_list.py
Created Time: 2022-11-25
Author: krahets (krahets@163.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import ListNode, print_linked_list


def insert(n0: ListNode, P: ListNode):
    """P csomópontot az n0 csomópont után szúrja be a láncolt listába"""
    n1 = n0.next
    P.next = n1
    n0.next = P


def remove(n0: ListNode):
    """Az n0 csomópont utáni első csomópontot törli a láncolt listából"""
    if not n0.next:
        return
    # n0 -> P -> n1
    P = n0.next
    n1 = P.next
    n0.next = n1


def access(head: ListNode, index: int) -> ListNode | None:
    """A láncolt lista index pozíciójában lévő csomópontot adja vissza"""
    for _ in range(index):
        if not head:
            return None
        head = head.next
    return head


def find(head: ListNode, target: int) -> int:
    """Megkeresi a target értékű első csomópont indexét a láncolt listában"""
    index = 0
    while head:
        if head.val == target:
            return index
        head = head.next
        index += 1
    return -1


"""Fő kód"""
if __name__ == "__main__":
    # Láncolt lista inicializálása
    # Minden csomópont inicializálása
    n0 = ListNode(1)
    n1 = ListNode(3)
    n2 = ListNode(2)
    n3 = ListNode(5)
    n4 = ListNode(4)
    # Csomópontok közötti referenciák felépítése
    n0.next = n1
    n1.next = n2
    n2.next = n3
    n3.next = n4
    print("Az inicializált láncolt lista:")
    print_linked_list(n0)

    # Csomópont beszúrása
    p = ListNode(0)
    insert(n0, p)
    print("Csomópont beszúrása utáni láncolt lista:")
    print_linked_list(n0)

    # Csomópont törlése
    remove(n0)
    print("Csomópont törlése utáni láncolt lista:")
    print_linked_list(n0)

    # Csomópont elérése
    node: ListNode = access(n0, 3)
    print("A 3-as indexű csomópont értéke a láncolt listában = {}".format(node.val))

    # Csomópont keresése
    index: int = find(n0, 2)
    print("A 2-es értékű csomópont indexe a láncolt listában = {}".format(index))
