/**
 * File: linkedlist_deque.java
 * Created Time: 2023-01-20
 * Author: krahets (krahets@163.com)
 */

package chapter_stack_and_queue;

import java.util.*;

/* Kétirányú láncolt lista csomópont */
class ListNode {
    int val; // Csomópont értéke
    ListNode next; // Következő csomópont referenciája
    ListNode prev; // Előző csomópont referenciája

    ListNode(int val) {
        this.val = val;
        prev = next = null;
    }
}

/* Kétirányú láncolt lista alapú kétirányú sor implementáció */
class LinkedListDeque {
    private ListNode front, rear; // Fejcsomópont front, farokcsomópont rear
    private int queSize = 0; // Kétirányú sor hossza

    public LinkedListDeque() {
        front = rear = null;
    }

    /* Kétirányú sor hosszának lekérése */
    public int size() {
        return queSize;
    }

    /* Kétirányú sor üresség ellenőrzése */
    public boolean isEmpty() {
        return size() == 0;
    }

    /* Besorolási művelet */
    private void push(int num, boolean isFront) {
        ListNode node = new ListNode(num);
        // Ha a láncolt lista üres, front és rear is a csomópontra mutat
        if (isEmpty())
            front = rear = node;
        // Sor elejére való besorolási művelet
        else if (isFront) {
            // Csomópont hozzáadása a láncolt lista elejéhez
            front.prev = node;
            node.next = front;
            front = node; // Fejcsomópont frissítése
        // Sor végére való besorolási művelet
        } else {
            // Csomópont hozzáadása a láncolt lista végéhez
            rear.next = node;
            node.prev = rear;
            rear = node; // Farokcsomópont frissítése
        }
        queSize++; // Sor hosszának frissítése
    }

    /* Sor elejére való besorolás */
    public void pushFirst(int num) {
        push(num, true);
    }

    /* Sor végére való besorolás */
    public void pushLast(int num) {
        push(num, false);
    }

    /* Kisorolási művelet */
    private int pop(boolean isFront) {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        int val;
        // Fejcsomópont értékének ideiglenes tárolása
        if (isFront) {
            val = front.val; // Fejcsomópont törlése
            // Fejcsomópont törlése
            ListNode fNext = front.next;
            if (fNext != null) {
                fNext.prev = null;
                front.next = null;
            }
            front = fNext; // Fejcsomópont frissítése
        // Farokcsomópont értékének ideiglenes tárolása
        } else {
            val = rear.val; // Farokcsomópont törlése
            // Farokcsomópont frissítése
            ListNode rPrev = rear.prev;
            if (rPrev != null) {
                rPrev.next = null;
                rear.prev = null;
            }
            rear = rPrev; // Farokcsomópont frissítése
        }
        queSize--; // Sor hosszának frissítése
        return val;
    }

    /* Sor végéről való kisorolás */
    public int popFirst() {
        return pop(true);
    }

    /* Sor végén lévő elem elérése */
    public int popLast() {
        return pop(false);
    }

    /* Lista visszaadása nyomtatáshoz */
    public int peekFirst() {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        return front.val;
    }

    /* Főprogram */
    public int peekLast() {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        return rear.val;
    }

    /* Tömb visszaadása nyomtatáshoz */
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

public class linkedlist_deque {
    public static void main(String[] args) {
        /* Kétirányú sor hosszának lekérése */
        LinkedListDeque deque = new LinkedListDeque();
        deque.pushLast(3);
        deque.pushLast(2);
        deque.pushLast(5);
        System.out.println("Double-ended queue deque = " + Arrays.toString(deque.toArray()));

        /* Elem frissítése */
        int peekFirst = deque.peekFirst();
        System.out.println("Front element peekFirst = " + peekFirst);
        int peekLast = deque.peekLast();
        System.out.println("Rear element peekLast = " + peekLast);

        /* Elemek sorba rakása */
        deque.pushLast(4);
        System.out.println("After element 4 enqueues at rear, deque = " + Arrays.toString(deque.toArray()));
        deque.pushFirst(1);
        System.out.println("After element 1 enqueues at front, deque = " + Arrays.toString(deque.toArray()));

        /* Elem kivétele */
        int popLast = deque.popLast();
        System.out.println("Rear dequeue element = " + popLast + ", after rear dequeue, deque = " + Arrays.toString(deque.toArray()));
        int popFirst = deque.popFirst();
        System.out.println("Front dequeue element = " + popFirst + ", after front dequeue, deque = " + Arrays.toString(deque.toArray()));

        /* Kétirányú sor hosszának lekérése */
        int size = deque.size();
        System.out.println("Double-ended queue length size = " + size);

        /* Kétirányú sor üresség ellenőrzése */
        boolean isEmpty = deque.isEmpty();
        System.out.println("Double-ended queue is empty = " + isEmpty);
    }
}
