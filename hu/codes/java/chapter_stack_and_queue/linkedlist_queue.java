/**
 * File: linkedlist_queue.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_stack_and_queue;

import java.util.*;

/* Láncolt lista alapú sor implementáció */
class LinkedListQueue {
    private ListNode front, rear; // Fejcsomópont front, farokcsomópont rear
    private int queSize = 0;

    public LinkedListQueue() {
        front = null;
        rear = null;
    }

    /* Sor hosszának lekérése */
    public int size() {
        return queSize;
    }

    /* Sor üresség ellenőrzése */
    public boolean isEmpty() {
        return size() == 0;
    }

    /* Elem sorba rakása */
    public void push(int num) {
        // num hozzáadása a farokcsomópont után
        ListNode node = new ListNode(num);
        // Ha a sor üres, front és rear is a csomópontra mutat
        if (front == null) {
            front = node;
            rear = node;
        // Ha a sor nem üres, a csomópontot a farokcsomópont után adja hozzá
        } else {
            rear.next = node;
            rear = node;
        }
        queSize++;
    }

    /* Elem kivétele a sorból */
    public int pop() {
        int num = peek();
        // Fejcsomópont törlése
        front = front.next;
        queSize--;
        return num;
    }

    /* Lista visszaadása nyomtatáshoz */
    public int peek() {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        return front.val;
    }

    /* Láncolt lista tömbbé konvertálása és visszaadása */
    public int[] toArray() {
        ListNode node = front;
        int[] res = new int[size()];
        for (int i = 0; i < res.length; i++) {
            res[i] = node.val;
            node = node.next;
        }
        return res;
    }
}

public class linkedlist_queue {
    public static void main(String[] args) {
        /* Sor elejének elérése */
        LinkedListQueue queue = new LinkedListQueue();

        /* Elemek sorba rakása */
        queue.push(1);
        queue.push(3);
        queue.push(2);
        queue.push(5);
        queue.push(4);
        System.out.println("Queue queue = " + Arrays.toString(queue.toArray()));

        /* Lista visszaadása nyomtatáshoz */
        int peek = queue.peek();
        System.out.println("Front element peek = " + peek);

        /* Elem kivétele a sorból */
        int pop = queue.pop();
        System.out.println("Dequeue element pop = " + pop + ", after dequeue, queue = " + Arrays.toString(queue.toArray()));

        /* Sor hosszának lekérése */
        int size = queue.size();
        System.out.println("Queue length size = " + size);

        /* Sor üresség ellenőrzése */
        boolean isEmpty = queue.isEmpty();
        System.out.println("Queue is empty = " + isEmpty);
    }
}
