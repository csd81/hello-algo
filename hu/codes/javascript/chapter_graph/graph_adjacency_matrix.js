/**
 * File: graph_adjacency_matrix.js
 * Created Time: 2023-02-09
 * Author: Zhuo Qinyue (1403450829@qq.com)
 */

/* Szomszédsági mátrixon alapuló irányítatlan gráf osztály */
class GraphAdjMat {
    vertices; // Csúcslista, ahol az elem a "csúcs értékét", az index a "csúcs indexét" jelöli
    adjMat; // Szomszédsági mátrix, ahol a sor- és oszlopindexek a "csúcs indexnek" felelnek meg

    /* Konstruktor */
    constructor(vertices, edges) {
        this.vertices = [];
        this.adjMat = [];
        // Csúcs hozzáadása
        for (const val of vertices) {
            this.addVertex(val);
        }
        // Él hozzáadása
        // Megjegyzés: az edges elemek csúcsindexeket jelölnek, azaz a vertices elemindexeinek felelnek meg
        for (const e of edges) {
            this.addEdge(e[0], e[1]);
        }
    }

    /* A csúcsok számának lekérése */
    size() {
        return this.vertices.length;
    }

    /* Csúcs hozzáadása */
    addVertex(val) {
        const n = this.size();
        // Az új csúcs értékét hozzáadjuk a csúcslistához
        this.vertices.push(val);
        // Új sort adunk a szomszédsági mátrixhoz
        const newRow = [];
        for (let j = 0; j < n; j++) {
            newRow.push(0);
        }
        this.adjMat.push(newRow);
        // Új oszlopot adunk a szomszédsági mátrixhoz
        for (const row of this.adjMat) {
            row.push(0);
        }
    }

    /* Csúcs eltávolítása */
    removeVertex(index) {
        if (index >= this.size()) {
            throw new RangeError('Index Out Of Bounds Exception');
        }
        // Az index pozíciójú csúcsot eltávolítjuk a csúcslistából
        this.vertices.splice(index, 1);

        // Az index pozíciójú sort eltávolítjuk a szomszédsági mátrixból
        this.adjMat.splice(index, 1);
        // Az index pozíciójú oszlopot eltávolítjuk a szomszédsági mátrixból
        for (const row of this.adjMat) {
            row.splice(index, 1);
        }
    }

    /* Él hozzáadása */
    // Az i, j paraméterek a vertices elemindexeinek felelnek meg
    addEdge(i, j) {
        // Index határon kívüliség és egyenlőség kezelése
        if (i < 0 || j < 0 || i >= this.size() || j >= this.size() || i === j) {
            throw new RangeError('Index Out Of Bounds Exception');
        }
        // Irányítatlan gráfban a szomszédsági mátrix szimmetrikus a főátlóra, azaz (i, j) === (j, i)
        this.adjMat[i][j] = 1;
        this.adjMat[j][i] = 1;
    }

    /* Él eltávolítása */
    // Az i, j paraméterek a vertices elemindexeinek felelnek meg
    removeEdge(i, j) {
        // Index határon kívüliség és egyenlőség kezelése
        if (i < 0 || j < 0 || i >= this.size() || j >= this.size() || i === j) {
            throw new RangeError('Index Out Of Bounds Exception');
        }
        this.adjMat[i][j] = 0;
        this.adjMat[j][i] = 0;
    }

    /* Szomszédsági mátrix kiírása */
    print() {
        console.log('Vertex list = ', this.vertices);
        console.log('Adjacency matrix =', this.adjMat);
    }
}

/* Tesztkód */
/* Él hozzáadása */
// Megjegyzés: az edges elemek csúcsindexeket jelölnek, azaz a vertices elemindexeinek felelnek meg
const vertices = [1, 3, 2, 5, 4];
const edges = [
    [0, 1],
    [1, 2],
    [2, 3],
    [0, 3],
    [2, 4],
    [3, 4],
];
const graph = new GraphAdjMat(vertices, edges);
console.log('\nAfter initialization, graph is');
graph.print();

/* Él hozzáadása */
// Csúcs hozzáadása
graph.addEdge(0, 2);
console.log('\nAfter adding edge 1-2, graph is');
graph.print();

/* Él eltávolítása */
// Az 1, 3 csúcsoknak indexe 0, 1
graph.removeEdge(0, 1);
console.log('\nAfter removing edge 1-3, graph is');
graph.print();

/* Csúcs hozzáadása */
graph.addVertex(6);
console.log('\nAfter adding vertex 6, graph is');
graph.print();

/* Csúcs eltávolítása */
// A 3-as csúcsnak indexe 1
graph.removeVertex(1);
console.log('\nAfter removing vertex 3, graph is');
graph.print();
