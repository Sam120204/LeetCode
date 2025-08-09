class Solution(object):
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        # we define 0 to be unlabeled color, 1 to be group A, -1 to be group B
        n = len(graph)
        colors = [0] * n # [0 for i in range(n)]
        
        for i in range(n):
            if colors[i] != 0:
                continue
            
            # bfs starting from current node
            q = deque([i])
            colors[i] = 1

            while q:
                node = q.popleft()
                for nei in graph[node]:
                    if colors[nei] == 0:
                        colors[nei] = -colors[node]
                        q.append(nei)
                    elif colors[nei] == colors[node]:
                        # such edge links to same group, same color
                        return False
        return True


