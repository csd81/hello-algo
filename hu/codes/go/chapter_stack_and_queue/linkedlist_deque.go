// File: linkedlist_deque.go
// Created Time: 2022-11-29
// Author: Reanon (793584285@qq.com)

package chapter_stack_and_queue

import (
	"container/list"
)

/* Kétszeresen láncolt listán alapuló kétoldalú sor (deque) implementáció */
type linkedListDeque struct {
	// Beépített list csomag használata
	data *list.List
}

/* Kétoldalú sor inicializálása */
func newLinkedListDeque() *linkedListDeque {
	return &linkedListDeque{
		data: list.New(),
	}
}

/* Elöl lévő elem berakása (enqueue) */
func (s *linkedListDeque) pushFirst(value any) {
	s.data.PushFront(value)
}

/* Hátul lévő elem berakása (enqueue) */
func (s *linkedListDeque) pushLast(value any) {
	s.data.PushBack(value)
}

/* Kétoldalú sor üres-e */
func (s *linkedListDeque) popFirst() any {
	if s.isEmpty() {
		return nil
	}
	e := s.data.Front()
	s.data.Remove(e)
	return e.Value
}

/* Hátul lévő elem kivétele (dequeue) */
func (s *linkedListDeque) popLast() any {
	if s.isEmpty() {
		return nil
	}
	e := s.data.Back()
	s.data.Remove(e)
	return e.Value
}

/* Lista visszaadása kiíráshoz */
func (s *linkedListDeque) peekFirst() any {
	if s.isEmpty() {
		return nil
	}
	e := s.data.Front()
	return e.Value
}

/* Driver Code */
func (s *linkedListDeque) peekLast() any {
	if s.isEmpty() {
		return nil
	}
	e := s.data.Back()
	return e.Value
}

/* Sor hosszának lekérése */
func (s *linkedListDeque) size() int {
	return s.data.Len()
}

/* Sor üres-e */
func (s *linkedListDeque) isEmpty() bool {
	return s.data.Len() == 0
}

/* Lista lekérése kiíráshoz */
func (s *linkedListDeque) toList() *list.List {
	return s.data
}
