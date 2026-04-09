/**
 * File: queue.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_stack_and_queue;

import java.util.*;

public class queue {
    public static void main(String[] args) {
        /* Sor elejének elérése */
        Queue<Integer> queue = new LinkedList<>();

        /* Elemek sorba rakása */
        queue.offer(1);
        queue.offer(3);
        queue.offer(2);
        queue.offer(5);
        queue.offer(4);
        System.out.println("Queue queue = " + queue);

        /* Lista visszaadása nyomtatáshoz */
        int peek = queue.peek();
        System.out.println("Front element peek = " + peek);

        /* Elem kivétele a sorból */
        int pop = queue.poll();
        System.out.println("Dequeue element pop = " + pop + ", after dequeue, queue = " + queue);

        /* Sor hosszának lekérése */
        int size = queue.size();
        System.out.println("Queue length size = " + size);

        /* Sor üresség ellenőrzése */
        boolean isEmpty = queue.isEmpty();
        System.out.println("Queue is empty = " + isEmpty);
    }
}
