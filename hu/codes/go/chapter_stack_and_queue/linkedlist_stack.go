// File: linkedlist_stack.go
// Created Time: 2022-11-28
// Author: Reanon (793584285@qq.com)

package chapter_stack_and_queue

import (
	"container/list"
)

/* Láncolt listán alapuló verem implementáció */
type linkedListStack struct {
	// Beépített list csomag használata a verem implementálásához
	data *list.List
}

/* Verem csúcselemének elérése */
func newLinkedListStack() *linkedListStack {
	return &linkedListStack{
		data: list.New(),
	}
}

/* Push (push) */
func (s *linkedListStack) push(value int) {
	s.data.PushBack(value)
}

/* Pop (pop) */
func (s *linkedListStack) pop() any {
	if s.isEmpty() {
		return nil
	}
	e := s.data.Back()
	s.data.Remove(e)
	return e.Value
}

/* Lista visszaadása kiíráshoz */
func (s *linkedListStack) peek() any {
	if s.isEmpty() {
		return nil
	}
	e := s.data.Back()
	return e.Value
}

/* Verem hosszának lekérése */
func (s *linkedListStack) size() int {
	return s.data.Len()
}

/* Verem üres-e */
func (s *linkedListStack) isEmpty() bool {
	return s.data.Len() == 0
}

/* Lista lekérése kiíráshoz */
func (s *linkedListStack) toList() *list.List {
	return s.data
}
