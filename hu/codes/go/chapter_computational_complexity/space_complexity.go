// File: space_complexity.go
// Created Time: 2022-12-15
// Author: cathay (cathaycchen@gmail.com)

package chapter_computational_complexity

import (
	"fmt"
	"strconv"

	. "github.com/krahets/hello-algo/pkg"
)

/* Struktúra */
type node struct {
	val  int
	next *node
}

/* Csomópont-struktúra létrehozása */
func newNode(val int) *node {
	return &node{val: val}
}

/* Függvény */
func function() int {
	// Végrehajt néhány műveletet...
	return 0
}

/* Konstans rend */
func spaceConstant(n int) {
	// Konstansok, változók, objektumok O(1) helyet foglalnak
	const a = 0
	b := 0
	nums := make([]int, 10000)
	node := newNode(0)
	// A ciklusban lévő változók O(1) helyet foglalnak
	var c int
	for i := 0; i < n; i++ {
		c = 0
	}
	// A ciklusban lévő függvények O(1) helyet foglalnak
	for i := 0; i < n; i++ {
		function()
	}
	b += 0
	c += 0
	nums[0] = 0
	node.val = 0
}

/* Lineáris rend */
func spaceLinear(n int) {
	// n hosszúságú tömb O(n) helyet használ
	_ = make([]int, n)
	// n hosszúságú lista O(n) helyet foglal
	var nodes []*node
	for i := 0; i < n; i++ {
		nodes = append(nodes, newNode(i))
	}
	// n hosszúságú hash tábla O(n) helyet foglal
	m := make(map[int]string, n)
	for i := 0; i < n; i++ {
		m[i] = strconv.Itoa(i)
	}
}

/* Lineáris rend (rekurzív implementáció) */
func spaceLinearRecur(n int) {
	fmt.Println("Recursion n =", n)
	if n == 1 {
		return
	}
	spaceLinearRecur(n - 1)
}

/* Exponenciális rend */
func spaceQuadratic(n int) {
	// A mátrix O(n^2) helyet használ
	numMatrix := make([][]int, n)
	for i := 0; i < n; i++ {
		numMatrix[i] = make([]int, n)
	}
}

/* Négyzetes rend (rekurzív implementáció) */
func spaceQuadraticRecur(n int) int {
	if n <= 0 {
		return 0
	}
	nums := make([]int, n)
	fmt.Printf("In recursion n = %d, nums length = %d \n", n, len(nums))
	return spaceQuadraticRecur(n - 1)
}

/* Driver Code */
func buildTree(n int) *TreeNode {
	if n == 0 {
		return nil
	}
	root := NewTreeNode(0)
	root.Left = buildTree(n - 1)
	root.Right = buildTree(n - 1)
	return root
}
