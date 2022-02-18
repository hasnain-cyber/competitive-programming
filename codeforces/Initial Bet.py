def main():
    arr = list(map(int, input().split()))

    total = sum(arr)
    b = total / 5
    if b.is_integer() and b >= 1:
        print(int(b))
    else:
        print(-1)


if __name__ == "__main__":
    main()

# correct
