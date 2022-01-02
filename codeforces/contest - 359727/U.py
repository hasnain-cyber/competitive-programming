import math


def main():
    for _ in range(int(input())):
        n, k = list(map(int, input().split()))

        floor = math.ceil((math.sqrt(8 * k + 1) - 1) / 2)
        temp = floor * (floor - 1) // 2
        if temp == 0:
            rem = 1
        else:
            rem = k - (k // temp) * temp
        answer = 'a' * (n - floor - 1) + 'b' + 'a' * (floor - rem) + 'b' + 'a' * (rem - 1)
        print(answer)


if __name__ == '__main__':
    main()

# wrong answer
