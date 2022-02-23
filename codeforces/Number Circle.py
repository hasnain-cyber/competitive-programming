def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    if arr[-1] >= arr[-2] + arr[-3]:
        print("NO")
        return

    print("YES")
    temp_arr = [arr[n - 1]]
    for i in range(n - 3, -1, -1):
        temp_arr.append(arr[i])
    temp_arr.append(arr[n - 2])
    print(*temp_arr)


if __name__ == "__main__":
    main()

# correct
