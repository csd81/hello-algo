/**
 * File: array_deque.java
 * Created Time: 2023-02-16
 * Author: krahets (krahets@163.com), FangYuan33 (374072213@qq.com)
 */

package chapter_stack_and_queue;

import java.util.*;

/* Körkörös tömb alapú kétirányú sor implementáció */
class ArrayDeque {
    private int[] nums; // Tömb a kétirányú sor elemeinak tárolásához
    private int front; // Elő-mutató, a sor első elemére mutat
    private int queSize; // Kétirányú sor hossza

    /* Konstruktor */
    public ArrayDeque(int capacity) {
        this.nums = new int[capacity];
        front = queSize = 0;
    }

    /* Kétirányú sor kapacitásának lekérése */
    public int capacity() {
        return nums.length;
    }

    /* Kétirányú sor hosszának lekérése */
    public int size() {
        return queSize;
    }

    /* Kétirányú sor üresség ellenőrzése */
    public boolean isEmpty() {
        return queSize == 0;
    }

    /* Körkörös tömb indexének kiszámítása */
    private int index(int i) {
        // Moduló műveletet használva a tömb eleje és vége összekapcsolódik
        // Ha i meghaladja a tömb végét, az elejére kerül
        // Ha i meghaladja a tömb elejét, a végére kerül
        return (i + capacity()) % capacity();
    }

    /* Sor elejére való besorolás */
    public void pushFirst(int num) {
        if (queSize == capacity()) {
            System.out.println("Double-ended queue is full");
            return;
        }
        // Moduló műveletet használva front a tömb elején túl a végére kerül
        // num hozzáadása a sor elejéhez
        front = index(front - 1);
        // num hozzáadása a sor elejéhez
        nums[front] = num;
        queSize++;
    }

    /* Sor végére való besorolás */
    public void pushLast(int num) {
        if (queSize == capacity()) {
            System.out.println("Double-ended queue is full");
            return;
        }
        // Moduló műveletet használva rear a tömb végén túl az elejére kerül
        int rear = index(front + queSize);
        // Elő-mutató egy pozícióval hátra lép
        nums[rear] = num;
        queSize++;
    }

    /* Sor végéről való kisorolás */
    public int popFirst() {
        int num = peekFirst();
        // Elő-mutató egy pozícióval hátra lép
        front = index(front + 1);
        queSize--;
        return num;
    }

    /* Sor végén lévő elem elérése */
    public int popLast() {
        int num = peekLast();
        queSize--;
        return num;
    }

    /* Lista visszaadása nyomtatáshoz */
    public int peekFirst() {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        return nums[front];
    }

    /* Főprogram */
    public int peekLast() {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        // Kétirányú sor inicializálása
        int last = index(front + queSize - 1);
        return nums[last];
    }

    /* Tömb visszaadása nyomtatáshoz */
    public int[] toArray() {
        // Elemek sorba rakása
        int[] res = new int[queSize];
        for (int i = 0, j = front; i < queSize; i++, j++) {
            res[i] = nums[index(j)];
        }
        return res;
    }
}

public class array_deque {
    public static void main(String[] args) {
        /* Kétirányú sor hosszának lekérése */
        ArrayDeque deque = new ArrayDeque(10);
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
