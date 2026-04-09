/**
 * File: linked_list.java
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

package chapter_array_and_linkedlist;

import utils.*;

public class linked_list {
    /* P csomópont beszúrása n0 csomópont után a láncolt listában */
    static void insert(ListNode n0, ListNode P) {
        ListNode n1 = n0.next;
        P.next = n1;
        n0.next = P;
    }

    /* Az n0 csomópont utáni első csomópont törlése a láncolt listából */
    static void remove(ListNode n0) {
        if (n0.next == null)
            return;
        // n0 -> P -> n1
        ListNode P = n0.next;
        ListNode n1 = P.next;
        n0.next = n1;
    }

    /* A láncolt lista index pozíciójú csomópontjának elérése */
    static ListNode access(ListNode head, int index) {
        for (int i = 0; i < index; i++) {
            if (head == null)
                return null;
            head = head.next;
        }
        return head;
    }

    /* A target értékű első csomópont megkeresése a láncolt listában */
    static int find(ListNode head, int target) {
        int index = 0;
        while (head != null) {
            if (head.val == target)
                return index;
            head = head.next;
            index++;
        }
        return -1;
    }

    /* Főprogram */
    public static void main(String[] args) {
        /* Láncolt lista inicializálása */
        // Minden csomópont inicializálása
        ListNode n0 = new ListNode(1);
        ListNode n1 = new ListNode(3);
        ListNode n2 = new ListNode(2);
        ListNode n3 = new ListNode(5);
        ListNode n4 = new ListNode(4);
        // Hivatkozások felépítése a csomópontok között
        n0.next = n1;
        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        System.out.println("Initialized linked list is");
        PrintUtil.printLinkedList(n0);

        /* Csomópont beszúrása */
        insert(n0, new ListNode(0));
        System.out.println("Linked list after inserting node is");
        PrintUtil.printLinkedList(n0);

        /* Csomópont törlése */
        remove(n0);
        System.out.println("Linked list after removing node is");
        PrintUtil.printLinkedList(n0);

        /* Csomópont elérése */
        ListNode node = access(n0, 3);
        System.out.println("Value of node at index 3 in linked list = " + node.val);

        /* Csomópont keresése */
        int index = find(n0, 2);
        System.out.println("Index of node with value 2 in linked list = " + index);
    }
}
