//https://leetcode.com/problems/integer-to-roman/
class Solution {
    companion object {
        fun intToRoman(num: Int): String {
            val str = StringBuilder()
            var res = num
            val nums = mapOf<Int, String>(
                1000 to "M",
                900 to "CM",
                500 to "D",
                400 to "CD",
                100 to "C",
                90 to "XC",
                50 to "L",
                40 to "XL",
                10 to "X",
                9 to "IX",
                5 to "V",
                4 to "IV",
                1 to "I",
            )

            var i = nums.keys.iterator()
            var key = i.next()

            while (res > 0) {
                if (res >= key) {
                    str.append(nums[key])
                    res -= key
                } else {
                    if (i.hasNext()) {
                        key = i.next()
                    }
                }
            }

            return str.toString()
        }

    }
}

fun main() {
    println("RES= ${Solution.intToRoman(999)}")
}