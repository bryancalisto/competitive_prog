//https://leetcode.com/problems/zigzag-conversion/
class Solution {
    companion object {
        fun convert(s: String, numRows: Int): String {

            if (numRows == 1) {
                return s
            }

            var j: Int
            val res = StringBuilder()
            val mainInterval = numRows * 2 - 2 // Discovered pattern

            for (i in 0 until numRows) {
                j = i
                while (j < s.length) {
                    res.append(s[j])
                    if (i != 0 && i != numRows - 1 && j + mainInterval - i * 2 < s.length) {
                        res.append(s[j + mainInterval - i * 2])
                    }
                    j += mainInterval
                }
            }

            return res.toString()
        }

    }
}

fun main() {
    val s = "PAYPALISHIRING"
    /*
    * P - 0                     I - 6                   N - 12
    * A - 1             L - 5   S - 7           I - 11  G - 13
    * Y - 2     A - 4           R - 8   S - 10
    * P - 3                     I - 9
    * */
    val numRows = 4
    println(Solution.convert(s, numRows))
}
