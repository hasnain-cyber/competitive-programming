def main():
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    portal_arr = []
    for i in range(1, n):
        portal_arr.append(i + arr[i - 1])

    current_positon = 1
    while current_positon != n:
        new_position = portal_arr[current_positon - 1]
        if new_position == k:
            print("YES")
            return
        current_positon = new_position
    print("NO")


if __name__ == "__main__":
    main()

# correct
