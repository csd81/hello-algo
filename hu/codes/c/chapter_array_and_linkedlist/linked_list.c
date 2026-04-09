/**
 * File: linked_list.c
 * Created Time: 2023-01-12
 * Author: Zero (glj0@outlook.com)
 */

#include "../utils/common.h"

/* P csomópont beillesztése az n0 csomópont után a láncolt listában */
void insert(ListNode *n0, ListNode *P) {
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

/* Az n0 csomópont utáni első csomópont törlése a láncolt listából */
// Megjegyzés: a stdio.h foglalja a remove kulcsszót
void removeItem(ListNode *n0) {
    if (!n0->next)
        return;
    // n0 -> P -> n1
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    // Memória felszabadítása
    free(P);
}

/* Az index indexű csomópont elérése a láncolt listában */
ListNode *access(ListNode *head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == NULL)
            return NULL;
        head = head->next;
    }
    return head;
}

/* A target értékű első csomópont keresése a láncolt listában */
int find(ListNode *head, int target) {
    int index = 0;
    while (head) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

/* Vezérlő kód */
int main() {
    /* Láncolt lista inicializálása */
    // Minden csomópont inicializálása
    ListNode *n0 = newListNode(1);
    ListNode *n1 = newListNode(3);
    ListNode *n2 = newListNode(2);
    ListNode *n3 = newListNode(5);
    ListNode *n4 = newListNode(4);
    // Csomópontok közötti hivatkozások felépítése
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printf("Initialized linked list is\r\n");
    printLinkedList(n0);

    /* Csomópont beillesztése */
    insert(n0, newListNode(0));
    printf("Linked list after node insertion is\r\n");
    printLinkedList(n0);

    /* Csomópont törlése */
    removeItem(n0);
    printf("Linked list after node deletion is\r\n");
    printLinkedList(n0);

    /* Csomópont elérése */
    ListNode *node = access(n0, 3);
    printf("Value of node at index 3 in linked list = %d\r\n", node->val);

    /* Csomópont keresése */
    int index = find(n0, 2);
    printf("Index of node with value 2 in linked list = %d\r\n", index);

    // Memória felszabadítása
    freeMemoryLinkedList(n0);
    return 0;
}
