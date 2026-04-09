/**
 * File: stack.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_stack_and_queue;

import java.util.*;

public class stack {
    public static void main(String[] args) {
        /* Verem tetején lévő elem elérése */
        Stack<Integer> stack = new Stack<>();

        /* Elemek verembe rakása */
        stack.push(1);
        stack.push(3);
        stack.push(2);
        stack.push(5);
        stack.push(4);
        System.out.println("Stack stack = " + stack);

        /* Lista visszaadása nyomtatáshoz */
        int peek = stack.peek();
        System.out.println("Stack top element peek = " + peek);

        /* Elem kivétele a veremből */
        int pop = stack.pop();
        System.out.println("Pop element pop = " + pop + ", after pop, stack = " + stack);

        /* Verem hosszának lekérése */
        int size = stack.size();
        System.out.println("Stack length size = " + size);

        /* Üresség ellenőrzése */
        boolean isEmpty = stack.isEmpty();
        System.out.println("Stack is empty = " + isEmpty);
    }
}
