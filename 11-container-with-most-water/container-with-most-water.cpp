class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1, res = 0;
        while (start < end) {
            int width = end-start;
            int h = min(height[start], height[end]);
            int temp = width * h;
            res = max(res, temp);
            if (height[start] < height[end]) start++;
            else end--;
        }
        return res;
    }
};