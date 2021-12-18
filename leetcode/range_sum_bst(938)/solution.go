//https://leetcode.com/problems/range-sum-of-bst/
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var sum int

func helper(root *TreeNode, low int, high int, sum *int) {
	fmt.Println(root.Val)
	if root.Left != nil {
		helper(root.Left, low, high, sum)
	}

	if root.Val >= low && root.Val <= high {
		*sum += root.Val
	}

	if root.Right != nil {
		helper(root.Right, low, high, sum)
	}
}

func rangeSumBST(root *TreeNode, low int, high int) int {
	sum = 0
	helper(root, low, high, &sum)
	return sum
}

func main() {
	var root = &TreeNode{}
	root.Val = 10
	root.Left = &TreeNode{Val: 5, Left: &TreeNode{Val: 3}, Right: &TreeNode{Val: 7}}
	root.Right = &TreeNode{Val: 15, Right: &TreeNode{Val: 18}}
	low := 7
	high := 15
	fmt.Println(rangeSumBST(root, low, high))
}
