for _ in range(int(input())):
    n = int(input())
    if n % 2 == 0:
        for i in range(n):
            for j in range(n):
                print(-1, end=' ')
            print()
    else:
        for i in range(n):
            for j in range(n):
                if j == i:
                    print(-1, end=' ')
                else:
                    print(1, end=' ')
            print()

# correct
