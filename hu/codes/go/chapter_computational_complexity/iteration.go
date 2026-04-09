// File: iteration.go
// Created Time: 2023-08-28
// Author: Reanon (793584285@qq.com)

package chapter_computational_complexity

import "fmt"

/* for ciklus */
func forLoop(n int) int {
	res := 0
	// 1, 2, ..., n-1, n összege
	for i := 1; i <= n; i++ {
		res += i
	}
	return res
}

/* while ciklus */
func whileLoop(n int) int {
	res := 0
	// Feltételváltozó inicializálása
	i := 1
	// 1, 2, ..., n-1, n összege
	for i <= n {
		res += i
		// Feltételváltozó frissítése
		i++
	}
	return res
}

/* while ciklus (két frissítéssel) */
func whileLoopII(n int) int {
	res := 0
	// Feltételváltozó inicializálása
	i := 1
	// 1, 4, 10, ... összege
	for i <= n {
		res += i
		// Feltételváltozó frissítése
		i++
		i *= 2
	}
	return res
}

/* Egymásba ágyazott for ciklus */
func nestedForLoop(n int) string {
	res := ""
	// i = 1, 2, ..., n-1, n ciklus
	for i := 1; i <= n; i++ {
		for j := 1; j <= n; j++ {
			// j = 1, 2, ..., n-1, n ciklus
			res += fmt.Sprintf("(%d, %d), ", i, j)
		}
	}
	return res
}
