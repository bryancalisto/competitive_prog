class Solution {
    companion object {
        fun encrypt(str: String?, key: String?): String {
            var theKey = key
            val encrypted = StringBuilder()
            val vowels = mapOf(
                'a' to 1, 'e' to 2, 'i' to 3, 'o' to 4, 'u' to 5, 'A' to 6, 'E' to 7,
                'I' to 8, 'O' to 9, 'U' to 10
            )

            if (str.isNullOrEmpty()) {
                return ""
            }

            if (theKey.isNullOrEmpty()) {
                theKey = "DCJ"
            }

            for (c in str) {
                if (vowels[c] != null) {
                    encrypted.append(theKey + c)
                } else {
                    encrypted.append(c)
                }
            }
            return encrypted.toString()
        }
    }
}

fun main() {
    println("RES= ${Solution.encrypt("hola", null)}")
    println("RES= ${Solution.encrypt("I love prOgrAmming!", "dcj")}")
}