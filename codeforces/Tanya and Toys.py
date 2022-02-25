def main():
    n, k = map(int, input().split())
    arr = set(map(int, input().split()))

    i = 1
    s = 0
    answer_arr = []
    while True:
        if i not in arr:
            if s + i > k:
                break
            else:
                s += i
                answer_arr.append(i)
                i += 1
        else:
            i += 1
    print(len(answer_arr))
    print(*answer_arr)


if __name__ == "__main__":
    main()

# correct
