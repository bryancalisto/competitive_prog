package trackMyTime

import kotlin.math.truncate

class Solution {
    companion object {
        fun extractTime(times: Array<Int>): Array<Int> {
            val res = arrayOf(0,0,0,0,0)
            var sum = 0

            times.forEach { t ->
                if(t > 0){
                    sum += t
                }
            }

            res[0] = sum / 86400000
            sum -= 86400000 * res[0]
            res[1] = sum / 3600000
            sum -= 3600000 * res[1]
            res[2] = sum / 60000
            sum -= 60000 *res[2]
            res[3] = sum / 1000
            sum -= 1000 * res[3]
            res[4] = sum % 1000

            return res
        }
    }
}

fun main() {
    Solution.extractTime(arrayOf(65647440, 199644521)).forEach { i-> print("$i ") }
}
