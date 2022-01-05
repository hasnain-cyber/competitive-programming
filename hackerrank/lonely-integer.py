def main():
    n = int(input())
    arr = list(map(int, input().split()))

    ans = 0
    for element in arr:
        ans ^= element
    print(ans)


if __name__ == "__main__":
    main()

# correct
