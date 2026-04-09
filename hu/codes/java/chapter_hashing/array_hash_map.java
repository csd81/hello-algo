/**
 * File: array_hash_map.java
 * Created Time: 2022-12-04
 * Author: krahets (krahets@163.com)
 */

package chapter_hashing;

import java.util.*;

/* Kulcs-érték pár */
class Pair {
    public int key;
    public String val;

    public Pair(int key, String val) {
        this.key = key;
        this.val = val;
    }
}

/* Tömb alapú hash tábla implementáció */
class ArrayHashMap {
    private List<Pair> buckets;

    public ArrayHashMap() {
        // Tömb inicializálása 100 vödörrel
        buckets = new ArrayList<>();
        for (int i = 0; i < 100; i++) {
            buckets.add(null);
        }
    }

    /* Hash függvény */
    private int hashFunc(int key) {
        int index = key % 100;
        return index;
    }

    /* Lekérdezési művelet */
    public String get(int key) {
        int index = hashFunc(key);
        Pair pair = buckets.get(index);
        if (pair == null)
            return null;
        return pair.val;
    }

    /* Hozzáadási művelet */
    public void put(int key, String val) {
        Pair pair = new Pair(key, val);
        int index = hashFunc(key);
        buckets.set(index, pair);
    }

    /* Törlési művelet */
    public void remove(int key) {
        int index = hashFunc(key);
        // null-ra állítja a törlés jelzéséhez
        buckets.set(index, null);
    }

    /* Összes kulcs-érték pár lekérése */
    public List<Pair> pairSet() {
        List<Pair> pairSet = new ArrayList<>();
        for (Pair pair : buckets) {
            if (pair != null)
                pairSet.add(pair);
        }
        return pairSet;
    }

    /* Összes kulcs lekérése */
    public List<Integer> keySet() {
        List<Integer> keySet = new ArrayList<>();
        for (Pair pair : buckets) {
            if (pair != null)
                keySet.add(pair.key);
        }
        return keySet;
    }

    /* Összes érték lekérése */
    public List<String> valueSet() {
        List<String> valueSet = new ArrayList<>();
        for (Pair pair : buckets) {
            if (pair != null)
                valueSet.add(pair.val);
        }
        return valueSet;
    }

    /* Hash tábla nyomtatása */
    public void print() {
        for (Pair kv : pairSet()) {
            System.out.println(kv.key + " -> " + kv.val);
        }
    }
}

public class array_hash_map {
    public static void main(String[] args) {
        /* Hash tábla inicializálása */
        ArrayHashMap map = new ArrayHashMap();

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
        String name = map.get(15937);
        System.out.println("\nInput student ID 15937, query name " + name);

        /* Törlési művelet */
        // Kulcs-érték pár (kulcs, érték) eltávolítása a hash táblából
        map.remove(10583);
        System.out.println("\nAfter removing 10583, hash table is\nKey -> Value");
        map.print();

        /* Hash tábla bejárása */
        System.out.println("\nTraverse key-value pairs Key->Value");
        for (Pair kv : map.pairSet()) {
            System.out.println(kv.key + " -> " + kv.val);
        }
        System.out.println("\nTraverse keys only Key");
        for (int key : map.keySet()) {
            System.out.println(key);
        }
        System.out.println("\nTraverse values only Value");
        for (String val : map.valueSet()) {
            System.out.println(val);
        }
    }
}
