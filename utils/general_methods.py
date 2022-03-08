# binary search


def binary_search(arr, x):
    l, r = 0, len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            r = mid - 1
        else:
            l = mid + 1
    return -1


def upper_bound_binary_search(arr, x):
    l, r = 0, len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] >= x:
            r = mid - 1
        else:
            l = mid + 1
    return l


def lower_bound_binary_search(arr, x):
    l, r = 0, len(arr) - 1
    while l <= r:
        mid = (l + r) // 2
        if arr[mid] <= x:
            l = mid + 1
        else:
            r = mid - 1
    return r


# subarrays


def subarrs(arr):
    return_arr = []
    for i in range(len(arr)):
        for j in range(i, len(arr)):
            sub_arr = arr[i : j + 1]
            return_arr.append(sub_arr)

    return return_arr


def max_subarr_sum(arr):
    total_max = float("-inf")
    max_so_far = 0
    for i in range(n - 1):
        max_so_far += arr[i]
        total_max = max(total_max, max_so_far)
        max_so_far = max(max_so_far, 0)

    return total_max


# graphs


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


# miscellaneous


def primes(n):
    # Returns  a list of primes < nu
    sieve = [True] * n
    for i in range(3, int(n**0.5) + 1, 2):
        if sieve[i]:
            sieve[i * i :: 2 * i] = [False] * ((n - i * i - 1) // (2 * i) + 1)
    return [2] + [i for i in range(3, n, 2) if sieve[i]]
