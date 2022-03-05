from collections import defaultdict


class Graph:
    def __init__(self, vertices):
        self.V = vertices  # No. of vertices
        self.graph = defaultdict(list)  # default dictionary to store graph

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def isReachable(self, s, d):
        visited = [False] * (self.V)

        queue = []

        queue.append(s)
        visited[s] = True

        while queue:

            n = queue.pop(0)

            if n == d:
                return True

            for i in self.graph[n]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True
        return False


n, q = map(int, input().split())
temp_string = input()
arr = [int(bit) for bit in temp_string]

g = Graph(n)
for i in range(n - 1):
    for j in range(i + 1, n):
        if arr[i] == arr[j]:
            g.addEdge(i, j)
        else:
            g.addEdge(j, i)

# could not solve
