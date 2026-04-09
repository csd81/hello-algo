// File: linked_list_test.go
// Created Time: 2022-12-29
// Author: cathay (cathaycchen@gmail.com)

package chapter_array_and_linkedlist

import (
	"fmt"
	"testing"

	. "github.com/krahets/hello-algo/pkg"
)

func TestLinkedList(t *testing.T) {
	/* Láncolt lista inicializálása: 1 -> 3 -> 2 -> 5 -> 4 */
	// Minden csomópont inicializálása
	n0 := NewListNode(1)
	n1 := NewListNode(3)
	n2 := NewListNode(2)
	n3 := NewListNode(5)
	n4 := NewListNode(4)

	// Csomópontok közötti hivatkozások felépítése
	n0.Next = n1
	n1.Next = n2
	n2.Next = n3
	n3.Next = n4
	fmt.Println("Initialized linked list is")
	PrintLinkedList(n0)

	/* Csomópont beszúrása */
	insertNode(n0, NewListNode(0))
	fmt.Println("Linked list after inserting node is")
	PrintLinkedList(n0)

	/* Csomópont törlése */
	removeItem(n0)
	fmt.Println("Linked list after removing node is")
	PrintLinkedList(n0)

	/* Csomópont elérése */
	node := access(n0, 3)
	fmt.Println("Value of node at index 3 in linked list =", node)

	/* Csomópont keresése */
	index := findNode(n0, 2)
	fmt.Println("Index of node with value 2 in linked list =", index)
}
