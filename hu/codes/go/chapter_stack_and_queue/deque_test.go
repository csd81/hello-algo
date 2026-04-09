// File: deque_test.go
// Created Time: 2022-11-29
// Author: Reanon (793584285@qq.com)

package chapter_stack_and_queue

import (
	"container/list"
	"fmt"
	"testing"

	. "github.com/krahets/hello-algo/pkg"
)

func TestDeque(t *testing.T) {
	/* Kétoldalú sor hosszának lekérése */
	// Go-ban list-et használunk kétoldalú sorként
	deque := list.New()

	/* Elemek sorba állítása (enqueue) */
	deque.PushBack(2)
	deque.PushBack(5)
	deque.PushBack(4)
	deque.PushFront(3)
	deque.PushFront(1)
	fmt.Print("Double-ended queue deque = ")
	PrintList(deque)

	/* Elem frissítése */
	front := deque.Front()
	fmt.Println("Front element front =", front.Value)
	rear := deque.Back()
	fmt.Println("Rear element rear =", rear.Value)

	/* Elem kivétele (dequeue) */
	deque.Remove(front)
	fmt.Print("Front dequeue element front = ", front.Value, ", after front dequeue, deque = ")
	PrintList(deque)
	deque.Remove(rear)
	fmt.Print("Rear dequeue element rear = ", rear.Value, ", after rear dequeue, deque = ")
	PrintList(deque)

	/* Kétoldalú sor hosszának lekérése */
	size := deque.Len()
	fmt.Println("Deque length size =", size)

	/* Kétoldalú sor üres-e */
	isEmpty := deque.Len() == 0
	fmt.Println("Is deque empty =", isEmpty)
}

func TestArrayDeque(t *testing.T) {
	/* Kétoldalú sor hosszának lekérése */
	// Go-ban list-et használunk kétoldalú sorként
	deque := newArrayDeque(16)

	/* Elemek sorba állítása (enqueue) */
	deque.pushLast(3)
	deque.pushLast(2)
	deque.pushLast(5)
	fmt.Print("Double-ended queue deque = ")
	PrintSlice(deque.toSlice())

	/* Elem frissítése */
	peekFirst := deque.peekFirst()
	fmt.Println("Front element peekFirst =", peekFirst)
	peekLast := deque.peekLast()
	fmt.Println("Rear element peekLast =", peekLast)

	/* Elemek sorba állítása (enqueue) */
	deque.pushLast(4)
	fmt.Print("After element 4 enqueues at rear, deque = ")
	PrintSlice(deque.toSlice())
	deque.pushFirst(1)
	fmt.Print("After element 1 enqueues at front, deque = ")
	PrintSlice(deque.toSlice())

	/* Elem kivétele (dequeue) */
	popFirst := deque.popFirst()
	fmt.Print("Front dequeue element popFirst = ", popFirst, ", after front dequeue, deque = ")
	PrintSlice(deque.toSlice())
	popLast := deque.popLast()
	fmt.Print("Back dequeue element popLast = ", popLast, ", after rear dequeue, deque = ")
	PrintSlice(deque.toSlice())

	/* Kétoldalú sor hosszának lekérése */
	size := deque.size()
	fmt.Println("Deque length size =", size)

	/* Kétoldalú sor üres-e */
	isEmpty := deque.isEmpty()
	fmt.Println("Is deque empty =", isEmpty)
}

func TestLinkedListDeque(t *testing.T) {
	// Sor első elemének elérése
	deque := newLinkedListDeque()

	// Elemek sorba állítása (enqueue)
	deque.pushLast(2)
	deque.pushLast(5)
	deque.pushLast(4)
	deque.pushFirst(3)
	deque.pushFirst(1)
	fmt.Print("Deque deque = ")
	PrintList(deque.toList())

	// Lista visszaadása kiíráshoz
	front := deque.peekFirst()
	fmt.Println("Front element front =", front)
	rear := deque.peekLast()
	fmt.Println("Rear element rear =", rear)

	// Elem kivétele (dequeue)
	popFirst := deque.popFirst()
	fmt.Print("Front dequeue element popFirst = ", popFirst, ", after front dequeue, deque = ")
	PrintList(deque.toList())
	popLast := deque.popLast()
	fmt.Print("Back dequeue element popLast = ", popLast, ", after rear dequeue, deque = ")
	PrintList(deque.toList())

	// Sor hosszának lekérése
	size := deque.size()
	fmt.Println("Queue length size =", size)

	// Üres-e
	isEmpty := deque.isEmpty()
	fmt.Println("Is queue empty =", isEmpty)
}

// BenchmarkLinkedListDeque 67.92 ns/op Mac M1 Pro-n
func BenchmarkLinkedListDeque(b *testing.B) {
	deque := newLinkedListDeque()
	// b.N használata ciklushoz
	for i := 0; i < b.N; i++ {
		deque.pushLast(777)
	}
	for i := 0; i < b.N; i++ {
		deque.popFirst()
	}
}
