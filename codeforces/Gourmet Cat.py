def main():
    a, b, c = map(int, input().split())
    k = min(a // 3, b // 2, c // 2)
    a -= 3 * k
    b -= 2 * k
    c -= 2 * k

    cost_arr = [0, 0, 1, 2, 0, 2, 1]
    answer_arr = [7 * k for _ in range(7)]
    for s in range(7):
        a_expended, b_expended, c_expended = 0, 0, 0
        for i in range(s, 7 + s):
            pointer = i % 7

            if cost_arr[pointer] == 0:
                a_expended += 1
                if a_expended > a:
                    a_expended -= 1
                    break
            elif cost_arr[pointer] == 1:
                b_expended += 1
                if b_expended > b:
                    b_expended -= 1
                    break
            else:
                c_expended += 1
                if c_expended > c:
                    c_expended -= 1
                    break

        answer_arr[s] += a_expended + b_expended + c_expended

    print(max(answer_arr))


if __name__ == "__main__":
    main()

# correct
