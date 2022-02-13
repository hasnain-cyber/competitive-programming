def main():
    n, m = list(map(int, input().split()))
    arr = [input() for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if arr[i][j] == "S":
                if i != 0 and arr[i - 1][j] == "W":
                    print("No")
                    return
                elif i != n - 1 and arr[i + 1][j] == "W":
                    print("No")
                    return
                elif j != 0 and arr[i][j - 1] == "W":
                    print("No")
                    return
                elif j != m - 1 and arr[i][j + 1] == "W":
                    print("No")
                    return

    print("Yes")
    for element in arr:
        print_element = element.replace(".", "D")
        print(print_element)


if __name__ == "__main__":
    main()

# correct
