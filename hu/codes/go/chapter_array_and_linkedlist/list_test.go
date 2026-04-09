// File: list_test.go
// Created Time: 2022-12-18
// Author: msk397 (machangxinq@gmail.com)

package chapter_array_and_linkedlist

import (
	"fmt"
	"sort"
	"testing"
)

/* Driver Code */
func TestList(t *testing.T) {
	/* Lista inicializálása */
	nums := []int{1, 3, 2, 5, 4}
	fmt.Println("List nums =", nums)

	/* Elem frissítése */
	num := nums[1] // Az 1-es indexű elem elérése
	fmt.Println("Access element at index 1, get num =", num)

	/* Elem hozzáadása a végéhez */
	nums[1] = 0 // Az 1-es indexű elem frissítése 0-ra
	fmt.Println("Update element at index 1 to 0, get nums =", nums)

	/* Elem törlése */
	nums = nil
	fmt.Println("After clearing list, nums =", nums)

	/* Listaelemek közvetlen bejárása */
	nums = append(nums, 1)
	nums = append(nums, 3)
	nums = append(nums, 2)
	nums = append(nums, 5)
	nums = append(nums, 4)
	fmt.Println("After adding elements, nums =", nums)

	/* Lista rendezése */
	nums = append(nums[:3], append([]int{6}, nums[3:]...)...) // A 6-os szám beszúrása a 3-as indexbe
	fmt.Println("Insert number 6 at index 3, get nums =", nums)

	/* Elem törlése */
	nums = append(nums[:3], nums[4:]...) // A 3-as indexű elem törlése
	fmt.Println("Remove element at index 3, get nums =", nums)

	/* Lista bejárása index alapján */
	count := 0
	for i := 0; i < len(nums); i++ {
		count += nums[i]
	}
	/* Listaelemek közvetlen bejárása */
	count = 0
	for _, x := range nums {
		count += x
	}

	/* Két lista összefűzése */
	nums1 := []int{6, 8, 7, 10, 9}
	nums = append(nums, nums1...) // A nums1 lista összefűzése a nums listával
	fmt.Println("Concatenate list nums1 to nums, get nums =", nums)

	/* Lista rendezése */
	sort.Ints(nums) // Rendezés után a lista elemei a legkisebbtől a legnagyobbig vannak rendezve
	fmt.Println("After sorting list, nums =", nums)
}
