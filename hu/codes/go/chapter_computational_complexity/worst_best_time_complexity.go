// File: worst_best_time_complexity.go
// Created Time: 2022-12-13
// Author: msk397 (machangxinq@gmail.com), cathay (cathaycchen@gmail.com)

package chapter_computational_complexity

import (
	"math/rand"
)

/* { 1, 2, ..., n } elemekből álló tömb generálása véletlenszerű sorrendben */
func randomNumbers(n int) []int {
	nums := make([]int, n)
	// nums = { 1, 2, 3, ..., n } tömb generálása
	for i := 0; i < n; i++ {
		nums[i] = i + 1
	}
	// Tömbelemek véletlenszerű összekeverése
	rand.Shuffle(len(nums), func(i, j int) {
		nums[i], nums[j] = nums[j], nums[i]
	})
	return nums
}

/* Az 1-es szám indexének keresése a nums tömbben */
func findOne(nums []int) int {
	for i := 0; i < len(nums); i++ {
		// Ha az 1-es elem a tömb elején van, a legjobb időbonyolultság O(1) érhető el
		// Ha az 1-es elem a tömb végén van, a legrosszabb időbonyolultság O(n) érhető el
		if nums[i] == 1 {
			return i
		}
	}
	return -1
}
