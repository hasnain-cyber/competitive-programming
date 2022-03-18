import math


def main():
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(n)]

    if n == 1:
        print(1)
    else:
        a1_element_arr = arr[0]
        a5_element_arr = [temp_arr[-1] for temp_arr in arr]

        a1_a2 = a1_element_arr[1]
        a1_by_a2 = a1_element_arr[-1] / a5_element_arr[1]

        a1 = math.floor(math.sqrt(a1_a2 * a1_by_a2))

        answer_arr = [a1]
        for i in range(1, n):
            answer_arr.append(a1_element_arr[i] // a1)

        print(*answer_arr)


if __name__ == "__main__":
    main()

# correct
