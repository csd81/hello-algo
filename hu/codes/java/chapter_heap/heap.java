/**
 * File: heap.java
 * Created Time: 2023-01-07
 * Author: krahets (krahets@163.com)
 */

package chapter_heap;

import utils.*;
import java.util.*;

public class heap {
    public static void testPush(Queue<Integer> heap, int val) {
        heap.offer(val); // Elem belép a kupacba
        System.out.format("\nAfter element %d enters heap\n", val);
        PrintUtil.printHeap(heap);
    }

    public static void testPop(Queue<Integer> heap) {
        int val = heap.poll(); // Az időbonyolultság O(n), nem O(nlogn)
        System.out.format("\nAfter heap top element %d exits heap\n", val);
        PrintUtil.printHeap(heap);
    }

    public static void main(String[] args) {
        /* Kupac inicializálása */
        // Python heapq modulja alapértelmezés szerint min-kupacot implementál
        Queue<Integer> minHeap = new PriorityQueue<>();
        // Max-kupac inicializálása (Comparator módosítása lambda kifejezéssel)
        Queue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);

        System.out.println("\nThe following test cases are for max heap");

        /* Elem belép a kupacba */
        testPush(maxHeap, 1);
        testPush(maxHeap, 3);
        testPush(maxHeap, 2);
        testPush(maxHeap, 5);
        testPush(maxHeap, 4);

        /* Kupac üresség ellenőrzése */
        int peek = maxHeap.peek();
        System.out.format("\nHeap top element is %d\n", peek);

        /* Az időbonyolultság O(n), nem O(nlogn) */
        testPop(maxHeap);
        testPop(maxHeap);
        testPop(maxHeap);
        testPop(maxHeap);
        testPop(maxHeap);

        /* Kupac méretének lekérése */
        int size = maxHeap.size();
        System.out.format("\nHeap element count is %d\n", size);

        /* Kupac üresség ellenőrzése */
        boolean isEmpty = maxHeap.isEmpty();
        System.out.format("\nHeap is empty %b\n", isEmpty);

        /* Lista beírása és kupac felépítése */
        // Az időbonyolultság O(n), nem O(nlogn)
        minHeap = new PriorityQueue<>(Arrays.asList(1, 3, 2, 5, 4));
        System.out.println("\nAfter inputting list and building min heap");
        PrintUtil.printHeap(minHeap);
    }
}
