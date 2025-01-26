class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count; // Count the frequency of each element
        for (auto &i : nums) {
            count[i]++;
        }

        // Create buckets where index represents frequency
        vector<vector<int>> bucket(nums.size() + 1);
        for (const auto &ele : count) {
            bucket[ele.second].push_back(ele.first); // Group numbers by frequency
        }

        vector<int> res;
        // Iterate through the buckets from the end (highest frequency)
        for (int i = bucket.size() - 1; i >= 0 && res.size() < k; --i) {
            for (const auto &num : bucket[i]) {
                res.push_back(num); // Collect top k frequent elements
                if (res.size() == k) break;
            }
        }

        return res;
    }
};
