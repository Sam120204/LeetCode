class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
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
        
        while (p1 < m) {
            res.push_back(nums1[p1]);
            p1++;
        }
        

        
        while (p2 < n) {
            res.push_back(nums2[p2]);
            p2++;
        }
        
        
        nums1 = res;
    }
};