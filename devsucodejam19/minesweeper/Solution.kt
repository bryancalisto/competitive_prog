package minesweeper

class Solution {
    companion object {
        // Brute force solution
        fun sweep(arr: Array<Array<Char>>): Array<Array<Char>> {
            val m = arr.size
            val n = arr[0].size
            var up: Int
            var down: Int
            var mines: Int

            for (i in arr.indices) {
                for (j in 0 until n) {
                    if(arr[i][j] == 'x'){
                        continue
                    }
                    mines = 0
                    if (i > 0 && i < m - 1) {
                        if (j > 0 && j < n - 1) {
                            up = i - 1
                            down = i + 1
                            if (arr[up][j] == 'x') {
                                mines++
                            }
                            if (arr[up][j - 1] == 'x') {
                                mines++
                            }
                            if (arr[up][j + 1] == 'x') {
                                mines++
                            }
                            if (arr[down][j] == 'x') {
                                mines++
                            }
                            if (arr[down][j - 1] == 'x') {
                                mines++
                            }
                            if (arr[down][j + 1] == 'x') {
                                mines++
                            }
                            if (arr[i][j - 1] == 'x') {
                                mines++
                            }
                            if (arr[i][j + 1] == 'x') {
                                mines++
                            }
                            arr[i][j] = mines.digitToChar()

                        } else if(j > 0){
                            up = i - 1
                            down = i + 1
                            if (arr[up][j] == 'x') {
                                mines++
                            }
                            if (arr[up][j - 1] == 'x') {
                                mines++
                            }
                            if (arr[down][j] == 'x') {
                                mines++
                            }
                            if (arr[down][j - 1] == 'x') {
                                mines++
                            }
                            arr[i][j] = mines.digitToChar()

                        }
                        else{
                            up = i - 1
                            down = i + 1
                            if (arr[up][j] == 'x') {
                                mines++
                            }
                            if (arr[up][j + 1] == 'x') {
                                mines++
                            }
                            if (arr[down][j] == 'x') {
                                mines++
                            }
                            if (arr[down][j + 1] == 'x') {
                                mines++
                            }
                            arr[i][j] = mines.digitToChar()

                        }
                    }
                    else if(i == 0){
                        if (j > 0 && j < n - 1) {
                            down = i + 1
                            if (arr[down][j] == 'x') {
                                mines++
                            }
                            if (arr[down][j - 1] == 'x') {
                                mines++
                            }
                            if (arr[down][j + 1] == 'x') {
                                mines++
                            }
                            if (arr[i][j - 1] == 'x') {
                                mines++
                            }
                            if (arr[i][j + 1] == 'x') {
                                mines++
                            }
                            arr[i][j] = mines.digitToChar()

                        } else if(j > 0){
                            down = i + 1
                            if (arr[down][j] == 'x') {
                                mines++
                            }
                            if (arr[down][j - 1] == 'x') {
                                mines++
                            }
                            arr[i][j] = mines.digitToChar()

                        }
                        else{
                            down = i + 1
                            if (arr[down][j] == 'x') {
                                mines++
                            }
                            if (arr[down][j + 1] == 'x') {
                                mines++
                            }
                            arr[i][j] = mines.digitToChar()

                        }

                    }
                    else{
                        if (j > 0 && j < n - 1) {
                            up = i - 1
                            if (arr[up][j] == 'x') {
                                mines++
                            }
                            if (arr[up][j - 1] == 'x') {
                                mines++
                            }
                            if (arr[up][j + 1] == 'x') {
                                mines++
                            }
                            if (arr[i][j - 1] == 'x') {
                                mines++
                            }
                            if (arr[i][j + 1] == 'x') {
                                mines++
                            }
                            arr[i][j] = mines.digitToChar()

                        } else if(j > 0){
                            up = i - 1
                            if (arr[up][j] == 'x') {
                                mines++
                            }
                            if (arr[up][j - 1] == 'x') {
                                mines++
                            }
                            arr[i][j] = mines.digitToChar()

                        }
                        else{
                            up = i - 1
                            if (arr[up][j] == 'x') {
                                mines++
                            }
                            if (arr[up][j + 1] == 'x') {
                                mines++
                            }
                            arr[i][j] = mines.digitToChar()

                        }

                    }
                }
            }
            return arr
        }
    }
}

fun main() {
    val arr = arrayOf(
        arrayOf(' ', ' ', ' ', 'x', ' ', ' ', ' ', 'x', ' '),
        arrayOf(' ', 'x', ' ', ' ', 'x', ' ', ' ', ' ', 'x'),
        arrayOf(' ', 'x', ' ', ' ', ' ', 'x', 'x', 'x', 'x'),
        arrayOf(' ', ' ', ' ', 'x', ' ', 'x', ' ', 'x', ' '),
        arrayOf(' ', ' ', ' ', ' ', ' ', 'x', 'x', 'x', ' '),
        arrayOf(' ', 'x', ' ', ' ', 'x', 'x', 'x', ' ', ' ')
    )

    Solution.sweep(arr).forEach { i ->
        i.forEach { c ->
            print("$c ")
        }
        println()
    }
}