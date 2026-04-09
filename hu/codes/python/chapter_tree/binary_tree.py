"""
File: binary_tree.py
Created Time: 2022-12-20
Author: a16su (lpluls001@gmail.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import TreeNode, print_tree


"""Fő kód"""
if __name__ == "__main__":
    # Bináris fa inicializálása
    # Csomópontok inicializálása
    n1 = TreeNode(val=1)
    n2 = TreeNode(val=2)
    n3 = TreeNode(val=3)
    n4 = TreeNode(val=4)
    n5 = TreeNode(val=5)
    # Csomópontok közötti referenciák (mutatók) felépítése
    n1.left = n2
    n1.right = n3
    n2.left = n4
    n2.right = n5
    print("\nBináris fa inicializálása\n")
    print_tree(n1)

    # Csomópontok beszúrása és törlése
    P = TreeNode(0)
    # P csomópont beszúrása az n1 -> n2 közé
    n1.left = P
    P.left = n2
    print("\nP csomópont beszúrása után\n")
    print_tree(n1)
    # Csomópont törlése
    n1.left = n2
    print("\nP csomópont törlése után\n")
    print_tree(n1)
