#include <algorithm>

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0 || size == 1) {
            return 0;
        }
        int longest = 0;
        int i = 0;
        int j = 0;
        std::sort(nums.begin(), nums.end());

        while (i < size) {
            int num = nums[i];
            int count = 0;
            int dif = 0;
            j = i;
            while (j < size && nums[j] < num + 2) {
                if (nums[j] == num || nums[j] == num + 1) {
                    if (nums[j] == num + 1) {
                        dif = 1;
                    }
                    count++;
                }
                j++;
            }
            if (count > longest && dif == 1) {
                longest = count;
            }
            if (dif == 0) {
                i += count;
            } else {
                while (i < size && nums[i] == num) {
                    i++;
                }
            }  
        }
        return longest;
    }
};