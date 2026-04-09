// File: array_queue.go
// Created Time: 2022-11-28
// Author: Reanon (793584285@qq.com)

package chapter_stack_and_queue

/* Körkörös tömbön alapuló sor implementáció */
type arrayQueue struct {
	nums        []int // Tömb a sorabeli elemek tárolásához
	front       int   // Elöl mutató, a sor első elemére mutat
	queSize     int   // Sor hossza
	queCapacity int   // Sor kapacitása (maximum elemszám)
}

/* Sor első elemének elérése */
func newArrayQueue(queCapacity int) *arrayQueue {
	return &arrayQueue{
		nums:        make([]int, queCapacity),
		queCapacity: queCapacity,
		front:       0,
		queSize:     0,
	}
}

/* Sor hosszának lekérése */
func (q *arrayQueue) size() int {
	return q.queSize
}

/* Sor üres-e */
func (q *arrayQueue) isEmpty() bool {
	return q.queSize == 0
}

/* Sorba állítás (enqueue) */
func (q *arrayQueue) push(num int) {
	// Ha rear == queCapacity, a sor tele van
	if q.queSize == q.queCapacity {
		return
	}
	// Moduló művelettel a rear-t visszatekerjük a tömb elejére a végének átlépése után
	// A num elemet a sor végéhez adjuk
	rear := (q.front + q.queSize) % q.queCapacity
	// Az elöl mutató egy pozícióval előre lép
	q.nums[rear] = num
	q.queSize++
}

/* Sorból kivétel (dequeue) */
func (q *arrayQueue) pop() any {
	num := q.peek()
	if num == nil {
		return nil
	}

	// Az elöl mutatót egy pozícióval előre mozgatjuk, ha átlépi a véget, visszatér a tömb elejére
	q.front = (q.front + 1) % q.queCapacity
	q.queSize--
	return num
}

/* Lista visszaadása kiíráshoz */
func (q *arrayQueue) peek() any {
	if q.isEmpty() {
		return nil
	}
	return q.nums[q.front]
}

/* Szelet lekérése kiíráshoz */
func (q *arrayQueue) toSlice() []int {
	rear := (q.front + q.queSize)
	if rear >= q.queCapacity {
		rear %= q.queCapacity
		return append(q.nums[q.front:], q.nums[:rear]...)
	}
	return q.nums[q.front:rear]
}
