https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

func strStr(haystack string, needle string) int {
    if strings.Contains(haystack, needle) == false {
        return -1
    }
    i := 0
    start := 0

    for i < len(haystack) {
        if haystack[i] == needle[start] {
            if (i + len(needle)) <= len(haystack) && strings.Compare(haystack[i: i + len(needle)], needle) == 0 {
                return i
            }
        }
		i++
    }
    return -1
}