/**
 * File: deque.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_stack_and_queue;

import java.util.*;

public class deque {
    public static void main(String[] args) {
        /* Kétirányú sor hosszának lekérése */
        Deque<Integer> deque = new LinkedList<>();
        deque.offerLast(3);
        deque.offerLast(2);
        deque.offerLast(5);
        System.out.println("Double-ended queue deque = " + deque);

        /* Elem frissítése */
        int peekFirst = deque.peekFirst();
        System.out.println("Front element peekFirst = " + peekFirst);
        int peekLast = deque.peekLast();
        System.out.println("Rear element peekLast = " + peekLast);

        /* Elemek sorba rakása */
        deque.offerLast(4);
        System.out.println("After element 4 enqueues at rear, deque = " + deque);
        deque.offerFirst(1);
        System.out.println("After element 1 enqueues at front, deque = " + deque);

        /* Elem kivétele */
        int popLast = deque.pollLast();
        System.out.println("Rear dequeue element = " + popLast + ", after rear dequeue, deque = " + deque);
        int popFirst = deque.pollFirst();
        System.out.println("Front dequeue element = " + popFirst + ", after front dequeue, deque = " + deque);

        /* Kétirányú sor hosszának lekérése */
        int size = deque.size();
        System.out.println("Double-ended queue length size = " + size);

        /* Kétirányú sor üresség ellenőrzése */
        boolean isEmpty = deque.isEmpty();
        System.out.println("Double-ended queue is empty = " + isEmpty);
    }
}
