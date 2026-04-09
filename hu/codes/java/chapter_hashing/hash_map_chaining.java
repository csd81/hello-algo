/**
 * File: hash_map_chaining.java
 * Created Time: 2023-06-13
 * Author: krahets (krahets@163.com)
 */

package chapter_hashing;

import java.util.ArrayList;
import java.util.List;

/* Láncolással ütközéskezelő hash tábla */
class HashMapChaining {
    int size; // Kulcs-érték párok száma
    int capacity; // Hash tábla kapacitása
    double loadThres; // Terhelési tényező küszöbértéke a bővítés kiváltásához
    int extendRatio; // Bővítési szorzó
    List<List<Pair>> buckets; // Vödör tömb

    /* Konstruktor */
    public HashMapChaining() {
        size = 0;
        capacity = 4;
        loadThres = 2.0 / 3.0;
        extendRatio = 2;
        buckets = new ArrayList<>(capacity);
        for (int i = 0; i < capacity; i++) {
            buckets.add(new ArrayList<>());
        }
    }

    /* Hash függvény */
    int hashFunc(int key) {
        return key % capacity;
    }

    /* Terhelési tényező */
    double loadFactor() {
        return (double) size / capacity;
    }

    /* Lekérdezési művelet */
    String get(int key) {
        int index = hashFunc(key);
        List<Pair> bucket = buckets.get(index);
        // Vödör bejárása, ha megtalálta a kulcsot, visszaadja a megfelelő értéket
        for (Pair pair : bucket) {
            if (pair.key == key) {
                return pair.val;
            }
        }
        // Ha nem találta meg a kulcsot, null-t ad vissza
        return null;
    }

    /* Hozzáadási művelet */
    void put(int key, String val) {
        // Ha a terhelési tényező meghaladja a küszöbértéket, bővítést hajt végre
        if (loadFactor() > loadThres) {
            extend();
        }
        int index = hashFunc(key);
        List<Pair> bucket = buckets.get(index);
        // Vödör bejárása, ha megtalálta a megadott kulcsot, frissíti a megfelelő értéket és visszatér
        for (Pair pair : bucket) {
            if (pair.key == key) {
                pair.val = val;
                return;
            }
        }
        // Ha a kulcs nem létezik, a kulcs-érték párt a végéhez fűzi
        Pair pair = new Pair(key, val);
        bucket.add(pair);
        size++;
    }

    /* Törlési művelet */
    void remove(int key) {
        int index = hashFunc(key);
        List<Pair> bucket = buckets.get(index);
        // Vödör bejárása és a kulcs-érték pár eltávolítása belőle
        for (Pair pair : bucket) {
            if (pair.key == key) {
                bucket.remove(pair);
                size--;
                break;
            }
        }
    }

    /* Hash tábla bővítése */
    void extend() {
        // Az eredeti hash tábla ideiglenes tárolása
        List<List<Pair>> bucketsTmp = buckets;
        // Bővített új hash tábla inicializálása
        capacity *= extendRatio;
        buckets = new ArrayList<>(capacity);
        for (int i = 0; i < capacity; i++) {
            buckets.add(new ArrayList<>());
        }
        size = 0;
        // Kulcs-érték párok áthelyezése az eredeti hash táblából az újba
        for (List<Pair> bucket : bucketsTmp) {
            for (Pair pair : bucket) {
                put(pair.key, pair.val);
            }
        }
    }

    /* Hash tábla nyomtatása */
    void print() {
        for (List<Pair> bucket : buckets) {
            List<String> res = new ArrayList<>();
            for (Pair pair : bucket) {
                res.add(pair.key + " -> " + pair.val);
            }
            System.out.println(res);
        }
    }
}

public class hash_map_chaining {
    public static void main(String[] args) {
        /* Hash tábla inicializálása */
        HashMapChaining map = new HashMapChaining();

        /* Hozzáadási művelet */
        // Kulcs-érték pár (kulcs, érték) hozzáadása a hash táblához
        map.put(12836, "Xiao Ha");
        map.put(15937, "Xiao Luo");
        map.put(16750, "Xiao Suan");
        map.put(13276, "Xiao Fa");
        map.put(10583, "Xiao Ya");
        System.out.println("\nAfter adding is complete, hash table is\nKey -> Value");
        map.print();

        /* Lekérdezési művelet */
        // Kulcs beírása a hash táblába az érték lekéréséhez
        String name = map.get(13276);
        System.out.println("\nInput student ID 13276, query name " + name);

        /* Törlési művelet */
        // Kulcs-érték pár (kulcs, érték) eltávolítása a hash táblából
        map.remove(12836);
        System.out.println("\nAfter removing 12836, hash table is\nKey -> Value");
        map.print();
    }
}
