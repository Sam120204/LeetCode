class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> fleet;
        if (position.size() == 1) return 1;
        map<int, int> ori_pos = {};
        for (int i = 0; i < position.size(); i++) {
            ori_pos[position[i]] = i;
        }
        sort(position.rbegin(), position.rend());
        double first = static_cast<double>(target - position[0]) / speed[ori_pos[position[0]]];
        double maxx = first;
        fleet.push(first);
        for (int i = 1; i < position.size(); i++) {
            double t = time(target, position[i], speed[ori_pos[position[i]]]);
            if (t > maxx) {
                fleet.push(t);
                maxx = max(t, maxx);
            }
        }

        return fleet.size();
    }
    double time(int target, int pos2, double speed2) {
        return (target - pos2) / speed2;
    }
};