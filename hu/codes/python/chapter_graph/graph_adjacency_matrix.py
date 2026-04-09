"""
File: graph_adjacency_matrix.py
Created Time: 2023-02-23
Author: krahets (krahets@163.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import Vertex, print_matrix


class GraphAdjMat:
    """Szomszédsági mátrixon alapuló irányítatlan gráf osztály"""

    def __init__(self, vertices: list[int], edges: list[list[int]]):
        """Konstruktor"""
        # Csúcslista, ahol az elem a "csúcs értékét", az index a "csúcs indexét" jelöli
        self.vertices: list[int] = []
        # Szomszédsági mátrix, ahol a sor- és oszlopindexek a "csúcs indexének" felelnek meg
        self.adj_mat: list[list[int]] = []
        # Csúcsok hozzáadása
        for val in vertices:
            self.add_vertex(val)
        # Élek hozzáadása
        # Megjegyzés: az edges elemei csúcsindexeket jelölnek, azaz a vertices elemek indexeinek felelnek meg
        for e in edges:
            self.add_edge(e[0], e[1])

    def size(self) -> int:
        """A csúcsok számának lekérése"""
        return len(self.vertices)

    def add_vertex(self, val: int):
        """Csúcs hozzáadása"""
        n = self.size()
        # Az új csúcs értékét a csúcslistához adja
        self.vertices.append(val)
        # Egy sort ad a szomszédsági mátrixhoz
        new_row = [0] * n
        self.adj_mat.append(new_row)
        # Egy oszlopot ad a szomszédsági mátrixhoz
        for row in self.adj_mat:
            row.append(0)

    def remove_vertex(self, index: int):
        """Csúcs eltávolítása"""
        if index >= self.size():
            raise IndexError()
        # Az index-edik csomópontot eltávolítja a csúcslistából
        self.vertices.pop(index)
        # Az index-edik sort eltávolítja a szomszédsági mátrixból
        self.adj_mat.pop(index)
        # Az index-edik oszlopot eltávolítja a szomszédsági mátrixból
        for row in self.adj_mat:
            row.pop(index)

    def add_edge(self, i: int, j: int):
        """Él hozzáadása"""
        # Az i, j paraméterek a vertices elemek indexeinek felelnek meg
        # Az index határon kívüliségének és egyenlőségének kezelése
        if i < 0 or j < 0 or i >= self.size() or j >= self.size() or i == j:
            raise IndexError()
        # Irányítatlan gráfban a szomszédsági mátrix szimmetrikus a főátlóra, azaz (i, j) == (j, i)
        self.adj_mat[i][j] = 1
        self.adj_mat[j][i] = 1

    def remove_edge(self, i: int, j: int):
        """Él eltávolítása"""
        # Az i, j paraméterek a vertices elemek indexeinek felelnek meg
        # Az index határon kívüliségének és egyenlőségének kezelése
        if i < 0 or j < 0 or i >= self.size() or j >= self.size() or i == j:
            raise IndexError()
        self.adj_mat[i][j] = 0
        self.adj_mat[j][i] = 0

    def print(self):
        """Szomszédsági mátrix kiírása"""
        print("Csúcslista =", self.vertices)
        print("Szomszédsági mátrix =")
        print_matrix(self.adj_mat)


"""Fő kód"""
if __name__ == "__main__":
    # Irányítatlan gráf inicializálása
    # Megjegyzés: az edges elemei csúcsindexeket jelölnek, azaz a vertices elemek indexeinek felelnek meg
    vertices = [1, 3, 2, 5, 4]
    edges = [[0, 1], [0, 3], [1, 2], [2, 3], [2, 4], [3, 4]]
    graph = GraphAdjMat(vertices, edges)
    print("\nInicializálás után a gráf:")
    graph.print()

    # Él hozzáadása
    # Az 1-es és 2-es csúcsok indexe 0 és 2
    graph.add_edge(0, 2)
    print("\nAz 1-2 él hozzáadása után a gráf:")
    graph.print()

    # Él eltávolítása
    # Az 1-es és 3-as csúcsok indexe 0 és 1
    graph.remove_edge(0, 1)
    print("\nAz 1-3 él eltávolítása után a gráf:")
    graph.print()

    # Csúcs hozzáadása
    graph.add_vertex(6)
    print("\nA 6-os csúcs hozzáadása után a gráf:")
    graph.print()

    # Csúcs eltávolítása
    # A 3-as csúcs indexe 1
    graph.remove_vertex(1)
    print("\nA 3-as csúcs eltávolítása után a gráf:")
    graph.print()
