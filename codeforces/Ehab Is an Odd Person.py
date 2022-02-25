def main():
    n = int(input())
    arr = list(map(int, input().split()))

    parity_0, parity_1 = False, False
    for element in arr:
        if element % 2 == 0:
            parity_0 = True
        else:
            parity_1 = True
        
        if parity_0 and parity_1:
            break

    if parity_0 and parity_1:
        print(*list(sorted(arr)))
    else:
        print(*arr)


if __name__ == "__main__":
    main()

# correct
