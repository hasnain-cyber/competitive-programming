def main():
    n, m = list(map(int, input().split()))
    arr = [input() for _ in range(n)]

    top, bottom, left, right = 0, n - 1, 0, m - 1
    for i in range(n):
        for j in range(m):
            if arr[i][j] == "B":
                if j > left:
                    left = j
                if j < right:
                    right = j
                if i > top:
                    top = i
                if i < bottom:
                    bottom = i
    print((bottom + top) // 2 + 1, (right + left) // 2 + 1)


if __name__ == "__main__":
    main()

# correct
