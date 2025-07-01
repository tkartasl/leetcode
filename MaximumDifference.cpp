class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int dif = 0;
        int answer = 0;
        int prev_num = 0;
        int size = nums.size();

        while (i < size) {
            j = i + 1;
            prev_num = nums[i];
            while (j < size) {
                if (nums[j] > prev_num) {
                    dif = nums[j] - prev_num;
                }
                if (dif > answer) {
                    answer = dif;
                }
                j++;
            }
            while (i < size && nums[i] >= prev_num) {
                i++;
            }
        }
        if (answer == 0) {
            return -1;
        }
        return answer;
    }
};