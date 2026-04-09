// File: linkedlist_queue.go
// Created Time: 2022-11-28
// Author: Reanon (793584285@qq.com)

package chapter_stack_and_queue

import (
	"container/list"
)

/* Láncolt listán alapuló sor implementáció */
type linkedListQueue struct {
	// Beépített list csomag használata a sor implementálásához
	data *list.List
}

/* Sor első elemének elérése */
func newLinkedListQueue() *linkedListQueue {
	return &linkedListQueue{
		data: list.New(),
	}
}

/* Sorba állítás (enqueue) */
func (s *linkedListQueue) push(value any) {
	s.data.PushBack(value)
}

/* Sorból kivétel (dequeue) */
func (s *linkedListQueue) pop() any {
	if s.isEmpty() {
		return nil
	}
	e := s.data.Front()
	s.data.Remove(e)
	return e.Value
}

/* Lista visszaadása kiíráshoz */
func (s *linkedListQueue) peek() any {
	if s.isEmpty() {
		return nil
	}
	e := s.data.Front()
	return e.Value
}

/* Sor hosszának lekérése */
func (s *linkedListQueue) size() int {
	return s.data.Len()
}

/* Sor üres-e */
func (s *linkedListQueue) isEmpty() bool {
	return s.data.Len() == 0
}

/* Lista lekérése kiíráshoz */
func (s *linkedListQueue) toList() *list.List {
	return s.data
}
