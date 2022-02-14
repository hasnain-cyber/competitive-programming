# the recursion limit causes problem in python, and in pypy too, so increase it

from sys import setrecursionlimit

setrecursionlimit(20000000)


def dfs(arr, visited, i, depth):
    visited[i] = True
    if len(arr[i]) == 0:
        return depth
    else:
        mx = 1
        for element in arr[i]:
            check_value = dfs(arr, visited, element, depth + 1)
            mx = max(mx, check_value)
        return mx


def main():
    n = int(input())
    arr = [[] for _ in range(n)]
    visited = [False for _ in range(n)]

    for i in range(n):
        manager = int(input())
        if not manager == -1:
            arr[manager - 1].append(i)

    mx = 1
    for i in range(n):
        if not visited[i] and len(arr[i]) > 0:
            check_value = dfs(arr, visited, i, 1)
            mx = max(mx, check_value)
            visited[i] = True

    print(mx)


if __name__ == "__main__":
    main()

# correct
