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


def main():
    n, m = map(int, input().split())

    graph = Graph(n)
    for _ in range(m):
        u, v = map(int, input().split())
        graph.addEdge(u - 1, v - 1)

    cc = graph.connectedComponents()
    answer = 1
    for component in cc:
        answer *= 2 ** (len(component) - 1)
    print(answer)


if __name__ == "__main__":
    main()

# correct
