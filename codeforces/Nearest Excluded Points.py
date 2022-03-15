def main():
    n = int(input())
    arr = [tuple(map(int, input().split())) for _ in range(n)]

    current_points = set(arr)
    for point in arr:
        new_point = None
        distance = 1
        while not new_point:
            for i in range(1, distance + 1):
                new_points_arr = [
                    (point[0] + i, point[1]),
                    (point[0] - i, point[1]),
                    (point[0], point[1] + i),
                    (point[0], point[1] - i),
                ]
                for temp_point in new_points_arr:
                    if temp_point not in current_points:
                        new_point = temp_point
                        break

            distance += 1

        print(*new_point)


if __name__ == "__main__":
    main()

# tle
