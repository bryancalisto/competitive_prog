package productSubarray

import kotlin.math.max
import kotlin.math.min


class Solution {
    companion object {
        fun findSubarray(arr: Array<Double>): Array<Double> {
//            var maxSoFar = 1.0
//            var minSoFar = 1.0
//            var maxTemp: Double
//            var res = arr.maxOrNull()
//            var start = 0
//            var end = 0
//            var bestStart = 0
//            var bestEnd = 0
//
//            for (i in arr.indices) {
//
//                if (arr[i] == 0.0) {
//                    maxSoFar = 1.0
//                    minSoFar = 1.0
//                    continue
//                }
//                maxTemp = maxSoFar * arr[i]
//                maxSoFar = max(minSoFar * arr[i], maxSoFar * arr[i])
//                maxSoFar = max(maxSoFar, arr[i])
//                minSoFar = min(minSoFar * arr[i], maxTemp)
//                if (res != null) {
//                    res = max(res, maxSoFar)
//                    res = max(res, minSoFar)
//                }
//            }
//
//            println("max prod = $res")
//            println("$bestStart $bestEnd")
//            return arr.copyOfRange(bestStart, bestEnd)

            var maxSoFar: Double
            var res = arr[0]
            var start = 0
            var end = 0

            for (i in arr.indices) {
                maxSoFar = 1.0
                for (j in i until arr.size) {
                    if (arr[j] == 0.0) {
                        maxSoFar = 1.0
                        continue
                    }

                    maxSoFar *= arr[j]
                    if (maxSoFar > res) {
                        res = maxSoFar
                        start = i
                        end = j
                    }
                }
            }

            println("max prod = $res")
            println("$start $end")
            return arr.copyOfRange(start, end + 1)
        }
    }
}

fun main() {
    Solution.findSubarray(arrayOf(-3.2, 4.2, 7.0, 5.4, -2.2, -2.5)).forEach { i -> print("$i ") }
}