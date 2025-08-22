class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        total = 0      # total net gas across all stations
        tank = 0       # current tank while scanning
        start = 0      # candidate start index

        for i in range(len(gas)):
            diff = gas[i] - cost[i]
            total += diff
            tank += diff
            # If we run out before reaching i+1, any start in [start, i] fails
            if tank < 0:
                start = i + 1
                tank = 0

        return start if total >= 0 else -1
