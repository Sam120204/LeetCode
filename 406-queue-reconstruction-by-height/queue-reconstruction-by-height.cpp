class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& p1, const vector<int>& p2) {
            return p1[0] > p2[0] || (p1[0] == p2[0] and p1[1] < p2[1]);
        });

        
        // Example input: [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]].
        // After sorting: [[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]].

        // Insert person at index k in the queue:
        // Insert [7,0] → [[7,0]].
        // Insert [7,1] → [[7,0],[7,1]].
        // Insert [6,1] → [[7,0],[6,1],[7,1]].
        // Insert [5,0] → [[5,0],[7,0],[6,1],[7,1]].
        // Insert [5,2] → [[5,0],[7,0],[5,2],[6,1],[7,1]].
        // Insert [4,4] → [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]].

        vector<vector<int>> queue;
        for (const auto & person : people) {
            queue.insert(queue.begin() + person[1], person);
        }
        return queue;
    }
};