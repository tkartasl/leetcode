/*Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.*/

#include <iostream>
#include <string.h>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.empty()) {
            return 0;
        }
        std::string substr;
        int size = s.size();
        int length = 0;
        int pos = 0;

        for (int i = 0; i < size; i++) {
            pos = substr.find(s[i]);
            if (pos == std::string::npos) {
                substr += s[i];
                if (substr.size() > length) {
                    length = substr.size();
                } 
            } else {
                if (pos + 1 < substr.size()) {
                    substr = substr.substr(pos + 1, std::string::npos);
                } else {
                    substr.clear();
                }
                substr += s[i];
            }
        }
        return length;
    }
};