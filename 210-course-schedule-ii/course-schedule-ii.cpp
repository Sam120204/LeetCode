class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (const auto& pre:prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i); // Add courses with no prerequisites
        }
        vector<int> order;
        while (!q.empty()) {
            int course = q.front(); q.pop();
            order.push_back(course); // Add course to order
            for (int next : graph[course]) {
                inDegree[next]--;
                if (inDegree[next] == 0) q.push(next); // Add next course if no prerequisites
            }
        }
        return order.size() == numCourses ? order : vector<int>(); 
    }
};