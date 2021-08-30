def solve(currentPosition, grid, pathArr):
    if currentPosition == (n - 1, n - 1):
        return True


for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    gridArr = []
    coinsArr = []
    for i in range(n):
        gridArr.append([character for character in input()])
    for i in range(n):
        coinsArr.append(list(map(int, input().split())))
    solve((0, 0), gridArr, [])
