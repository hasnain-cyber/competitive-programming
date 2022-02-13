def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    print(*arr)


if __name__ == "__main__":
    main()

# correct
