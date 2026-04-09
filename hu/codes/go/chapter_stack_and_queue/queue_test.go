// File: queue_test.go
// Created Time: 2022-11-28
// Author: Reanon (793584285@qq.com)

package chapter_stack_and_queue

import (
	"container/list"
	"fmt"
	"testing"

	. "github.com/krahets/hello-algo/pkg"
)

func TestQueue(t *testing.T) {
	/* Sor első elemének elérése */
	// Go-ban list-et használunk sorként
	queue := list.New()

	/* Elemek sorba állítása (enqueue) */
	queue.PushBack(1)
	queue.PushBack(3)
	queue.PushBack(2)
	queue.PushBack(5)
	queue.PushBack(4)
	fmt.Print("Queue queue = ")
	PrintList(queue)

	/* Lista visszaadása kiíráshoz */
	peek := queue.Front()
	fmt.Println("Front element peek =", peek.Value)

	/* Elem kivétele a sorból (dequeue) */
	pop := queue.Front()
	queue.Remove(pop)
	fmt.Print("Dequeue element pop = ", pop.Value, ", after dequeue, queue = ")
	PrintList(queue)

	/* Sor hosszának lekérése */
	size := queue.Len()
	fmt.Println("Queue length size =", size)

	/* Sor üres-e */
	isEmpty := queue.Len() == 0
	fmt.Println("Is queue empty =", isEmpty)
}

func TestArrayQueue(t *testing.T) {

	// Sor inicializálása a sor általános interfészén keresztül
	capacity := 10
	queue := newArrayQueue(capacity)
	if queue.pop() != nil {
		t.Errorf("want:%v,got:%v", nil, queue.pop())
	}

	// Elemek sorba állítása (enqueue)
	queue.push(1)
	queue.push(3)
	queue.push(2)
	queue.push(5)
	queue.push(4)
	fmt.Print("Queue queue = ")
	PrintSlice(queue.toSlice())

	// Lista visszaadása kiíráshoz
	peek := queue.peek()
	fmt.Println("Front element peek =", peek)

	// Elem kivétele a sorból (dequeue)
	pop := queue.pop()
	fmt.Print("Dequeue element pop = ", pop, ", after dequeue, queue = ")
	PrintSlice(queue.toSlice())

	// Sor hosszának lekérése
	size := queue.size()
	fmt.Println("Queue length size =", size)

	// Üres-e
	isEmpty := queue.isEmpty()
	fmt.Println("Is queue empty =", isEmpty)

	/* Körkörös tömb tesztelése */
	for i := 0; i < 10; i++ {
		queue.push(i)
		queue.pop()
		fmt.Print("Round ", i, " enqueue + dequeue, queue =")
		PrintSlice(queue.toSlice())
	}
}

func TestLinkedListQueue(t *testing.T) {
	// Sor inicializálása
	queue := newLinkedListQueue()

	// Elemek sorba állítása (enqueue)
	queue.push(1)
	queue.push(3)
	queue.push(2)
	queue.push(5)
	queue.push(4)
	fmt.Print("Queue queue = ")
	PrintList(queue.toList())

	// Lista visszaadása kiíráshoz
	peek := queue.peek()
	fmt.Println("Front element peek =", peek)

	// Elem kivétele a sorból (dequeue)
	pop := queue.pop()
	fmt.Print("Dequeue element pop = ", pop, ", after dequeue, queue = ")
	PrintList(queue.toList())

	// Sor hosszának lekérése
	size := queue.size()
	fmt.Println("Queue length size =", size)

	// Üres-e
	isEmpty := queue.isEmpty()
	fmt.Println("Is queue empty =", isEmpty)
}

// BenchmarkArrayQueue 8 ns/op Mac M1 Pro-n
func BenchmarkArrayQueue(b *testing.B) {
	capacity := 1000
	queue := newArrayQueue(capacity)
	// b.N használata ciklushoz
	for i := 0; i < b.N; i++ {
		queue.push(777)
	}
	for i := 0; i < b.N; i++ {
		queue.pop()
	}
}

// BenchmarkLinkedQueue 62.66 ns/op Mac M1 Pro-n
func BenchmarkLinkedQueue(b *testing.B) {
	queue := newLinkedListQueue()
	// b.N használata ciklushoz
	for i := 0; i < b.N; i++ {
		queue.push(777)
	}
	for i := 0; i < b.N; i++ {
		queue.pop()
	}
}
