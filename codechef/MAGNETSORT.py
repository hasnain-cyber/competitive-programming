def solve():
    n = int(input())
    arr = list(map(int, input().split()))
    polarity_string = input()

    sorted_arr = sorted(arr)

    if arr == sorted_arr:
        return 0
    else:
        partition1_left, partition1_right = polarity_string.find(
            "N"
        ), polarity_string.rfind("S")
        partition2_left, partition2_right = polarity_string.find(
            "S"
        ), polarity_string.rfind("N")

        if partition1_left == -1 or partition2_left == -1:
            return -1

        wrong_flag = False
        wrong_arr = []
        for i in range(n):
            if arr[i] != sorted_arr[i]:
                if not (
                    partition1_left <= i <= partition1_right
                    or partition2_left <= i <= partition2_right
                ):
                    wrong_flag = True
                    break
                else:
                    wrong_arr.append(i)

        if wrong_flag:
            print(-1)
        else:
            counter1, counter2 = 0, 0
            for i in wrong_arr:
                if partition1_left <= i <= partition1_right:
                    counter1 += 1
                if partition2_left <= i <= partition2_right:
                    counter2 += 1

            if counter1 == len(wrong_arr) or counter2 == len(wrong_arr):
                return 1
            else:
                return 2


def main():
    for _ in range(int(input())):
        print(solve())


if __name__ == "__main__":
    main()

# correct
