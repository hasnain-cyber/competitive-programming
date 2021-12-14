for _ in range(int(input())):
    a, b, p, q = list(map(int, input().split()))
    alpha, beta = p / a, q / b
    if (alpha.is_integer() and beta.is_integer()) and (alpha == beta or abs(alpha - beta) == 1):
        print('yes')
    else:
        print('no')

# correct answer
