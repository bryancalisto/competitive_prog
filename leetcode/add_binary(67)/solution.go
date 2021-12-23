package main

import (
	"fmt"
	"strings"
)

func reverse(s string) string {
	rns := []rune(s)
	for i, j := 0, len(rns)-1; i < j; i, j = i+1, j-1 {
		rns[i], rns[j] = rns[j], rns[i]
	}

	return string(rns)
}

var asciiToDigits = map[byte]byte{48: 0, 49: 1}
var digitsToAscii = map[byte]byte{0: 48, 1: 49}

func addBinary(a string, b string) string {
	res := strings.Builder{}
	lenA := len(a)
	lenB := len(b)
	var currentSum byte = 0
	var carry byte = 0
	var indexA int
	var indexB int

	if lenA > lenB {
		for i := 0; i < lenA; i++ {
			indexA = lenA - i - 1
			indexB = lenB - i - 1
			currentSum = carry + byte(asciiToDigits[a[indexA]])

			if i < lenB {
				currentSum += byte(asciiToDigits[b[indexB]])
			}

			if currentSum == 2 {
				res.WriteString(string("0"))
				carry = 1
			} else if currentSum == 3 {
				res.WriteString(string("1"))
			} else {
				res.WriteString(string(digitsToAscii[currentSum]))
				carry = 0
			}
		}
	} else {
		for i := 0; i < lenB; i++ {
			indexA = lenA - i - 1
			indexB = lenB - i - 1
			currentSum = carry + byte(asciiToDigits[b[indexB]])

			if i < lenA {
				currentSum += byte(asciiToDigits[a[indexA]])
			}

			if currentSum == 2 {
				res.WriteString(string("0"))
				carry = 1
			} else if currentSum == 3 {
				res.WriteString(string("1"))
			} else {
				res.WriteString(string(digitsToAscii[currentSum]))
				carry = 0
			}
		}
	}

	if carry > 0 {
		res.WriteString("1")
	}

	return reverse(res.String())
}

func main() {
	num1 := "1111"
	num2 := "1111"
	fmt.Println(addBinary(num1, num2))
}
