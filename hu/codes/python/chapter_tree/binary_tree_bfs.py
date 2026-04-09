"""
File: binary_tree_bfs.py
Created Time: 2022-12-20
Author: a16su (lpluls001@gmail.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import TreeNode, list_to_tree, print_tree
from collections import deque


def level_order(root: TreeNode | None) -> list[int]:
    """Szintenkénti bejárás"""
    # Sor inicializálása, gyökércsomópont hozzáadása
    queue: deque[TreeNode] = deque()
    queue.append(root)
    # Lista inicializálása a bejárási sorrend mentéséhez
    res = []
    while queue:
        node: TreeNode = queue.popleft()  # Kivétel a sorból
        res.append(node.val)  # Csomópont értékének mentése
        if node.left is not None:
            queue.append(node.left)  # Bal gyermekcsomópont sorba állítása
        if node.right is not None:
            queue.append(node.right)  # Jobb gyermekcsomópont sorba állítása
    return res


"""Fő kód"""
if __name__ == "__main__":
    # Bináris fa inicializálása
    # Tömbből közvetlenül bináris fát generáló függvény használata
    root: TreeNode = list_to_tree(arr=[1, 2, 3, 4, 5, 6, 7])
    print("\nBináris fa inicializálása\n")
    print_tree(root)

    # Szintenkénti bejárás
    res: list[int] = level_order(root)
    print("\nSzintenkénti bejárás csomópont kiírási sorrendje = ", res)
