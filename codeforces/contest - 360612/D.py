import math


def check_log_int(x, k):
    return math.log(x, k).is_integer()


def main():
    for _ in range(int(input())):
        n, k = list(map(int, input().split()))
        a = list(map(int, input().split()))
        a.sort()

        current_index, current_step = 0, 0
        break_flag = False
        while current_index < n:
            if a[current_index] == 0:
                current_index += 1
            elif a[current_index] - k ** current_step == 0:
                current_index += 1
                current_step += 1
            elif a[current_index] - k ** current_step < 0:
                break_flag = True
                break
            else:
                a[current_index] %= k ** current_step
                current_step += 1

        if break_flag:
            print('NO')
        else:
            print('YES')


if __name__ == '__main__':
    main()

# could not solve
