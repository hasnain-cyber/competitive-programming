def main():
    n, a, b, c = int(input()), int(input()), int(input()), int(input())

    current_home = "rabbit"
    counter = 0
    total_distance = 0
    while True:
        counter += 1
        if counter >= n:
            break
        if current_home == "rabbit":
            if a > b:
                current_home = "eeyore"
                total_distance += b
            else:
                current_home = "owl"
                total_distance += a
        elif current_home == "owl":
            if c > a:
                current_home = "rabbit"
                total_distance += a
            else:
                current_home = "eeyore"
                total_distance += c
        else:
            if b > c:
                current_home = "owl"
                total_distance += c
            else:
                current_home = "rabbit"
                total_distance += b

    print(total_distance)


if __name__ == "__main__":
    main()

# correct
