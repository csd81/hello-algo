// File: array_deque.go
// Created Time: 2023-03-13
// Author: Reanon (793584285@qq.com)

package chapter_stack_and_queue

import "fmt"

/* Körkörös tömbön alapuló kétoldalú sor (deque) implementáció */
type arrayDeque struct {
	nums        []int // Tömb a kétoldalú sor elemek tárolásához
	front       int   // Elöl mutató, a sor első elemére mutat
	queSize     int   // Kétoldalú sor hossza
	queCapacity int   // Sor kapacitása (maximum elemszám)
}

/* Sor első elemének elérése */
func newArrayDeque(queCapacity int) *arrayDeque {
	return &arrayDeque{
		nums:        make([]int, queCapacity),
		queCapacity: queCapacity,
		front:       0,
		queSize:     0,
	}
}

/* Kétoldalú sor hosszának lekérése */
func (q *arrayDeque) size() int {
	return q.queSize
}

/* Kétoldalú sor üres-e */
func (q *arrayDeque) isEmpty() bool {
	return q.queSize == 0
}

/* Körkörös tömb indexének kiszámítása */
func (q *arrayDeque) index(i int) int {
	// Moduló művelettel a tömb elejét és végét összekapcsoljuk
	// Ha i átlépi a tömb végét, visszatér az elejére
	// Ha i átlépi a tömb elejét, visszatér a végére
	return (i + q.queCapacity) % q.queCapacity
}

/* Sor elejére való berakás (enqueue) */
func (q *arrayDeque) pushFirst(num int) {
	if q.queSize == q.queCapacity {
		fmt.Println("Double-ended queue is full")
		return
	}
	// Moduló művelettel a front-ot a tömb végére tekerjük vissza az eleje átlépésekor
	// A num elemet a sor elejéhez adjuk
	q.front = q.index(q.front - 1)
	// A num elem hozzáadása a sor elejéhez
	q.nums[q.front] = num
	q.queSize++
}

/* Sor végéhez való hozzáadás (enqueue) */
func (q *arrayDeque) pushLast(num int) {
	if q.queSize == q.queCapacity {
		fmt.Println("Double-ended queue is full")
		return
	}
	// Moduló művelettel a rear-t a tömb elejére tekerjük vissza a végének átlépésekor
	rear := q.index(q.front + q.queSize)
	// Az elöl mutató egy pozícióval előre lép
	q.nums[rear] = num
	q.queSize++
}

/* Sor elejéről való kivétel (dequeue) */
func (q *arrayDeque) popFirst() any {
	num := q.peekFirst()
	if num == nil {
		return nil
	}
	// Az elöl mutatót egy pozícióval előre mozgatjuk
	q.front = q.index(q.front + 1)
	q.queSize--
	return num
}

/* Sor végének elemének elérése */
func (q *arrayDeque) popLast() any {
	num := q.peekLast()
	if num == nil {
		return nil
	}
	q.queSize--
	return num
}

/* Lista visszaadása kiíráshoz */
func (q *arrayDeque) peekFirst() any {
	if q.isEmpty() {
		return nil
	}
	return q.nums[q.front]
}

/* Driver Code */
func (q *arrayDeque) peekLast() any {
	if q.isEmpty() {
		return nil
	}
	// Kétoldalú sor inicializálása
	last := q.index(q.front + q.queSize - 1)
	return q.nums[last]
}

/* Szelet lekérése kiíráshoz */
func (q *arrayDeque) toSlice() []int {
	// Elemek sorba állítása
	res := make([]int, q.queSize)
	for i, j := 0, q.front; i < q.queSize; i++ {
		res[i] = q.nums[q.index(j)]
		j++
	}
	return res
}
