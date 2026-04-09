/**
 * File: linked_list.cpp
 * Created Time: 2022-11-25
 * Author: krahets (krahets@163.com)
 */

#include "../utils/common.hpp"

/* P csomópont beszúrása az n0 csomópont után a láncolt listában */
void insert(ListNode *n0, ListNode *P) {
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

/* Az n0 csomópont utáni első csomópont törlése a láncolt listából */
void remove(ListNode *n0) {
    if (n0->next == nullptr)
        return;
    // n0 -> P -> n1
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    // Memória felszabadítása
    delete P;
}

/* A láncolt lista index indexén lévő csomópont elérése */
ListNode *access(ListNode *head, int index) {
    for (int i = 0; i < index; i++) {
        if (head == nullptr)
            return nullptr;
        head = head->next;
    }
    return head;
}

/* A target értékű első csomópont keresése a láncolt listában */
int find(ListNode *head, int target) {
    int index = 0;
    while (head != nullptr) {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

/* Főprogram */
int main() {
    /* Láncolt lista inicializálása */
    // Minden csomópont inicializálása
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(5);
    ListNode *n4 = new ListNode(4);
    // Csomópontok közötti hivatkozások felépítése
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    cout << "Initialized linked list is" << endl;
    printLinkedList(n0);

    /* Csomópont beszúrása */
    insert(n0, new ListNode(0));
    cout << "Linked list after inserting node is" << endl;
    printLinkedList(n0);

    /* Csomópont törlése */
    remove(n0);
    cout << "Linked list after removing node is" << endl;
    printLinkedList(n0);

    /* Csomópont elérése */
    ListNode *node = access(n0, 3);
    cout << "Value of node at index 3 in linked list = " << node->val << endl;

    /* Csomópont keresése */
    int index = find(n0, 2);
    cout << "Index of node with value 2 in linked list = " << index << endl;

    // Memória felszabadítása
    freeMemoryLinkedList(n0);

    return 0;
}
