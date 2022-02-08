def main():
    n, m = list(map(int, input().split()))
    arr = []
    for _ in range(n):
        arr.append(input())

    mn_i, mx_i, mx_j, mn_j = n, -1, -1, m
    for i in range(n):
        for j in range(m):
            if arr[i][j] == "*":
                mn_i = min(mn_i, i)
                mx_i = max(mx_i, i)
                mn_j = min(mn_j, j)
                mx_j = max(mx_j, j)
    for i in range(mn_i, mx_i + 1):
        print(arr[i][mn_j : mx_j + 1])


if __name__ == "__main__":
    main()

# correct
