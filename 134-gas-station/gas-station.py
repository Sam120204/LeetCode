class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        now_gas = 0
        start = 0

        if sum(gas) < sum(cost):
            return -1

        for i in range(len(gas)):
            now_gas += gas[i] - cost[i]
            if now_gas < 0:
                now_gas = 0
                start = i + 1

        return start

        