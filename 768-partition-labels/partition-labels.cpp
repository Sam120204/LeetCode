class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Step 1: Create an array to store the last occurrence of each character
        int M[256] = {0}; // Fixed size array for ASCII characters
        for (int i = 0; i < s.size(); ++i) {
            M[s[i]] = i; // Store the last index of character s[i]
        }

        // Step 2: Iterate through the string and calculate partitions
        vector<int> partitions;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); ++i) {
            end = max(end, M[s[i]]); // Update the current partition's end index
            if (i == end) { // If the current index reaches the partition's end
                partitions.push_back(end - start + 1); // Add partition size to the result
                start = i + 1; // Start a new partition
            }
        }

        return partitions;
    }
};