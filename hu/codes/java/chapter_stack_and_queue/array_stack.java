/**
 * File: array_stack.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_stack_and_queue;

import java.util.*;

/* Tömb alapú verem implementáció */
class ArrayStack {
    private ArrayList<Integer> stack;

    public ArrayStack() {
        // Lista inicializálása (dinamikus tömb)
        stack = new ArrayList<>();
    }

    /* Verem hosszának lekérése */
    public int size() {
        return stack.size();
    }

    /* Verem üresség ellenőrzése */
    public boolean isEmpty() {
        return size() == 0;
    }

    /* Elem berakása a verembe */
    public void push(int num) {
        stack.add(num);
    }

    /* Elem kivétele a veremből */
    public int pop() {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        return stack.remove(size() - 1);
    }

    /* Lista visszaadása nyomtatáshoz */
    public int peek() {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        return stack.get(size() - 1);
    }

    /* Lista tömbbé konvertálása és visszaadása */
    public Object[] toArray() {
        return stack.toArray();
    }
}

public class array_stack {
    public static void main(String[] args) {
        /* Verem tetején lévő elem elérése */
        ArrayStack stack = new ArrayStack();

        /* Elemek verembe rakása */
        stack.push(1);
        stack.push(3);
        stack.push(2);
        stack.push(5);
        stack.push(4);
        System.out.println("Stack stack = " + Arrays.toString(stack.toArray()));

        /* Lista visszaadása nyomtatáshoz */
        int peek = stack.peek();
        System.out.println("Stack top element peek = " + peek);

        /* Elem kivétele a veremből */
        int pop = stack.pop();
        System.out.println("Pop element pop = " + pop + ", after pop, stack = " + Arrays.toString(stack.toArray()));

        /* Verem hosszának lekérése */
        int size = stack.size();
        System.out.println("Stack length size = " + size);

        /* Üresség ellenőrzése */
        boolean isEmpty = stack.isEmpty();
        System.out.println("Stack is empty = " + isEmpty);
    }
}
