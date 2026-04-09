/**
 * File: array_queue.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_stack_and_queue;

import java.util.*;

/* Körkörös tömb alapú sor implementáció */
class ArrayQueue {
    private int[] nums; // Tömb a sor elemeinak tárolásához
    private int front; // Elő-mutató, a sor első elemére mutat
    private int queSize; // Sor hossza

    public ArrayQueue(int capacity) {
        nums = new int[capacity];
        front = queSize = 0;
    }

    /* Sor kapacitásának lekérése */
    public int capacity() {
        return nums.length;
    }

    /* Sor hosszának lekérése */
    public int size() {
        return queSize;
    }

    /* Sor üresség ellenőrzése */
    public boolean isEmpty() {
        return queSize == 0;
    }

    /* Elem sorba rakása */
    public void push(int num) {
        if (queSize == capacity()) {
            System.out.println("Queue is full");
            return;
        }
        // Moduló műveletet használva a hátsó mutató a tömb végén túl az elejére kerül
        // num hozzáadása a sor végéhez
        int rear = (front + queSize) % capacity();
        // Elő-mutató egy pozícióval hátra lép
        nums[rear] = num;
        queSize++;
    }

    /* Elem kivétele a sorból */
    public int pop() {
        int num = peek();
        // Elő-mutató egy pozícióval hátra lép, ha eléri a végét, a tömb elejére kerül
        front = (front + 1) % capacity();
        queSize--;
        return num;
    }

    /* Lista visszaadása nyomtatáshoz */
    public int peek() {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        return nums[front];
    }

    /* Tömb visszaadása */
    public int[] toArray() {
        // Elemek sorba rakása
        int[] res = new int[queSize];
        for (int i = 0, j = front; i < queSize; i++, j++) {
            res[i] = nums[j % capacity()];
        }
        return res;
    }
}

public class array_queue {
    public static void main(String[] args) {
        /* Sor elejének elérése */
        int capacity = 10;
        ArrayQueue queue = new ArrayQueue(capacity);

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

        /* Körkörös tömb tesztelése */
        for (int i = 0; i < 10; i++) {
            queue.push(i);
            queue.pop();
            System.out.println("After round " + i + " enqueue + dequeue, queue = " + Arrays.toString(queue.toArray()));
        }
    }
}
