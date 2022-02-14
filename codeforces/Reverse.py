def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        for i in range(n):
            if i + 1 == arr[i]:
                continue
            else:
                index = arr.index(i + 1)
                arr = arr[:i] + list(reversed(arr[i : index + 1])) + arr[index + 1 :]
                break
        print(*arr)


if __name__ == "__main__":
    main()

# correct
