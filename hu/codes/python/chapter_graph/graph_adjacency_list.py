"""
File: graph_adjacency_list.py
Created Time: 2023-02-23
Author: krahets (krahets@163.com)
"""

import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent.parent))
from modules import Vertex, vals_to_vets


class GraphAdjList:
    """Szomszédsági listán alapuló irányítatlan gráf osztály"""

    def __init__(self, edges: list[list[Vertex]]):
        """Konstruktor"""
        # Szomszédsági lista, kulcs: csúcs, érték: az adott csúcs összes szomszédja
        self.adj_list = dict[Vertex, list[Vertex]]()
        # Az összes csúcs és él hozzáadása
        for edge in edges:
            self.add_vertex(edge[0])
            self.add_vertex(edge[1])
            self.add_edge(edge[0], edge[1])

    def size(self) -> int:
        """A csúcsok számának lekérése"""
        return len(self.adj_list)

    def add_edge(self, vet1: Vertex, vet2: Vertex):
        """Él hozzáadása"""
        if vet1 not in self.adj_list or vet2 not in self.adj_list or vet1 == vet2:
            raise ValueError()
        # vet1 - vet2 él hozzáadása
        self.adj_list[vet1].append(vet2)
        self.adj_list[vet2].append(vet1)

    def remove_edge(self, vet1: Vertex, vet2: Vertex):
        """Él eltávolítása"""
        if vet1 not in self.adj_list or vet2 not in self.adj_list or vet1 == vet2:
            raise ValueError()
        # vet1 - vet2 él eltávolítása
        self.adj_list[vet1].remove(vet2)
        self.adj_list[vet2].remove(vet1)

    def add_vertex(self, vet: Vertex):
        """Csúcs hozzáadása"""
        if vet in self.adj_list:
            return
        # Új láncolt lista hozzáadása a szomszédsági listához
        self.adj_list[vet] = []

    def remove_vertex(self, vet: Vertex):
        """Csúcs eltávolítása"""
        if vet not in self.adj_list:
            raise ValueError()
        # A vet csúcshoz tartozó láncolt lista eltávolítása a szomszédsági listából
        self.adj_list.pop(vet)
        # A többi csúcs láncolt listáin végigmegy és eltávolítja az összes vet-et tartalmazó élt
        for vertex in self.adj_list:
            if vet in self.adj_list[vertex]:
                self.adj_list[vertex].remove(vet)

    def print(self):
        """Szomszédsági lista kiírása"""
        print("Szomszédsági lista =")
        for vertex in self.adj_list:
            tmp = [v.val for v in self.adj_list[vertex]]
            print(f"{vertex.val}: {tmp},")


"""Fő kód"""
if __name__ == "__main__":
    # Irányítatlan gráf inicializálása
    v = vals_to_vets([1, 3, 2, 5, 4])
    edges = [
        [v[0], v[1]],
        [v[0], v[3]],
        [v[1], v[2]],
        [v[2], v[3]],
        [v[2], v[4]],
        [v[3], v[4]],
    ]
    graph = GraphAdjList(edges)
    print("\nInicializálás után a gráf:")
    graph.print()

    # Él hozzáadása
    # Az 1-es és 2-es csúcsok v[0] és v[2]
    graph.add_edge(v[0], v[2])
    print("\nAz 1-2 él hozzáadása után a gráf:")
    graph.print()

    # Él eltávolítása
    # Az 1-es és 3-as csúcsok v[0] és v[1]
    graph.remove_edge(v[0], v[1])
    print("\nAz 1-3 él eltávolítása után a gráf:")
    graph.print()

    # Csúcs hozzáadása
    v5 = Vertex(6)
    graph.add_vertex(v5)
    print("\nA 6-os csúcs hozzáadása után a gráf:")
    graph.print()

    # Csúcs eltávolítása
    # A 3-as csúcs v[1]
    graph.remove_vertex(v[1])
    print("\nA 3-as csúcs eltávolítása után a gráf:")
    graph.print()
