/**
 * File: graph_adjacency_matrix.dart
 * Created Time: 2023-05-15
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import '../utils/print_util.dart';

/* Szomszédsági mátrixon alapuló irányítatlan gráf osztály */
class GraphAdjMat {
  List<int> vertices = []; // Csúcselemek, az elemek a "csúcsértékeket", az indexek a "csúcsindexeket" jelölik
  List<List<int>> adjMat = []; // Szomszédsági mátrix, ahol a sor- és oszlopindexek a "csúcsindexeknek" felelnek meg

  /* Konstruktor */
  GraphAdjMat(List<int> vertices, List<List<int>> edges) {
    this.vertices = [];
    this.adjMat = [];
    // Csúcs hozzáadása
    for (int val in vertices) {
      addVertex(val);
    }
    // Él hozzáadása
    // Megjegyzés: az élek elemei csúcsindexeket jelölnek, azaz a vertices elemek indexeinek felelnek meg
    for (List<int> e in edges) {
      addEdge(e[0], e[1]);
    }
  }

  /* Csúcsok számának lekérése */
  int size() {
    return vertices.length;
  }

  /* Csúcs hozzáadása */
  void addVertex(int val) {
    int n = size();
    // Az új csúcs értékének hozzáadása a csúcslistához
    vertices.add(val);
    // Sor hozzáadása a szomszédsági mátrixhoz
    List<int> newRow = List.filled(n, 0, growable: true);
    adjMat.add(newRow);
    // Oszlop hozzáadása a szomszédsági mátrixhoz
    for (List<int> row in adjMat) {
      row.add(0);
    }
  }

  /* Csúcs eltávolítása */
  void removeVertex(int index) {
    if (index >= size()) {
      throw IndexError;
    }
    // Az index pozíciójú csúcs eltávolítása a csúcslistából
    vertices.removeAt(index);
    // Az index pozíciójú sor eltávolítása a szomszédsági mátrixból
    adjMat.removeAt(index);
    // Az index pozíciójú oszlop eltávolítása a szomszédsági mátrixból
    for (List<int> row in adjMat) {
      row.removeAt(index);
    }
  }

  /* Él hozzáadása */
  // Az i, j paraméterek a vertices elemek indexeinek felelnek meg
  void addEdge(int i, int j) {
    // Indexhatáron kívüli és egyenlőségi esetek kezelése
    if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
      throw IndexError;
    }
    // Irányítatlan gráfban a szomszédsági mátrix szimmetrikus a főátlóra, azaz (i, j) == (j, i)
    adjMat[i][j] = 1;
    adjMat[j][i] = 1;
  }

  /* Él eltávolítása */
  // Az i, j paraméterek a vertices elemek indexeinek felelnek meg
  void removeEdge(int i, int j) {
    // Indexhatáron kívüli és egyenlőségi esetek kezelése
    if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
      throw IndexError;
    }
    adjMat[i][j] = 0;
    adjMat[j][i] = 0;
  }

  /* Szomszédsági mátrix kiírása */
  void printAdjMat() {
    print("Vertex list = $vertices");
    print("Adjacency matrix = ");
    printMatrix(adjMat);
  }
}

/* Főprogram */
void main() {
  /* Él hozzáadása */
  // Megjegyzés: az élek elemei csúcsindexeket jelölnek, azaz a vertices elemek indexeinek felelnek meg
  List<int> vertices = [1, 3, 2, 5, 4];
  List<List<int>> edges = [
    [0, 1],
    [0, 3],
    [1, 2],
    [2, 3],
    [2, 4],
    [3, 4],
  ];
  GraphAdjMat graph = GraphAdjMat(vertices, edges);
  print("\nAfter initialization, graph is");
  graph.printAdjMat();

  /* Él hozzáadása */
  // Csúcs hozzáadása
  graph.addEdge(0, 2);
  print("\nAfter adding edge 1-2, graph is");
  graph.printAdjMat();

  /* Él eltávolítása */
  // Az 1-es, 3-as csúcsok indexei rendre 0, 1
  graph.removeEdge(0, 1);
  print("\nAfter removing edge 1-3, graph is");
  graph.printAdjMat();

  /* Csúcs hozzáadása */
  graph.addVertex(6);
  print("\nAfter adding vertex 6, graph is");
  graph.printAdjMat();

  /* Csúcs eltávolítása */
  // A 3-as csúcs indexe 1
  graph.removeVertex(1);
  print("\nAfter removing vertex 3, graph is");
  graph.printAdjMat();
}
