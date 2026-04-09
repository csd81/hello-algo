/**
 * File: graph_adjacency_list.js
 * Created Time: 2023-02-09
 * Author: Justin (xiefahit@gmail.com)
 */

const { Vertex } = require('../modules/Vertex');

/* Szomszédsági listán alapuló irányítatlan gráf osztály */
class GraphAdjList {
    // Szomszédsági lista, kulcs: csúcs, érték: az adott csúcs összes szomszédos csúcsa
    adjList;

    /* Konstruktor */
    constructor(edges) {
        this.adjList = new Map();
        // Hozzáadjuk az összes csúcsot és élt
        for (const edge of edges) {
            this.addVertex(edge[0]);
            this.addVertex(edge[1]);
            this.addEdge(edge[0], edge[1]);
        }
    }

    /* A csúcsok számának lekérése */
    size() {
        return this.adjList.size;
    }

    /* Él hozzáadása */
    addEdge(vet1, vet2) {
        if (
            !this.adjList.has(vet1) ||
            !this.adjList.has(vet2) ||
            vet1 === vet2
        ) {
            throw new Error('Illegal Argument Exception');
        }
        // Hozzáadjuk a vet1 - vet2 élt
        this.adjList.get(vet1).push(vet2);
        this.adjList.get(vet2).push(vet1);
    }

    /* Él eltávolítása */
    removeEdge(vet1, vet2) {
        if (
            !this.adjList.has(vet1) ||
            !this.adjList.has(vet2) ||
            vet1 === vet2 ||
            this.adjList.get(vet1).indexOf(vet2) === -1
        ) {
            throw new Error('Illegal Argument Exception');
        }
        // Eltávolítjuk a vet1 - vet2 élt
        this.adjList.get(vet1).splice(this.adjList.get(vet1).indexOf(vet2), 1);
        this.adjList.get(vet2).splice(this.adjList.get(vet2).indexOf(vet1), 1);
    }

    /* Csúcs hozzáadása */
    addVertex(vet) {
        if (this.adjList.has(vet)) return;
        // Új láncolt listát adunk a szomszédsági listához
        this.adjList.set(vet, []);
    }

    /* Csúcs eltávolítása */
    removeVertex(vet) {
        if (!this.adjList.has(vet)) {
            throw new Error('Illegal Argument Exception');
        }
        // Eltávolítjuk a vet csúcshoz tartozó láncolt listát a szomszédsági listából
        this.adjList.delete(vet);
        // Bejárjuk a többi csúcs láncolt listáját és eltávolítjuk az összes vet-et tartalmazó élt
        for (const set of this.adjList.values()) {
            const index = set.indexOf(vet);
            if (index > -1) {
                set.splice(index, 1);
            }
        }
    }

    /* Szomszédsági lista kiírása */
    print() {
        console.log('Adjacency list =');
        for (const [key, value] of this.adjList) {
            const tmp = [];
            for (const vertex of value) {
                tmp.push(vertex.val);
            }
            console.log(key.val + ': ' + tmp.join());
        }
    }
}

if (require.main === module) {
    /* Tesztkód */
    /* Él hozzáadása */
    const v0 = new Vertex(1),
        v1 = new Vertex(3),
        v2 = new Vertex(2),
        v3 = new Vertex(5),
        v4 = new Vertex(4);
    const edges = [
        [v0, v1],
        [v1, v2],
        [v2, v3],
        [v0, v3],
        [v2, v4],
        [v3, v4],
    ];
    const graph = new GraphAdjList(edges);
    console.log('\nAfter initialization, graph is');
    graph.print();

    /* Él hozzáadása */
    // Az 1, 2 csúcs v0, v2
    graph.addEdge(v0, v2);
    console.log('\nAfter adding edge 1-2, graph is');
    graph.print();

    /* Él eltávolítása */
    // Az 1, 3 csúcs v0, v1
    graph.removeEdge(v0, v1);
    console.log('\nAfter removing edge 1-3, graph is');
    graph.print();

    /* Csúcs hozzáadása */
    const v5 = new Vertex(6);
    graph.addVertex(v5);
    console.log('\nAfter adding vertex 6, graph is');
    graph.print();

    /* Csúcs eltávolítása */
    // A 3-as csúcs v1
    graph.removeVertex(v1);
    console.log('\nAfter removing vertex 3, graph is');
    graph.print();
}

module.exports = {
    GraphAdjList,
};
