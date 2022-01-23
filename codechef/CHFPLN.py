def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        points_dict = dict()
        for point in arr:
            if point in points_dict:
                points_dict[point] += 1
            else:
                points_dict[point] = 1

        counter = 0
        for key, value in points_dict.items():
            counter += min(key - 1, value)
        print(counter)


if __name__ == "__main__":
    main()

# correct
