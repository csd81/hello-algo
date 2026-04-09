// File: array_test.go
// Created Time: 2022-12-29
// Author: GuoWei (gongguowei01@gmail.com), cathay (cathaycchen@gmail.com)

package chapter_array_and_linkedlist

/**
A Go Slice-t tömbként kezeljük itt. Ez csökkenti
a tanulási költséget és lehetővé teszi, hogy az adatszerkezetekre
és algoritmusokra koncentráljunk.
*/

import (
	"fmt"
	"testing"
)

/* Driver Code */
func TestArray(t *testing.T) {
	/* Tömb inicializálása */
	var arr [5]int
	fmt.Println("Array arr =", arr)
	// Go-ban a hossz megadásával ([5]int) tömb, a hossz nélkül ([]int) szelet (slice) jön létre
	// Mivel a Go tömbök hosszát fordítási időben kell meghatározni, a hossz megadásához csak konstansokat lehet használni
	// Az extend() függvény implementációjának megkönnyítése érdekében a szeleteket tömbként kezeljük alább
	nums := []int{1, 3, 2, 5, 4}
	fmt.Println("Array nums =", nums)

	/* Elem beszúrása */
	randomNum := randomAccess(nums)
	fmt.Println("Get random element in nums", randomNum)

	/* Tömb bejárása */
	nums = extend(nums, 3)
	fmt.Println("Extend array length to 8, get nums =", nums)

	/* Elem beszúrása */
	insert(nums, 6, 3)
	fmt.Println("Insert number 6 at index 3, get nums =", nums)

	/* Elem törlése */
	remove(nums, 2)
	fmt.Println("Remove element at index 2, get nums =", nums)

	/* Tömb bejárása */
	traverse(nums)

	/* Elem keresése */
	index := find(nums, 3)
	fmt.Println("Find element 3 in nums, get index =", index)
}
