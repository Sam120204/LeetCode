class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> count;
        for (auto& i : s) {
            count[i]++;
        }

        // Step 2: Create buckets where the index represents the frequency
        vector<string> bucket(s.size() + 1); // Use string instead of vector<int>
        for (const auto& ele : count) {
            bucket[ele.second].append(ele.second, ele.first); // Add character multiple times
        }

        // Step 3: Build the result string by iterating buckets in reverse order
        string result;
        for (int i = bucket.size() - 1; i > 0; --i) {
            if (!bucket[i].empty()) {
                result += bucket[i]; // Append all characters with the same frequency
            }
        }

        return result;
    }
};
