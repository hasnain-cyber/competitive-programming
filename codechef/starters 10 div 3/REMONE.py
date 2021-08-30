for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    A.sort()
    B.sort()

    x1 = B[0] - A[1]
    x0 = B[0] - A[0]
    if x1 == x0:
        print(x0)
    else:
        flag = True
        for i in range(1, n - 1):
            if not A[i + 1] == B[i] - x1:
                flag = False
                break
        if not flag:
            print(x0)
        else:
            if x1 <= 0:
                print(x0)
            else:
                print(x1)

# correct
