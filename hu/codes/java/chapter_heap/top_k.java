/**
 * File: top_k.java
 * Created Time: 2023-06-12
 * Author: krahets (krahets@163.com)
 */

package chapter_heap;

import utils.*;
import java.util.*;

public class top_k {
    /* A tömb k legnagyobb elemének megkeresése kupac alapján */
    static Queue<Integer> topKHeap(int[] nums, int k) {
        // Python heapq modulja alapértelmezés szerint min-kupacot implementál
        Queue<Integer> heap = new PriorityQueue<Integer>();
        // A tömb első k eleme belép a kupacba
        for (int i = 0; i < k; i++) {
            heap.offer(nums[i]);
        }
        // A (k+1)-edik elemtől kezdve a kupac méretét k-n tartja
        for (int i = k; i < nums.length; i++) {
            // Ha az aktuális elem nagyobb mint a kupac tetején lévő elem, a kupac teteje kilép, az aktuális elem belép
            if (nums[i] > heap.peek()) {
                heap.poll();
                heap.offer(nums[i]);
            }
        }
        return heap;
    }

    public static void main(String[] args) {
        int[] nums = { 1, 7, 6, 3, 2 };
        int k = 3;

        Queue<Integer> res = topKHeap(nums, k);
        System.out.println("The largest " + k + " elements are");
        PrintUtil.printHeap(res);
    }
}
