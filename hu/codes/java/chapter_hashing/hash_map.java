/**
 * File: hash_map.java
 * Created Time: 2022-12-04
 * Author: krahets (krahets@163.com)
 */

package chapter_hashing;

import java.util.*;
import utils.*;

public class hash_map {
    public static void main(String[] args) {
        /* Hash tábla inicializálása */
        Map<Integer, String> map = new HashMap<>();

        /* Hozzáadási művelet */
        // Kulcs-érték pár (kulcs, érték) hozzáadása a hash táblához
        map.put(12836, "Xiao Ha");
        map.put(15937, "Xiao Luo");
        map.put(16750, "Xiao Suan");
        map.put(13276, "Xiao Fa");
        map.put(10583, "Xiao Ya");
        System.out.println("\nAfter adding is complete, hash table is\nKey -> Value");
        PrintUtil.printHashMap(map);

        /* Lekérdezési művelet */
        // Kulcs beírása a hash táblába az érték lekéréséhez
        String name = map.get(15937);
        System.out.println("\nInput student ID 15937, query name " + name);

        /* Törlési művelet */
        // Kulcs-érték pár (kulcs, érték) eltávolítása a hash táblából
        map.remove(10583);
        System.out.println("\nAfter removing 10583, hash table is\nKey -> Value");
        PrintUtil.printHashMap(map);

        /* Hash tábla bejárása */
        System.out.println("\nTraverse key-value pairs Key->Value");
        for (Map.Entry<Integer, String> kv : map.entrySet()) {
            System.out.println(kv.getKey() + " -> " + kv.getValue());
        }
        System.out.println("\nTraverse keys only Key");
        for (int key : map.keySet()) {
            System.out.println(key);
        }
        System.out.println("\nTraverse values only Value");
        for (String val : map.values()) {
            System.out.println(val);
        }
    }
}
