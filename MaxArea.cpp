class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int answer = 0;
        int size = height.size();
        int start = 0;
        int end = size - 1;

        while (start < size && end > start) {
            int val = 0;
            if (height[start] > height[end]) {
                area = (end - start) * height[end];
            } else {
                area = (end - start) * height[start];
            }
    
            if (area > answer) {
                answer = area;
            }
            if ((height[start] > height[end])) {
                val = height[end];
                while (end > start && height[end] <= val) {
                    end--;
                }
            } else {
                val = height[start];
                while (start < end && height[start] <= val) {
                    start++;
                }
            }
        }
        return answer;
    }
};