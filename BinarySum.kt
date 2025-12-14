class Solution {
    fun addBinary(a: String, b: String): String {
        var str1: String = ""
        var str2: String = ""

        if (a.length == b.length) {
            str1 = a
            str2 = b
        } else {
            var sb = if (a.length < b.length) {
                StringBuilder(a)
            } else {
                StringBuilder(b)
            }

            val dif = if (a.length < b.length) {
                b.length - a.length
            } else {
                a.length - b.length
            }

            for (i in 0 until dif) {
                sb.insert(0, '0')
            }
            str1 = sb.toString()
            str2 = if (a.length > b.length) {
                a
            } else {
                b
            }
        }
        var sbResult = StringBuilder("")
        var carry: Int = 0

        for (i in (str2.length - 1) downTo 0) {
            if (str1[i] == '1' && str2[i] == '1') {
                if (carry == 1) {
                    sbResult.insert(0, '1')
                } else { sbResult.insert(0, '0') }

                carry = 1
            } else if (str1[i] == '0' && str2[i] == '0') {
                if (carry == 1) {
                    sbResult.insert(0, '1')
                } else sbResult.insert(0, '0')
                carry = 0
            } else {
                if (carry == 0) {
                    sbResult.insert(0, '1')
                } else sbResult.insert(0, '0')
            }
        }
        if (carry == 1) {sbResult.insert(0, '1')}
        return sbResult.toString()
    }
}