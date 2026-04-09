/**
 * File: graph_bfs.js
 * Created Time: 2023-02-21
 * Author: Zhuo Qinyue (1403450829@qq.com)
 */

const { GraphAdjList } = require('./graph_adjacency_list');
const { Vertex } = require('../modules/Vertex');

/* Szélességi bejárás */
// A szomszédsági listával képviseljük a gráfot, hogy megkapjuk egy adott csúcs összes szomszédos csúcsát
function graphBFS(graph, startVet) {
    // Csúcs bejárási sorrend
    const res = [];
    // Hash halmaz a már meglátogatott csúcsok rögzítéséhez
    const visited = new Set();
    visited.add(startVet);
    // BFS megvalósításhoz használt sor
    const que = [startVet];
    // A startVet csúcstól kezdve, ciklus amíg az összes csúcsot meg nem látogattuk
    while (que.length) {
        const vet = que.shift(); // Kisorba állítjuk az első csúcsot
        res.push(vet); // Rögzítjük a meglátogatott csúcsot
        // Bejárjuk az adott csúcs összes szomszédos csúcsát
        for (const adjVet of graph.adjList.get(vet) ?? []) {
            if (visited.has(adjVet)) {
                continue; // Kihagyjuk a már meglátogatott csúcsokat
            }
            que.push(adjVet); // Csak a még nem meglátogatott csúcsokat sorba állítjuk
            visited.add(adjVet); // Megjelöljük ezt a csúcsot meglátogatottként
        }
    }
    // Visszaadjuk a csúcs bejárási sorrendjét
    return res;
}

/* Tesztkód */
/* Él hozzáadása */
const v = Vertex.valsToVets([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]);
const edges = [
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
const graph = new GraphAdjList(edges);
console.log('\nAfter initialization, graph is');
graph.print();

/* Szélességi bejárás */
const res = graphBFS(graph, v[0]);
console.log('\nBreadth-first traversal (BFS) vertex sequence is');
console.log(Vertex.vetsToVals(res));
