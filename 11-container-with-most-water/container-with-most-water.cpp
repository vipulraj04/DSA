class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;

        while (left < right) {
            int heights = min(height[left], height[right]);
            int width = right - left;

            int area = heights * width;
            result = max(area, result);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};
