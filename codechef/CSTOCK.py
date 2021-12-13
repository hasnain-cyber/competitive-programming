for i in range(int(input())):
    s, a, b, c = list(map(int, input().split()))
    finalPrice = s + s * c / 100

    if a <= finalPrice <= b:
        print('yes')
    else:
        print('no')

# correct
