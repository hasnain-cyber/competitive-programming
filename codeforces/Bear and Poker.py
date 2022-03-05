def main():
    n = int(input())
    arr = list(map(int, input().split()))

    for i in range(n):
        new_value = arr[i]
        while new_value % 2 == 0:
            new_value //= 2
        while new_value % 3 == 0:
            new_value //= 3
        arr[i] = new_value

    flag = True
    check_element = arr[0]
    for i in range(1, n):
        if arr[i] != check_element:
            flag = False
            break

    print("YES" if flag else "NO")


if __name__ == "__main__":
    main()

# correct
