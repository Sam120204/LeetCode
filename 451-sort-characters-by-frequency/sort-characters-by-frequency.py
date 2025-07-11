class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Step 1: Count character frequencies using a plain dictionary
        freq = {}
        for char in s:
            if char in freq:
                freq[char] += 1
            else:
                freq[char] = 1

        # Step 2: Create buckets where index = frequency
        max_freq = max(freq.values())
        buckets = [[] for _ in range(max_freq + 1)]

        for char, count in freq.items():
            buckets[count].append(char)

        # Step 3: Build the result from high freq to low
        result = []
        for i in range(len(buckets) - 1, 0, -1):
            for char in buckets[i]:
                result.append(char * i)

        return ''.join(result)
