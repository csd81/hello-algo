// File: space_complexity_test.go
// Created Time: 2022-12-15
// Author: cathay (cathaycchen@gmail.com)

package chapter_computational_complexity

import (
	"testing"

	. "github.com/krahets/hello-algo/pkg"
)

func TestSpaceComplexity(t *testing.T) {
	n := 5
	// Konstans rend
	spaceConstant(n)
	// Lineáris rend
	spaceLinear(n)
	spaceLinearRecur(n)
	// Exponenciális rend
	spaceQuadratic(n)
	spaceQuadraticRecur(n)
	// Exponenciális rend
	root := buildTree(n)
	PrintTree(root)
}
