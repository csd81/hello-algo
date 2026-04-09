/**
 * File: graph_adjacency_list.dart
 * Created Time: 2023-05-15
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import '../utils/vertex.dart';

/* Szomszédsági listán alapuló irányítatlan gráf osztály */
class GraphAdjList {
  // Szomszédsági lista, kulcs: csúcs, érték: az adott csúcs összes szomszédos csúcsa
  Map<Vertex, List<Vertex>> adjList = {};

  /* Konstruktor */
  GraphAdjList(List<List<Vertex>> edges) {
    for (List<Vertex> edge in edges) {
      addVertex(edge[0]);
      addVertex(edge[1]);
      addEdge(edge[0], edge[1]);
    }
  }

  /* Csúcsok számának lekérése */
  int size() {
    return adjList.length;
  }

  /* Él hozzáadása */
  void addEdge(Vertex vet1, Vertex vet2) {
    if (!adjList.containsKey(vet1) ||
        !adjList.containsKey(vet2) ||
        vet1 == vet2) {
      throw ArgumentError;
    }
    // vet1 - vet2 él hozzáadása
    adjList[vet1]!.add(vet2);
    adjList[vet2]!.add(vet1);
  }

  /* Él eltávolítása */
  void removeEdge(Vertex vet1, Vertex vet2) {
    if (!adjList.containsKey(vet1) ||
        !adjList.containsKey(vet2) ||
        vet1 == vet2) {
      throw ArgumentError;
    }
    // vet1 - vet2 él eltávolítása
    adjList[vet1]!.remove(vet2);
    adjList[vet2]!.remove(vet1);
  }

  /* Csúcs hozzáadása */
  void addVertex(Vertex vet) {
    if (adjList.containsKey(vet)) return;
    // Új láncolt lista hozzáadása a szomszédsági listához
    adjList[vet] = [];
  }

  /* Csúcs eltávolítása */
  void removeVertex(Vertex vet) {
    if (!adjList.containsKey(vet)) {
      throw ArgumentError;
    }
    // A vet csúcshoz tartozó láncolt lista eltávolítása a szomszédsági listából
    adjList.remove(vet);
    // Bejárja a többi csúcs láncolt listáját, és eltávolítja az összes vet-et tartalmazó élt
    adjList.forEach((key, value) {
      value.remove(vet);
    });
  }

  /* Szomszédsági lista kiírása */
  void printAdjList() {
    print("Adjacency list =");
    adjList.forEach((key, value) {
      List<int> tmp = [];
      for (Vertex vertex in value) {
        tmp.add(vertex.val);
      }
      print("${key.val}: $tmp,");
    });
  }
}

/* Főprogram */
void main() {
  /* Él hozzáadása */
  List<Vertex> v = Vertex.valsToVets([1, 3, 2, 5, 4]);
  List<List<Vertex>> edges = [
    [v[0], v[1]],
    [v[0], v[3]],
    [v[1], v[2]],
    [v[2], v[3]],
    [v[2], v[4]],
    [v[3], v[4]],
  ];
  GraphAdjList graph = GraphAdjList(edges);
  print("\nAfter initialization, graph is");
  graph.printAdjList();

  /* Él hozzáadása */
  // Az 1, 3 csúcsok v[0], v[1]
  graph.addEdge(v[0], v[2]);
  print("\nAfter adding edge 1-2, graph is");
  graph.printAdjList();

  /* Él eltávolítása */
  // A 3-as csúcs v[1]
  graph.removeEdge(v[0], v[1]);
  print("\nAfter removing edge 1-3, graph is");
  graph.printAdjList();

  /* Csúcs hozzáadása */
  Vertex v5 = Vertex(6);
  graph.addVertex(v5);
  print("\nAfter adding vertex 6, graph is");
  graph.printAdjList();

  /* Csúcs eltávolítása */
  // A 3-as csúcs v[1]
  graph.removeVertex(v[1]);
  print("\nAfter removing vertex 3, graph is");
  graph.printAdjList();
}
