"""
File: avl_tree.py
Created Time: 2022-12-20
Author: a16su (lpluls001@gmail.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import TreeNode, print_tree


class AVLTree:
    """AVL fa"""

    def __init__(self):
        """Konstruktor"""
        self._root = None

    def get_root(self) -> TreeNode | None:
        """A bináris fa gyökércsomópontjának lekérése"""
        return self._root

    def height(self, node: TreeNode | None) -> int:
        """Csomópont magasságának lekérése"""
        # Az üres csomópont magassága -1, a levélcsomóponté 0
        if node is not None:
            return node.height
        return -1

    def update_height(self, node: TreeNode | None):
        """Csomópont magasságának frissítése"""
        # A csomópont magassága = a legmagasabb részfa magassága + 1
        node.height = max([self.height(node.left), self.height(node.right)]) + 1

    def balance_factor(self, node: TreeNode | None) -> int:
        """Egyensúlyi tényező lekérése"""
        # Az üres csomópont egyensúlyi tényezője 0
        if node is None:
            return 0
        # Csomópont egyensúlyi tényezője = bal részfa magassága - jobb részfa magassága
        return self.height(node.left) - self.height(node.right)

    def right_rotate(self, node: TreeNode | None) -> TreeNode | None:
        """Jobbra forgatás"""
        child = node.left
        grand_child = child.right
        # A child-ot forgáspontként használva a node-ot jobbra forgatja
        child.right = node
        node.left = grand_child
        # Csomópont magasságának frissítése
        self.update_height(node)
        self.update_height(child)
        # A forgatás utáni részfa gyökércsomópontját adja vissza
        return child

    def left_rotate(self, node: TreeNode | None) -> TreeNode | None:
        """Balra forgatás"""
        child = node.right
        grand_child = child.left
        # A child-ot forgáspontként használva a node-ot balra forgatja
        child.left = node
        node.right = grand_child
        # Csomópont magasságának frissítése
        self.update_height(node)
        self.update_height(child)
        # A forgatás utáni részfa gyökércsomópontját adja vissza
        return child

    def rotate(self, node: TreeNode | None) -> TreeNode | None:
        """Forgatás végrehajtása a részfa egyensúlyának helyreállításához"""
        # Csomópont egyensúlyi tényezőjének lekérése
        balance_factor = self.balance_factor(node)
        # Bal oldali túlsúly
        if balance_factor > 1:
            if self.balance_factor(node.left) >= 0:
                # Jobbra forgatás
                return self.right_rotate(node)
            else:
                # Előbb balra, majd jobbra forgatás
                node.left = self.left_rotate(node.left)
                return self.right_rotate(node)
        # Jobb oldali túlsúly
        elif balance_factor < -1:
            if self.balance_factor(node.right) <= 0:
                # Balra forgatás
                return self.left_rotate(node)
            else:
                # Előbb jobbra, majd balra forgatás
                node.right = self.right_rotate(node.right)
                return self.left_rotate(node)
        # Kiegyensúlyozott fa, nincs szükség forgatásra, közvetlenül visszaadja
        return node

    def insert(self, val):
        """Csomópont beszúrása"""
        self._root = self.insert_helper(self._root, val)

    def insert_helper(self, node: TreeNode | None, val: int) -> TreeNode:
        """Rekurzív csomópont-beszúrás (segédmetódus)"""
        if node is None:
            return TreeNode(val)
        # 1. Beszúrási pozíció keresése és csomópont beszúrása
        if val < node.val:
            node.left = self.insert_helper(node.left, val)
        elif val > node.val:
            node.right = self.insert_helper(node.right, val)
        else:
            # Duplikált csomópont nem kerül be, közvetlenül visszaadja
            return node
        # Csomópont magasságának frissítése
        self.update_height(node)
        # 2. Forgatás végrehajtása a részfa egyensúlyának helyreállításához
        return self.rotate(node)

    def remove(self, val: int):
        """Csomópont törlése"""
        self._root = self.remove_helper(self._root, val)

    def remove_helper(self, node: TreeNode | None, val: int) -> TreeNode | None:
        """Rekurzív csomópont-törlés (segédmetódus)"""
        if node is None:
            return None
        # 1. Csomópont keresése és törlése
        if val < node.val:
            node.left = self.remove_helper(node.left, val)
        elif val > node.val:
            node.right = self.remove_helper(node.right, val)
        else:
            if node.left is None or node.right is None:
                child = node.left or node.right
                # Gyermekek száma = 0, a csomópontot közvetlenül törli és None-t ad vissza
                if child is None:
                    return None
                # Gyermekek száma = 1, a csomópontot közvetlenül törli
                else:
                    node = child
            else:
                # Gyermekek száma = 2, a közrendű bejárásban következő csomópontot törli, majd az aktuálist azzal helyettesíti
                temp = node.right
                while temp.left is not None:
                    temp = temp.left
                node.right = self.remove_helper(node.right, temp.val)
                node.val = temp.val
        # Csomópont magasságának frissítése
        self.update_height(node)
        # 2. Forgatás végrehajtása a részfa egyensúlyának helyreállításához
        return self.rotate(node)

    def search(self, val: int) -> TreeNode | None:
        """Csomópont keresése"""
        cur = self._root
        # Ciklusos keresés, a levélcsomópont után kilép
        while cur is not None:
            # A célcsomópont a cur jobb részfájában van
            if cur.val < val:
                cur = cur.right
            # A célcsomópont a cur bal részfájában van
            elif cur.val > val:
                cur = cur.left
            # Megtalálta a célcsomópontot, kilép a ciklusból
            else:
                break
        # A célcsomópontot adja vissza
        return cur


"""Fő kód"""
if __name__ == "__main__":

    def test_insert(tree: AVLTree, val: int):
        tree.insert(val)
        print("\A(z) {} csomópont beszúrása után az AVL fa:".format(val))
        print_tree(tree.get_root())

    def test_remove(tree: AVLTree, val: int):
        tree.remove(val)
        print("\nA(z) {} csomópont törlése után az AVL fa:".format(val))
        print_tree(tree.get_root())

    # Üres AVL fa inicializálása
    avl_tree = AVLTree()

    # Csomópontok beszúrása
    # Figyelje meg, hogyan tartja egyensúlyban az AVL fa magát csomópontok beszúrása után
    for val in [1, 2, 3, 4, 5, 8, 7, 9, 10, 6]:
        test_insert(avl_tree, val)

    # Duplikált csomópont beszúrása
    test_insert(avl_tree, 7)

    # Csomópontok törlése
    # Figyelje meg, hogyan tartja egyensúlyban az AVL fa magát csomópontok törlése után
    test_remove(avl_tree, 8)  # 0 fokú csomópont törlése
    test_remove(avl_tree, 5)  # 1 fokú csomópont törlése
    test_remove(avl_tree, 4)  # 2 fokú csomópont törlése

    result_node = avl_tree.search(7)
    print("\nA talált csomópont objektum: {}, csomópont értéke = {}".format(result_node, result_node.val))
