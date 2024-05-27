class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2=0;
        vector<int> res;
        while (p1 < m and p2 < n) {
            if (nums1[p1] < nums2[p2]) {
                res.push_back(nums1[p1]);
                p1++;
            } else {
                res.push_back(nums2[p2]);
                p2++;
            }
        }
        if (p1 != m) {
            for (int i = p1; i < m; i++) {
                res.push_back(nums1[i]);
            }
        }
        if (p2 != n) {
            for (int i = p2; i < n; i++) {
                res.push_back(nums2[i]);
            }
        }
        nums1 = res;
    }
};