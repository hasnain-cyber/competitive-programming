def check_valadity(s1, s2, length, k):
    for i in range(length):
        if s1[i] != s2[i]:
            k -= 1
            if k < 0:
                return False
    return True


def main():
    n, m, k = map(int, input().split())

    arr = []
    for _ in range(m + 1):
        binary_num = "{0:b}".format(int(input())).zfill(n)
        arr.append(binary_num)

    temp = arr[m]
    counter = 0
    for i in range(0, m):
        if check_valadity(arr[i], temp, n, k):
            counter += 1

    print(counter)


if __name__ == "__main__":
    main()

# correct
