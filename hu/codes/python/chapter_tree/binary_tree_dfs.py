"""
File: binary_tree_dfs.py
Created Time: 2022-12-20
Author: a16su (lpluls001@gmail.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import TreeNode, list_to_tree, print_tree


def pre_order(root: TreeNode | None):
    """Előrendű bejárás"""
    if root is None:
        return
    # Látogatási sorrend: gyökércsomópont -> bal részfa -> jobb részfa
    res.append(root.val)
    pre_order(root=root.left)
    pre_order(root=root.right)


def in_order(root: TreeNode | None):
    """Közrendű bejárás"""
    if root is None:
        return
    # Látogatási sorrend: bal részfa -> gyökércsomópont -> jobb részfa
    in_order(root=root.left)
    res.append(root.val)
    in_order(root=root.right)


def post_order(root: TreeNode | None):
    """Utórendű bejárás"""
    if root is None:
        return
    # Látogatási sorrend: bal részfa -> jobb részfa -> gyökércsomópont
    post_order(root=root.left)
    post_order(root=root.right)
    res.append(root.val)


"""Fő kód"""
if __name__ == "__main__":
    # Bináris fa inicializálása
    # Tömbből közvetlenül bináris fát generáló függvény használata
    root = list_to_tree(arr=[1, 2, 3, 4, 5, 6, 7])
    print("\nBináris fa inicializálása\n")
    print_tree(root)

    # Előrendű bejárás
    res = []
    pre_order(root)
    print("\nElőrendű bejárás csomópont kiírási sorrendje = ", res)

    # Közrendű bejárás
    res.clear()
    in_order(root)
    print("\nKözrendű bejárás csomópont kiírási sorrendje = ", res)

    # Utórendű bejárás
    res.clear()
    post_order(root)
    print("\nUtórendű bejárás csomópont kiírási sorrendje = ", res)
