// File: array.go
// Created Time: 2022-12-29
// Author: GuoWei (gongguowei01@gmail.com), cathay (cathaycchen@gmail.com)

package chapter_array_and_linkedlist

import (
	"math/rand"
)

/* Véletlenszerű hozzáférés egy elemhez */
func randomAccess(nums []int) (randomNum int) {
	// Véletlenszerűen válassz egy számot a [0, nums.length) intervallumból
	randomIndex := rand.Intn(len(nums))
	// Kérj le és adj vissza egy véletlen elemet
	randomNum = nums[randomIndex]
	return
}

/* Tömb hosszának bővítése */
func extend(nums []int, enlarge int) []int {
	// Inicializálj egy tömböt a bővített hosszal
	res := make([]int, len(nums)+enlarge)
	// Másold át az összes elemet az eredeti tömbből az új tömbbe
	for i, num := range nums {
		res[i] = num
	}
	// Adj vissza a bővített új tömböt
	return res
}

/* Az index pozícióba szúrd be a num elemet a tömbben */
func insert(nums []int, num int, index int) {
	// Toljuk hátra egy pozícióval az összes elemet az index pozíciótól kezdve
	for i := len(nums) - 1; i > index; i-- {
		nums[i] = nums[i-1]
	}
	// Rendelj num értéket az index pozícióbeli elemhez
	nums[index] = num
}

/* Töröld az index pozícióbeli elemet */
func remove(nums []int, index int) {
	// Toljuk előre egy pozícióval az összes elemet az index pozíció után
	for i := index; i < len(nums)-1; i++ {
		nums[i] = nums[i+1]
	}
}

/* Tömb bejárása */
func traverse(nums []int) {
	count := 0
	// Tömb bejárása index alapján
	for i := 0; i < len(nums); i++ {
		count += nums[i]
	}
	count = 0
	// Tömbelemek közvetlen bejárása
	for _, num := range nums {
		count += num
	}
	// Index és elemek egyidejű bejárása
	for i, num := range nums {
		count += nums[i]
		count += num
	}
}

/* A megadott elem keresése a tömbben */
func find(nums []int, target int) (index int) {
	index = -1
	for i := 0; i < len(nums); i++ {
		if nums[i] == target {
			index = i
			break
		}
	}
	return
}
