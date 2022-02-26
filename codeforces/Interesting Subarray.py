def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        found_value = None
        for i in range(n - 1):
            if abs(arr[i] - arr[i + 1]) >= 2:
                found_value = (i + 1, i + 2)
                break

        if found_value:
            print("YES")
            print(*found_value)
        else:
            print("NO")


if __name__ == "__main__":
    main()

# correct
