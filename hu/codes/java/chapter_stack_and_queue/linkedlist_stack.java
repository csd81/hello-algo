/**
 * File: linkedlist_stack.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_stack_and_queue;

import java.util.*;
import utils.*;

/* Láncolt lista alapú verem implementáció */
class LinkedListStack {
    private ListNode stackPeek; // Fejcsomópontot használja verem tetőként
    private int stkSize = 0; // Verem hossza

    public LinkedListStack() {
        stackPeek = null;
    }

    /* Verem hosszának lekérése */
    public int size() {
        return stkSize;
    }

    /* Verem üresség ellenőrzése */
    public boolean isEmpty() {
        return size() == 0;
    }

    /* Elem berakása a verembe */
    public void push(int num) {
        ListNode node = new ListNode(num);
        node.next = stackPeek;
        stackPeek = node;
        stkSize++;
    }

    /* Elem kivétele a veremből */
    public int pop() {
        int num = peek();
        stackPeek = stackPeek.next;
        stkSize--;
        return num;
    }

    /* Lista visszaadása nyomtatáshoz */
    public int peek() {
        if (isEmpty())
            throw new IndexOutOfBoundsException();
        return stackPeek.val;
    }

    /* Lista tömbbé konvertálása és visszaadása */
    public int[] toArray() {
        ListNode node = stackPeek;
        int[] res = new int[size()];
        for (int i = res.length - 1; i >= 0; i--) {
            res[i] = node.val;
            node = node.next;
        }
        return res;
    }
}

public class linkedlist_stack {
    public static void main(String[] args) {
        /* Verem tetején lévő elem elérése */
        LinkedListStack stack = new LinkedListStack();

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
