def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    s0 = sum(arr)

    s1, s2 = 0, 0
    for i in range(n):
        s1 += s0 - s2
        s2 += arr[i]
        if i != n - 1:
            s1 += arr[i]
    print(s1)


if __name__ == "__main__":
    main()

# correct
