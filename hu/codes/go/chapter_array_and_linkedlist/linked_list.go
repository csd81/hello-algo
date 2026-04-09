// File: linked_list.go
// Created Time: 2022-12-29
// Author: cathay (cathaycchen@gmail.com)

package chapter_array_and_linkedlist

import (
	. "github.com/krahets/hello-algo/pkg"
)

/* Szúrd be a P csomópontot az n0 csomópont után a láncolt listában */
func insertNode(n0 *ListNode, P *ListNode) {
	n1 := n0.Next
	P.Next = n1
	n0.Next = P
}

/* Távolítsd el az n0 csomópont utáni első csomópontot a láncolt listából */
func removeItem(n0 *ListNode) {
	if n0.Next == nil {
		return
	}
	// n0 -> P -> n1
	P := n0.Next
	n1 := P.Next
	n0.Next = n1
}

/* Hozzáférés az index pozícióbeli csomóponthoz a láncolt listában */
func access(head *ListNode, index int) *ListNode {
	for i := 0; i < index; i++ {
		if head == nil {
			return nil
		}
		head = head.Next
	}
	return head
}

/* Keresd meg a target értékű első csomópontot a láncolt listában */
func findNode(head *ListNode, target int) int {
	index := 0
	for head != nil {
		if head.Val == target {
			return index
		}
		head = head.Next
		index++
	}
	return -1
}
