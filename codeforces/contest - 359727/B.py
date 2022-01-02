def main():
    for _ in range(int(input())):
        n = int(input())
        k = n / 4
        if k >= 1 and k.is_integer():
            print('YES')
        else:
            print('NO')


if __name__ == '__main__':
    main()

# correct
