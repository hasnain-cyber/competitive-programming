def main():
    for _ in range(int(input())):
        n, m, k = map(int, input().split())
        arr = list(map(int, input().split()))

        counter = m
        flag = True
        for i in range(n - 1):
            if arr[i + 1] >= arr[i]:
                difference = arr[i + 1] - arr[i]
                if difference >= k:
                    counter -= difference - k
                else:
                    counter += min(k - difference, arr[i])
            else:
                counter += min(arr[i] - arr[i + 1] + k, arr[i])

            if counter < 0:
                flag = False
                break

        print("YES" if flag else "NO")


if __name__ == "__main__":
    main()

# correct
