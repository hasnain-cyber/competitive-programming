def main():
    n = int(input())
    arr = list(map(int, input().split()))
    for element in arr:
        if element == 1:
            print('HARD')
            return
    print('EASY')


if __name__ == '__main__':
    main()

# correct
