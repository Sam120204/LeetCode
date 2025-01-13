class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, vector<int>> pos;
        for (int i = 0; i < s.size(); i++) {
            if (pos.find(s[i]) == pos.end()) {
                pos[s[i]] = {i, i};
            } else {
                pos[s[i]][1] = i;
            }
        }

        for (const auto& pair : pos) {
            cout << pair.first << ": " << pair.second[0] << " " << pair.second[1] << endl;
        }

        vector<int> partitions;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, pos[s[i]][1]);
            if (i == end) {
                partitions.push_back(end-start+1);
                start=i+1;
            }
        }
        return partitions;
    }
};