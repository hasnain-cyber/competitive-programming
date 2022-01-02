import math


def main():
    for _ in range(int(input())):
        x = int(input())
        a = math.ceil((x - 1) ** (1 / 3))
        b = 1
        flag = False
        while not flag and b <= a:
            s = a ** 3 + b ** 3
            if s == x:
                flag = True
            elif s > x:
                a -= 1
            else:
                b += 1
        if flag:
            print('YES')
        else:
            print('NO')


if __name__ == '__main__':
    main()

# correct
