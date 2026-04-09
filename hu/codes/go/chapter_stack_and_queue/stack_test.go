// File: stack_test.go
// Created Time: 2022-11-28
// Author: Reanon (793584285@qq.com)

package chapter_stack_and_queue

import (
	"fmt"
	"testing"

	. "github.com/krahets/hello-algo/pkg"
)

func TestStack(t *testing.T) {
	/* Verem csúcselemének elérése */
	// Go-ban ajánlott a Slice-t veremként használni
	var stack []int

	/* Elemek a verembe rakása (push) */
	stack = append(stack, 1)
	stack = append(stack, 3)
	stack = append(stack, 2)
	stack = append(stack, 5)
	stack = append(stack, 4)
	fmt.Print("Stack stack = ")
	PrintSlice(stack)

	/* Lista visszaadása kiíráshoz */
	peek := stack[len(stack)-1]
	fmt.Println("Stack top element peek =", peek)

	/* Elem kivétele a veremből (pop) */
	pop := stack[len(stack)-1]
	stack = stack[:len(stack)-1]
	fmt.Print("Pop element pop = ", pop, ", after pop, stack = ")
	PrintSlice(stack)

	/* Verem hosszának lekérése */
	size := len(stack)
	fmt.Println("Stack length size =", size)

	/* Üres-e */
	isEmpty := len(stack) == 0
	fmt.Println("Is stack empty =", isEmpty)
}

func TestArrayStack(t *testing.T) {
	// Verem inicializálása interfészen keresztül
	stack := newArrayStack()

	// Elemek a verembe rakása (push)
	stack.push(1)
	stack.push(3)
	stack.push(2)
	stack.push(5)
	stack.push(4)
	fmt.Print("Stack stack = ")
	PrintSlice(stack.toSlice())

	// Lista visszaadása kiíráshoz
	peek := stack.peek()
	fmt.Println("Stack top element peek =", peek)

	// Elem kivétele a veremből (pop)
	pop := stack.pop()
	fmt.Print("Pop element pop = ", pop, ", after pop, stack = ")
	PrintSlice(stack.toSlice())

	// Verem hosszának lekérése
	size := stack.size()
	fmt.Println("Stack length size =", size)

	// Üres-e
	isEmpty := stack.isEmpty()
	fmt.Println("Is stack empty =", isEmpty)
}

func TestLinkedListStack(t *testing.T) {
	// Verem csúcselemének elérése
	stack := newLinkedListStack()
	// Elemek a verembe rakása (push)
	stack.push(1)
	stack.push(3)
	stack.push(2)
	stack.push(5)
	stack.push(4)
	fmt.Print("Stack stack = ")
	PrintList(stack.toList())

	// Lista visszaadása kiíráshoz
	peek := stack.peek()
	fmt.Println("Stack top element peek =", peek)

	// Elem kivétele a veremből (pop)
	pop := stack.pop()
	fmt.Print("Pop element pop = ", pop, ", after pop, stack = ")
	PrintList(stack.toList())

	// Verem hosszának lekérése
	size := stack.size()
	fmt.Println("Stack length size =", size)

	// Üres-e
	isEmpty := stack.isEmpty()
	fmt.Println("Is stack empty =", isEmpty)
}

// BenchmarkArrayStack 8 ns/op Mac M1 Pro-n
func BenchmarkArrayStack(b *testing.B) {
	stack := newArrayStack()
	// b.N használata ciklushoz
	for i := 0; i < b.N; i++ {
		stack.push(777)
	}
	for i := 0; i < b.N; i++ {
		stack.pop()
	}
}

// BenchmarkLinkedListStack 65.02 ns/op Mac M1 Pro-n
func BenchmarkLinkedListStack(b *testing.B) {
	stack := newLinkedListStack()
	// b.N használata ciklushoz
	for i := 0; i < b.N; i++ {
		stack.push(777)
	}
	for i := 0; i < b.N; i++ {
		stack.pop()
	}
}
