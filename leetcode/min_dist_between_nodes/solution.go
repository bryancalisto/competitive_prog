// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
/**
 * Definition for a binary tree node.
 */

package main

import (
	"fmt"
	"math"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func helper(root *TreeNode, prevVals *[]int) {
	if root != nil {
		*prevVals = append(*prevVals, root.Val)
		helper(root.Left, prevVals)
		helper(root.Right, prevVals)
	}
}

func minDiffInBST(root *TreeNode) int {
	var res int
	var prevVals []int
	minim := 100000
	helper(root, &prevVals)

	for i := 0; i < len(prevVals)-1; i++ {
		res = int(math.Abs(float64(prevVals[i] - prevVals[i+1])))
		if res < minim {
			minim = res
		}
	}

	return minim
}

func main() {
	// var root = &TreeNode{Val: 1, Left: &TreeNode{Val: 0}}
	// root.Right = &TreeNode{Val: 48, Left: &TreeNode{Val: 12}, Right: &TreeNode{Val: 49}}
	//[27,null,34,null,58,50,null,44]
	var root = &TreeNode{Val: 27, Right: &TreeNode{Val: 34}}
	root.Right.Left = &TreeNode{Val: 50, Left: &TreeNode{Val: 44}}
	fmt.Println(minDiffInBST(root))
}
