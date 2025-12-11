class Solution {
    fun plusOne(digits: IntArray): IntArray {
        var i = 0
        while (i < digits.size && digits[i] == 9) {
            i++
        }
        var size = if (i == digits.size) {
            digits.size + 1
        } else {
            digits.size
        }
        var result = IntArray(size)
        var end = digits.size - 1
        var resEnd = result.size - 1

        while(end >= 0 && digits[end] == 9) {
            result[resEnd] = 0
            end--
            resEnd--
        }
        if (end < 0) {
            result[resEnd] = 1
        } else {
            result[resEnd] = digits[end] + 1
            resEnd--
            end--
            while (end >= 0) {
                result[resEnd] = digits[end]
                resEnd--
                end--
            }
        }

        return result
    }
}