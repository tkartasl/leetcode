class Solution {
    fun climbStairs(n: Int): Int {
        when (n) {
            1 -> return 1
            2 -> return 2
            3 -> return 3
        }
        var prev = 3
        var prev2 = 2
        var temp = 0
        for (i in 4..n) {
            temp = prev
            prev += prev2
            prev2 = temp
        }
        return prev
    }
}
