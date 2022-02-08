def main():
    n = int(input())
    arr = list(map(int, input().split()))

    mx = max(arr)
    mx_index = arr.index(mx)
    print(mx_index + 1, list(sorted(arr))[-2])


if __name__ == "__main__":
    main()

# correct
