def main():
    a, b = list(map(int, input().split()))

    answer_arr = []
    while a != b and b >= a:
        if b % 10 == 1:
            b //= 10
            answer_arr.append(1)
        elif b % 2 == 0:
            b //= 2
            answer_arr.append(0)
        else:
            break

    if a == b:
        print("YES")
        print(len(answer_arr) + 1)
        temp_arr = [a]
        for operation in reversed(answer_arr):
            if operation == 0:
                temp_arr.append(temp_arr[-1] * 2)
            else:
                temp_arr.append(10 * temp_arr[-1] + 1)
        print(*temp_arr)
    else:
        print("NO")


if __name__ == "__main__":
    main()

# correct
