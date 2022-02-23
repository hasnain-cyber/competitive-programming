class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def DFSUtil(self, temp, v, visited):

        visited[v] = True
        temp.append(v)

        for i in self.adj[v]:
            if visited[i] == False:

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
            if visited[v] == False:
                temp = []
                cc.append(self.DFSUtil(temp, v, visited))
        return cc


if __name__ == "__main__":
    n = int(input())
    arr = [tuple(input().split()) for _ in range(n)]

    g = Graph(n)
    for i in range(n - 1):
        for j in range(i + 1, n):
            element1, element2 = arr[i], arr[j]
            if element1[0] == element2[0] or element1[1] == element2[1]:
                g.addEdge(i, j)
    print(len(g.connectedComponents()) - 1)

# correct
