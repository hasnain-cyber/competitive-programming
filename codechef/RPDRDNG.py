for _ in range(int(input())):
    length = int(input())
    b = list(map(int, input().split()))
    a = list(sorted(list(set(b))))

    flag = True
    for i in range(length):
        if i == length - 1:
            if b.count(a[i]) == 1:
                continue
            else:
                flag = False
                break
        if i == (length - 1) // 2:
            if b.count(a[i]) == 3:
                continue
            else:
                flag = False
                break
        if not b.count(a[i]) == 2:
            flag = False
            break
    if flag:
        print(*a)
    else:
        print(-1)
