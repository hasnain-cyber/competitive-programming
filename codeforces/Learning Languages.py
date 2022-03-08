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


def main():
    n, m = map(int, input().split())
    arr = [list(map(int, input().split()[1:])) for _ in range(n)]

    flag = True
    for element in arr:
        if len(element) != 0:
            flag = False
            break
    if flag:
        print(n)
    else:
        graph = Graph(n)
        for i in range(n - 1):
            for j in range(i + 1, n):
                if len(set(arr[i]).intersection(set(arr[j]))) > 0:
                    graph.addEdge(i, j)

        cc = graph.connectedComponents()
        print(len(cc) - 1)


if __name__ == "__main__":
    main()

# correct
