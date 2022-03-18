def main():
    k = int(input())

    sum_arr = []
    for nSequence in range(k):
        n = int(input())
        temp_arr = list(map(int, input().split()))
        s = sum(temp_arr)

        for i in range(n):
            sum_arr.append((s - temp_arr[i], nSequence + 1, i + 1))
    sum_arr.sort(key=lambda x: x[0])

    ans = None
    for i in range(len(sum_arr) - 1):
        if sum_arr[i][0] == sum_arr[i + 1][0] and sum_arr[i][1] != sum_arr[i + 1][1]:
            ans = (
                (sum_arr[i][1], sum_arr[i][2]),
                (sum_arr[i + 1][1], sum_arr[i + 1][2]),
            )
            break

    if ans:
        print("YES")
        for element in ans:
            print(*element)
    else:
        print("NO")


if __name__ == "__main__":
    main()

# correct
