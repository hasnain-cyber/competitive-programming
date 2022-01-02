def main():
    for _ in range(int(input())):
        n, m, x, y = list(map(int, input().split()))
        arr = []
        for i in range(n):
            arr.append(input())

        total_price = 0
        for i in range(n):
            j = 0
            while j < m:
                if arr[i][j] == '.':
                    if not j == m - 1 and arr[i][j + 1] == '.':
                        if y < 2 * x:
                            total_price += y
                            j += 1
                        else:
                            total_price += x
                    else:
                        total_price += x
                j += 1
        print(total_price)


if __name__ == '__main__':
    main()

# correct
