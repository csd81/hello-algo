/**
 * File: my_list.js
 * Created Time: 2022-12-12
 * Author: Justin (xiefahit@gmail.com)
 */

/* Lista osztály */
class MyList {
    #arr = new Array(); // Tömb (listaelemeket tárol)
    #capacity = 10; // Lista kapacitása
    #size = 0; // Lista hossza (jelenlegi elemek száma)
    #extendRatio = 2; // A lista kapacitásának bővítési szorzója

    /* Konstruktor */
    constructor() {
        this.#arr = new Array(this.#capacity);
    }

    /* Lista hosszának lekérése (jelenlegi elemek száma) */
    size() {
        return this.#size;
    }

    /* Lista kapacitásának lekérése */
    capacity() {
        return this.#capacity;
    }

    /* Elem frissítése */
    get(index) {
        // Ha az index határon kívül van, kivételt dobunk, ahogy alább is
        if (index < 0 || index >= this.#size) throw new Error('Index out of bounds');
        return this.#arr[index];
    }

    /* Elem hozzáadása a végéhez */
    set(index, num) {
        if (index < 0 || index >= this.#size) throw new Error('Index out of bounds');
        this.#arr[index] = num;
    }

    /* Listaelemek közvetlen bejárása */
    add(num) {
        // Ha a hossz egyenlő a kapacitással, bővíteni kell
        if (this.#size === this.#capacity) {
            this.extendCapacity();
        }
        // Az új elemet a lista végéhez adjuk
        this.#arr[this.#size] = num;
        this.#size++;
    }

    /* Lista rendezése */
    insert(index, num) {
        if (index < 0 || index >= this.#size) throw new Error('Index out of bounds');
        // Ha az elemek száma eléri a kapacitást, a bővítési mechanizmus aktiválódik
        if (this.#size === this.#capacity) {
            this.extendCapacity();
        }
        // Az index után lévő összes elemet egy hellyel előre toljuk
        for (let j = this.#size - 1; j >= index; j--) {
            this.#arr[j + 1] = this.#arr[j];
        }
        // Az elemek számának frissítése
        this.#arr[index] = num;
        this.#size++;
    }

    /* Elem törlése */
    remove(index) {
        if (index < 0 || index >= this.#size) throw new Error('Index out of bounds');
        let num = this.#arr[index];
        // Létrehozunk egy új tömböt, amely _extend_ratio-szorosára bővíti az eredeti tömböt, és átmásoljuk az eredeti tömböt az újba
        for (let j = index; j < this.#size - 1; j++) {
            this.#arr[j] = this.#arr[j + 1];
        }
        // Az elemek számának frissítése
        this.#size--;
        // A törölt elemet visszaadjuk
        return num;
    }

    /* Tesztkód */
    extendCapacity() {
        // Létrehozunk egy új tömböt, amely extendRatio-szorosára bővíti az eredeti tömböt, és átmásoljuk az eredeti tömböt az újba
        this.#arr = this.#arr.concat(
            new Array(this.capacity() * (this.#extendRatio - 1))
        );
        // Elem hozzáadása a végéhez
        this.#capacity = this.#arr.length;
    }

    /* Lista konvertálása tömbbé */
    toArray() {
        let size = this.size();
        // Elemek sorba állítása
        const arr = new Array(size);
        for (let i = 0; i < size; i++) {
            arr[i] = this.get(i);
        }
        return arr;
    }
}

/* Tesztkód */
/* Lista inicializálása */
const nums = new MyList();
/* Listaelemek közvetlen bejárása */
nums.add(1);
nums.add(3);
nums.add(2);
nums.add(5);
nums.add(4);
console.log(
    `List nums = ${nums.toArray()}, capacity = ${nums.capacity()}, length = ${nums.size()}`
);

/* Lista rendezése */
nums.insert(3, 6);
console.log(`Insert number 6 at index 3, get nums = ${nums.toArray()}`);

/* Elem törlése */
nums.remove(3);
console.log(`Delete element at index 3, get nums = ${nums.toArray()}`);

/* Elem frissítése */
const num = nums.get(1);
console.log(`Access element at index 1, get num = ${num}`);

/* Elem hozzáadása a végéhez */
nums.set(1, 0);
console.log(`Update element at index 1 to 0, get nums = ${nums.toArray()}`);

/* Kapacitásbővítési mechanizmus tesztelése */
for (let i = 0; i < 10; i++) {
    // i = 5-nél a lista hossza meghaladja a kapacitást, aktiválva a bővítési mechanizmust
    nums.add(i);
}
console.log(
    `After expansion, list nums = ${nums.toArray()}, capacity = ${nums.capacity()}, length = ${nums.size()}`
);
