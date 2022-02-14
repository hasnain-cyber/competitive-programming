def main():
    arr = [[1, 1, 1] for _ in range(3)]
    modifcation_arr = [list(map(int, input().split())) for _ in range(3)]

    for i in range(3):
        for j in range(3):
            times = modifcation_arr[i][j] % 2
            if times == 1:
                arr[i][j] = 1 - arr[i][j]
                if i > 0:
                    arr[i - 1][j] = 1 - arr[i - 1][j]
                if i < 2:
                    arr[i + 1][j] = 1 - arr[i + 1][j]
                if j > 0:
                    arr[i][j - 1] = 1 - arr[i][j - 1]
                if j < 2:
                    arr[i][j + 1] = 1 - arr[i][j + 1]

    for element in arr:
        for element2 in element:
            print(element2, end="")
        print()


if __name__ == "__main__":
    main()

# correct
