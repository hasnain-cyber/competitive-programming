def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        longest_prefix_length = 0
        for i in range(n):
            if arr[i] > i - 1:
                longest_prefix_length += 1
            else:
                break

        longest_suffix_length = 0
        for i in range(n - 1, -1, -1):
            if arr[i] >= n - i - 1:
                longest_suffix_length += 1
            else:
                break

        print("YES" if longest_prefix_length + longest_suffix_length > n else "NO")


if __name__ == "__main__":
    main()

# correct
