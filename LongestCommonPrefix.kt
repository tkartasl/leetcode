package org.example

class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        if (strs.isEmpty()) {
            return ""
        }
        val first = strs[0]
        var longest = first.length
        var count = 0
        var i = 0

        for (x in strs) {
            if (x.isEmpty()) {
                return ""
            }

            while(i < x.length && i < first.length && x[i] == first[i]) {
                i++
            }
            if (i > 0) {
                if (i < longest)
                    longest = i
                count++
                i = 0
            }
        }
        if (count != strs.size)
            return ""
        if(longest == 0)
            return first.substring(0,1)
        return first.substring(0, longest)
    }
}

fun main() {
    val solution = Solution()
    val strs = arrayOf("aaa","aa", "aaa")
    val ret = solution.longestCommonPrefix(strs)
    println("ret is $ret")
}
