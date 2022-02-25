def main():
    for _ in range(int(input())):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))

        odd_indices = [(i + 1) for i in range(n) if arr[i] % 2 == 1]

        if len(odd_indices) >= k and (len(odd_indices) - k) % 2 == 0:
            print("YES")
            print(*odd_indices[: k - 1], n)
        else:
            print("NO")


if __name__ == "__main__":
    main()

# correct
