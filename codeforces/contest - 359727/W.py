def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))

        if a == list(sorted(a)):
            print('YES')
        else:
            flag0 = False
            flag1 = False
            for element in b:
                if element == 0:
                    flag0 = True
                elif element == 1:
                    flag1 = True
            if flag0 and flag1:
                print('YES')
            else:
                print('NO')


if __name__ == '__main__':
    main()

# correct
