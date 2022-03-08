def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        score1 = sum(arr)

        score2 = float("-inf")
        max_so_far = 0
        for i in range(n - 1):
            max_so_far += arr[i]
            score2 = max(score2, max_so_far)
            max_so_far = max(max_so_far, 0)

        max_so_far = 0
        for i in range(1, n):
            max_so_far += arr[i]
            score2 = max(score2, max_so_far)
            max_so_far = max(max_so_far, 0)

        print("YES" if score1 > score2 else "NO")


if __name__ == "__main__":
    main()

# correct
