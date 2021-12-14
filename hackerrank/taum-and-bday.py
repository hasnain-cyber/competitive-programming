for _ in range(int(input())):
    b, w = list(map(int, input().split()))
    bc, wc, z = list(map(int, input().split()))
    bc = min(bc, wc + z)
    wc = min(wc, bc + z)
    print(bc * b + wc * w)

# correct
