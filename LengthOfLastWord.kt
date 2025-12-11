class Solution {
    fun lengthOfLastWord(s: String): Int {
        var len = 0
        var end = s.len - 1

        while(end >= 0 && s[end] == ' ') end--

        while(end >= 0 && s[end] != ' ') {
            len++
            end--
        }

        return len
    }
}