def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        max_medals = n // 2
        g, s, b = 0, 0, 0

        current_max = arr[0]
        mode = 0
        counter = 0
        for score in arr:
            if score == current_max:
                counter += 1
            else:
                if mode == 0:
                    g += counter
                elif mode == 1:
                    s += counter
                elif mode == 2:
                    b += counter

                counter = 0
                mode += 1
                current_max = score
            if mode == 3:
                break

        print(g, s, b)


if __name__ == "__main__":
    main()

# could not solve
