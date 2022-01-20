def main():
    n, q = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    kArr = [1]
    prev_value = 1
    temp_set = {arr[0]}
    for i in range(1, n):
        answer = kArr[-1]  # for previous calculations
        answer += 1  # for last element independent array
        answer += prev_value
        if (
            arr[i] not in temp_set
        ):  # for appending into the previous last element arrays
            answer += i
        if arr[i] not in temp_set:
            prev_value += i
        prev_value += 1
        temp_set.add(arr[i])
        kArr.append(answer)
    print(kArr)

    for _ in range(q):
        query = list(map(int, input().split()))
        query_type = query[0]
        if query_type == 1:
            x, y = query[1], query[2]
            arr[x - 1] = y
        else:
            k = query[1]
            print(kArr[k - 1])


if __name__ == "__main__":
    main()


# try with precomputation
# wrong answer or else tle
