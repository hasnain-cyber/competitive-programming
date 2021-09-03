from itertools import combinations


def checkTriangle(triangleTuple):
    s1 = triangleTuple[0]
    s2 = triangleTuple[1]
    s3 = triangleTuple[2]

    if s1 + s2 > s3 and s2 + s3 > s1 and s3 + s1 > s2:
        return True
    return False


length = int(input())
arr = list(map(int, input().split()))

combinationsArr = set(combinations(arr, 3))
finalTriangleArr = []
maxPerimeter = 0
for testTriangle in combinationsArr:
    if checkTriangle(testTriangle):
        perimeter = sum(testTriangle)
        if perimeter > maxPerimeter:
            finalTriangleArr = [testTriangle]
            maxPerimeter = perimeter
        elif perimeter == maxPerimeter:
            finalTriangleArr.append(testTriangle)

l = len(finalTriangleArr)
if l == 0:
    print(-1)
else:
    print(*sorted(finalTriangleArr[0]))

# correct
