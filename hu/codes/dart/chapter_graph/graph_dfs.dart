/**
 * File: graph_dfs.dart
 * Created Time: 2023-05-15
 * Author: liuyuxin (gvenusleo@gmail.com)
 */

import '../utils/vertex.dart';
import 'graph_adjacency_list.dart';

/* Mélységi elsőbejárás segédfüggvénye */
void dfs(
  GraphAdjList graph,
  Set<Vertex> visited,
  List<Vertex> res,
  Vertex vet,
) {
  res.add(vet); // A meglátogatott csúcs rögzítése
  visited.add(vet); // Ezt a csúcsot meglátogatottnak jelöli
  // Az adott csúcs összes szomszédos csúcsának bejárása
  for (Vertex adjVet in graph.adjList[vet]!) {
    if (visited.contains(adjVet)) {
      continue; // Már meglátogatott csúcsok kihagyása
    }
    // Szomszédos csúcsok rekurzív meglátogatása
    dfs(graph, visited, res, adjVet);
  }
}

/* Mélységi elsőbejárás */
List<Vertex> graphDFS(GraphAdjList graph, Vertex startVet) {
  // Csúcsbejárási sorrend
  List<Vertex> res = [];
  // Hash halmaz a meglátogatott csúcsok nyilvántartásához
  Set<Vertex> visited = {};
  dfs(graph, visited, res, startVet);
  return res;
}

/* Főprogram */
void main() {
  /* Él hozzáadása */
  List<Vertex> v = Vertex.valsToVets([0, 1, 2, 3, 4, 5, 6]);
  List<List<Vertex>> edges = [
    [v[0], v[1]],
    [v[0], v[3]],
    [v[1], v[2]],
    [v[2], v[5]],
    [v[4], v[5]],
    [v[5], v[6]],
  ];
  GraphAdjList graph = GraphAdjList(edges);
  print("\nAfter initialization, graph is");
  graph.printAdjList();

  /* Mélységi elsőbejárás */
  List<Vertex> res = graphDFS(graph, v[0]);
  print("\nDepth-first traversal (DFS) vertex sequence is");
  print(Vertex.vetsToVals(res));
}
