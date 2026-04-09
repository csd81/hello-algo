"""
File: binary_search_tree.py
Created Time: 2022-12-20
Author: a16su (lpluls001@gmail.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import TreeNode, print_tree


class BinarySearchTree:
    """Bináris keresőfa"""

    def __init__(self):
        """Konstruktor"""
        # Üres fa inicializálása
        self._root = None

    def get_root(self) -> TreeNode | None:
        """A bináris fa gyökércsomópontjának lekérése"""
        return self._root

    def search(self, num: int) -> TreeNode | None:
        """Csomópont keresése"""
        cur = self._root
        # Ciklusos keresés, a levélcsomópont után kilép
        while cur is not None:
            # A célcsomópont a cur jobb részfájában van
            if cur.val < num:
                cur = cur.right
            # A célcsomópont a cur bal részfájában van
            elif cur.val > num:
                cur = cur.left
            # Megtalálta a célcsomópontot, kilép a ciklusból
            else:
                break
        return cur

    def insert(self, num: int):
        """Csomópont beszúrása"""
        # Ha a fa üres, a gyökércsomópontot inicializálja
        if self._root is None:
            self._root = TreeNode(num)
            return
        # Ciklusos keresés, a levélcsomópont után kilép
        cur, pre = self._root, None
        while cur is not None:
            # Duplikált csomópont találva, közvetlenül visszatér
            if cur.val == num:
                return
            pre = cur
            # A beszúrási pozíció a cur jobb részfájában van
            if cur.val < num:
                cur = cur.right
            # A beszúrási pozíció a cur bal részfájában van
            else:
                cur = cur.left
        # Csomópont beszúrása
        node = TreeNode(num)
        if pre.val < num:
            pre.right = node
        else:
            pre.left = node

    def remove(self, num: int):
        """Csomópont törlése"""
        # Ha a fa üres, közvetlenül visszatér
        if self._root is None:
            return
        # Ciklusos keresés, a levélcsomópont után kilép
        cur, pre = self._root, None
        while cur is not None:
            # Megtalálta a törlendő csomópontot, kilép a ciklusból
            if cur.val == num:
                break
            pre = cur
            # A törlendő csomópont a cur jobb részfájában van
            if cur.val < num:
                cur = cur.right
            # A törlendő csomópont a cur bal részfájában van
            else:
                cur = cur.left
        # Ha nincs törlendő csomópont, közvetlenül visszatér
        if cur is None:
            return

        # Gyermekek száma = 0 vagy 1
        if cur.left is None or cur.right is None:
            # Ha gyermekek száma = 0 / 1, child = null / az egyetlen gyermek
            child = cur.left or cur.right
            # cur csomópont törlése
            if cur != self._root:
                if pre.left == cur:
                    pre.left = child
                else:
                    pre.right = child
            else:
                # Ha a törölt csomópont a gyökér, a gyökércsomópontot újra hozzárendeli
                self._root = child
        # Gyermekek száma = 2
        else:
            # A cur közrendű bejárásban következő csomópontjának lekérése
            tmp: TreeNode = cur.right
            while tmp.left is not None:
                tmp = tmp.left
            # tmp csomópont rekurzív törlése
            self.remove(tmp.val)
            # cur felváltása tmp-vel
            cur.val = tmp.val


"""Fő kód"""
if __name__ == "__main__":
    # Bináris keresőfa inicializálása
    bst = BinarySearchTree()
    nums = [8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15]
    # Megjegyzés: a különböző beszúrási sorrendek különböző bináris fákat generálnak; ez a sorrend tökéletes bináris fát eredményez
    for num in nums:
        bst.insert(num)
    print("\nAz inicializált bináris fa:\n")
    print_tree(bst.get_root())

    # Csomópont keresése
    node = bst.search(7)
    print("\nA talált csomópont objektum: {}, csomópont értéke = {}".format(node, node.val))

    # Csomópont beszúrása
    bst.insert(16)
    print("\nA 16-os csomópont beszúrása után a bináris fa:\n")
    print_tree(bst.get_root())

    # Csomópont törlése
    bst.remove(1)
    print("\nAz 1-es csomópont törlése után a bináris fa:\n")
    print_tree(bst.get_root())

    bst.remove(2)
    print("\nA 2-es csomópont törlése után a bináris fa:\n")
    print_tree(bst.get_root())

    bst.remove(4)
    print("\nA 4-es csomópont törlése után a bináris fa:\n")
    print_tree(bst.get_root())
