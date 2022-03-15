import sys

sys.setrecursionlimit(10**6)


class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def DFSUtil(self, temp, v, visited):

        visited[v] = True
        temp.append(v)

        for i in self.adj[v]:
            if not visited[i]:

                temp = self.DFSUtil(temp, i, visited)
        return temp

    def addEdge(self, v, w):
        self.adj[v].append(w)
        self.adj[w].append(v)

    def connectedComponents(self):
        visited = []
        cc = []
        for _ in range(self.V):
            visited.append(False)
        for v in range(self.V):
            if not visited[v]:
                temp = []
                cc.append(self.DFSUtil(temp, v, visited))
        return cc


n, m = map(int, input().split())
graph = Graph(n)

for _ in range(m):
    temp_arr = list(map(int, input().split()))
    temp_length, temp_arr = temp_arr[0], temp_arr[1:]
    for i in range(temp_length - 1):
        graph.addEdge(temp_arr[i] - 1, temp_arr[i + 1] - 1)

cc = graph.connectedComponents()
answer_dict = {}
for component in cc:
    length = len(component)
    for node in component:
        answer_dict[node] = length

for i in range(n):
    print(answer_dict.get(i, 1), end=" ")

# runtime error, try later with cpp
