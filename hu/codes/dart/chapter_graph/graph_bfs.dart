/**
 * File: graph_bfs.dart
 * Created Time: 2023-05-15
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import 'dart:collection';

import '../utils/vertex.dart';
import 'graph_adjacency_list.dart';

/* Szélességi elsőbejárás */
List<Vertex> graphBFS(GraphAdjList graph, Vertex startVet) {
  // Szomszédsági lista segítségével képviseli a gráfot, hogy megkapja az összes szomszédos csúcsot
  // Csúcsbejárási sorrend
  List<Vertex> res = [];
  // Hash halmaz a meglátogatott csúcsok nyilvántartásához
  Set<Vertex> visited = {};
  visited.add(startVet);
  // BFS megvalósításához használt sor
  Queue<Vertex> que = Queue();
  que.add(startVet);
  // A vet csúcstól indulva ciklusban fut, amíg az összes csúcsot meg nem látogatta
  while (que.isNotEmpty) {
    Vertex vet = que.removeFirst(); // Az első csúcs kivételezése a sorból
    res.add(vet); // A meglátogatott csúcs rögzítése
    // Az adott csúcs összes szomszédos csúcsának bejárása
    for (Vertex adjVet in graph.adjList[vet]!) {
      if (visited.contains(adjVet)) {
        continue; // Már meglátogatott csúcsok kihagyása
      }
      que.add(adjVet); // Csak a meg nem látogatott csúcsokat teszi a sorba
      visited.add(adjVet); // Ezt a csúcsot meglátogatottnak jelöli
    }
  }
  // Csúcsbejárási sorrend visszaadása
  return res;
}

/* Főprogram */
void main() {
  /* Él hozzáadása */
  List<Vertex> v = Vertex.valsToVets([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);
  List<List<Vertex>> edges = [
    [v[0], v[1]],
    [v[0], v[3]],
    [v[1], v[2]],
    [v[1], v[4]],
    [v[2], v[5]],
    [v[3], v[4]],
    [v[3], v[6]],
    [v[4], v[5]],
    [v[4], v[7]],
    [v[5], v[8]],
    [v[6], v[7]],
    [v[7], v[8]],
  ];
  GraphAdjList graph = GraphAdjList(edges);
  print("\nAfter initialization, graph is");
  graph.printAdjList();

  /* Szélességi elsőbejárás */
  List<Vertex> res = graphBFS(graph, v[0]);
  print("\nBreadth-first traversal (BFS) vertex sequence is");
  print(Vertex.vetsToVals(res));
}
