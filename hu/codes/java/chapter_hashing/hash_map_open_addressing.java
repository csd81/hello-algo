/**
 * File: hash_map_open_addressing.java
 * Created Time: 2023-06-13
 * Author: krahets (krahets@163.com)
 */

package chapter_hashing;

/* Nyílt címzéssel ütközéskezelő hash tábla */
class HashMapOpenAddressing {
    private int size; // Kulcs-érték párok száma
    private int capacity = 4; // Hash tábla kapacitása
    private final double loadThres = 2.0 / 3.0; // Terhelési tényező küszöbértéke a bővítés kiváltásához
    private final int extendRatio = 2; // Bővítési szorzó
    private Pair[] buckets; // Vödör tömb
    private final Pair TOMBSTONE = new Pair(-1, "-1"); // Törlési jelzés

    /* Konstruktor */
    public HashMapOpenAddressing() {
        size = 0;
        buckets = new Pair[capacity];
    }

    /* Hash függvény */
    private int hashFunc(int key) {
        return key % capacity;
    }

    /* Terhelési tényező */
    private double loadFactor() {
        return (double) size / capacity;
    }

    /* A kulcshoz tartozó vödör indexének keresése */
    private int findBucket(int key) {
        int index = hashFunc(key);
        int firstTombstone = -1;
        // Lineáris tapogatás, üres vödörnél kilép
        while (buckets[index] != null) {
            // Ha megtalálta a kulcsot, visszaadja a megfelelő vödör indexét
            if (buckets[index].key == key) {
                // Ha korábban törlési jelzéssel találkozott, a kulcs-érték párt arra az indexre helyezi
                if (firstTombstone != -1) {
                    buckets[firstTombstone] = buckets[index];
                    buckets[index] = TOMBSTONE;
                    return firstTombstone; // Az áthelyezett vödör indexét adja vissza
                }
                return index; // Vödör indexének visszaadása
            }
            // Az első törlési jelzés rögzítése
            if (firstTombstone == -1 && buckets[index] == TOMBSTONE) {
                firstTombstone = index;
            }
            // Vödör index kiszámítása, a tömb végén túl az elejére kerül
            index = (index + 1) % capacity;
        }
        // Ha a kulcs nem létezik, visszaadja a beszúráshoz szükséges indexet
        return firstTombstone == -1 ? index : firstTombstone;
    }

    /* Lekérdezési művelet */
    public String get(int key) {
        // A kulcshoz tartozó vödör indexének keresése
        int index = findBucket(key);
        // Ha megtalálta a kulcs-érték párt, visszaadja a megfelelő értéket
        if (buckets[index] != null && buckets[index] != TOMBSTONE) {
            return buckets[index].val;
        }
        // Ha a kulcs-érték pár nem létezik, null-t ad vissza
        return null;
    }

    /* Hozzáadási művelet */
    public void put(int key, String val) {
        // Ha a terhelési tényező meghaladja a küszöbértéket, bővítést hajt végre
        if (loadFactor() > loadThres) {
            extend();
        }
        // A kulcshoz tartozó vödör indexének keresése
        int index = findBucket(key);
        // Ha megtalálta a kulcs-érték párt, felülírja az értéket és visszatér
        if (buckets[index] != null && buckets[index] != TOMBSTONE) {
            buckets[index].val = val;
            return;
        }
        // Ha a kulcs-érték pár nem létezik, hozzáadja a kulcs-érték párt
        buckets[index] = new Pair(key, val);
        size++;
    }

    /* Törlési művelet */
    public void remove(int key) {
        // A kulcshoz tartozó vödör indexének keresése
        int index = findBucket(key);
        // Ha megtalálta a kulcs-érték párt, törlési jelzéssel felülírja
        if (buckets[index] != null && buckets[index] != TOMBSTONE) {
            buckets[index] = TOMBSTONE;
            size--;
        }
    }

    /* Hash tábla bővítése */
    private void extend() {
        // Az eredeti hash tábla ideiglenes tárolása
        Pair[] bucketsTmp = buckets;
        // Bővített új hash tábla inicializálása
        capacity *= extendRatio;
        buckets = new Pair[capacity];
        size = 0;
        // Kulcs-érték párok áthelyezése az eredeti hash táblából az újba
        for (Pair pair : bucketsTmp) {
            if (pair != null && pair != TOMBSTONE) {
                put(pair.key, pair.val);
            }
        }
    }

    /* Hash tábla nyomtatása */
    public void print() {
        for (Pair pair : buckets) {
            if (pair == null) {
                System.out.println("null");
            } else if (pair == TOMBSTONE) {
                System.out.println("TOMBSTONE");
            } else {
                System.out.println(pair.key + " -> " + pair.val);
            }
        }
    }
}

public class hash_map_open_addressing {
    public static void main(String[] args) {
        // Hash tábla inicializálása
        HashMapOpenAddressing hashmap = new HashMapOpenAddressing();

        // Hozzáadási művelet
        // Kulcs-érték pár (kulcs, érték) hozzáadása a hash táblához
        hashmap.put(12836, "Xiao Ha");
        hashmap.put(15937, "Xiao Luo");
        hashmap.put(16750, "Xiao Suan");
        hashmap.put(13276, "Xiao Fa");
        hashmap.put(10583, "Xiao Ya");
        System.out.println("\nAfter adding is complete, hash table is\nKey -> Value");
        hashmap.print();

        // Lekérdezési művelet
        // Kulcs beírása a hash táblába az érték lekéréséhez
        String name = hashmap.get(13276);
        System.out.println("\nInput student ID 13276, query name " + name);

        // Törlési művelet
        // Kulcs-érték pár (kulcs, érték) eltávolítása a hash táblából
        hashmap.remove(16750);
        System.out.println("\nAfter removing 16750, hash table is\nKey -> Value");
        hashmap.print();
    }
}
