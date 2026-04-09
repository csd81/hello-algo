/**
 * File: my_heap.java
 * Created Time: 2023-01-07
 * Author: krahets (krahets@163.com)
 */

package chapter_heap;

import utils.*;
import java.util.*;

/* Max-kupac */
class MaxHeap {
    // Lista használata tömb helyett, nem kell foglalkozni a kapacitásbővítéssel
    private List<Integer> maxHeap;

    /* Konstruktor, kupac felépítése bemeneti lista alapján */
    public MaxHeap(List<Integer> nums) {
        // Lista elemeit változatlanul hozzáadja a kupachoz
        maxHeap = new ArrayList<>(nums);
        // Az összes csomópont kupacosítása a levélcsomópontok kivételével
        for (int i = parent(size() - 1); i >= 0; i--) {
            siftDown(i);
        }
    }

    /* Bal gyermekcsomópont indexének lekérése */
    private int left(int i) {
        return 2 * i + 1;
    }

    /* Jobb gyermekcsomópont indexének lekérése */
    private int right(int i) {
        return 2 * i + 2;
    }

    /* Szülőcsomópont indexének lekérése */
    private int parent(int i) {
        return (i - 1) / 2; // Egészre csonkítás
    }

    /* Elemek felcserélése */
    private void swap(int i, int j) {
        int tmp = maxHeap.get(i);
        maxHeap.set(i, maxHeap.get(j));
        maxHeap.set(j, tmp);
    }

    /* Kupac méretének lekérése */
    public int size() {
        return maxHeap.size();
    }

    /* Kupac üresség ellenőrzése */
    public boolean isEmpty() {
        return size() == 0;
    }

    /* Kupac tetején lévő elem elérése */
    public int peek() {
        return maxHeap.get(0);
    }

    /* Elem belép a kupacba */
    public void push(int val) {
        // Csomópont hozzáadása
        maxHeap.add(val);
        // Alulról felfelé kupacosítás
        siftUp(size() - 1);
    }

    /* Az i csomóponttól kezdve alulról felfelé kupacosítás */
    private void siftUp(int i) {
        while (true) {
            // Az i csomópont szülőjének lekérése
            int p = parent(i);
            // Ha "átlépte a gyökércsomópontot" vagy "a csomópontnak nincs szüksége javításra", befejezi a kupacosítást
            if (p < 0 || maxHeap.get(i) <= maxHeap.get(p))
                break;
            // Két csomópont felcserélése
            swap(i, p);
            // Felfelé ciklikus kupacosítás
            i = p;
        }
    }

    /* Elem kilép a kupacból */
    public int pop() {
        // Üres eset kezelése
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        // Csomópont törlése
        swap(0, size() - 1);
        // Csomópont eltávolítása
        int val = maxHeap.remove(size() - 1);
        // Kupac tetejének visszaadása
        siftDown(0);
        // Kupac tetején lévő elem visszaadása
        return val;
    }

    /* Az i csomóponttól kezdve felülről lefelé kupacosítás */
    private void siftDown(int i) {
        while (true) {
            // Ha az i csomópont a legnagyobb vagy l, r indexek határon kívül vannak, nincs szükség további kupacosításra, kilép
            int l = left(i), r = right(i), ma = i;
            if (l < size() && maxHeap.get(l) > maxHeap.get(ma))
                ma = l;
            if (r < size() && maxHeap.get(r) > maxHeap.get(ma))
                ma = r;
            // Két csomópont felcserélése
            if (ma == i)
                break;
            // Két csomópont felcserélése
            swap(i, ma);
            // Lefelé ciklikus kupacosítás
            i = ma;
        }
    }

    /* Főprogram */
    public void print() {
        Queue<Integer> queue = new PriorityQueue<>((a, b) -> { return b - a; });
        queue.addAll(maxHeap);
        PrintUtil.printHeap(queue);
    }
}

public class my_heap {
    public static void main(String[] args) {
        /* Fontolja meg az elemek negálását kupacba lépés előtt, ami megfordítja a méretbeli viszonyokat, így max-kupacot valósít meg */
        MaxHeap maxHeap = new MaxHeap(Arrays.asList(9, 8, 6, 6, 7, 5, 2, 1, 4, 3, 6, 2));
        System.out.println("\nAfter inputting list and building heap");
        maxHeap.print();

        /* Kupac üresség ellenőrzése */
        int peek = maxHeap.peek();
        System.out.format("\nHeap top element is %d\n", peek);

        /* Elem belép a kupacba */
        int val = 7;
        maxHeap.push(val);
        System.out.format("\nAfter element %d enters heap\n", val);
        maxHeap.print();

        /* Az időbonyolultság O(n), nem O(nlogn) */
        peek = maxHeap.pop();
        System.out.format("\nAfter heap top element %d exits heap\n", peek);
        maxHeap.print();

        /* Kupac méretének lekérése */
        int size = maxHeap.size();
        System.out.format("\nHeap element count is %d\n", size);

        /* Kupac üresség ellenőrzése */
        boolean isEmpty = maxHeap.isEmpty();
        System.out.format("\nHeap is empty %b\n", isEmpty);
    }
}
