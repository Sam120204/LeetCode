class Solution {
public:
    bool judgeSquareSum(int c) {
    for (int a = 0; a <= std::sqrt(c); ++a) {
            int bSquare = c - a * a;
            int b = std::sqrt(bSquare);
            if (b * b == bSquare) {
                return true;
            }
        }
        return false;
    }
};