def main():
    n = int(input())
    arr = list(map(int, input().split()))

    answer_arr = [0]
    max_height = arr[n - 1]
    for i in range(n - 2, -1, -1):
        if arr[i] > max_height:
            answer_arr.append(0)
        else:
            answer_arr.append(max_height - arr[i] + 1)
        max_height = max(max_height, arr[i])

    print(*list(reversed(answer_arr)))


if __name__ == "__main__":
    main()

# correct
