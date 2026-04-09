// File: my_list_test.go
// Created Time: 2022-12-18
// Author: msk397 (machangxinq@gmail.com)

package chapter_array_and_linkedlist

import (
	"fmt"
	"testing"
)

/* Driver Code */
func TestMyList(t *testing.T) {
	/* Lista inicializálása */
	nums := newMyList()
	/* Listaelemek közvetlen bejárása */
	nums.add(1)
	nums.add(3)
	nums.add(2)
	nums.add(5)
	nums.add(4)
	fmt.Printf("List nums = %v, capacity = %v, length = %v\n", nums.toArray(), nums.capacity(), nums.size())

	/* Lista rendezése */
	nums.insert(6, 3)
	fmt.Printf("Insert number 6 at index 3, get nums = %v\n", nums.toArray())

	/* Elem törlése */
	nums.remove(3)
	fmt.Printf("Remove element at index 3, get nums = %v\n", nums.toArray())

	/* Elem frissítése */
	num := nums.get(1)
	fmt.Printf("Access element at index 1, get num = %v\n", num)

	/* Elem hozzáadása a végéhez */
	nums.set(0, 1)
	fmt.Printf("Update element at index 1 to 0, get nums = %v\n", nums.toArray())

	/* Kapacitásbővítési mechanizmus tesztelése */
	for i := 0; i < 10; i++ {
		// i = 5-nél a lista hossza meghaladja a lista kapacitását, aktiválódik a bővítési mechanizmus
		nums.add(i)
	}
	fmt.Printf("After expansion, list nums = %v, capacity = %v, length = %v\n", nums.toArray(), nums.capacity(), nums.size())
}
