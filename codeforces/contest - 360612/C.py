def main():
    for _ in range(int(input())):
        n, g, b = list(map(int, input().split()))

        required_good_highway = (n + 1) // 2
        k = required_good_highway // g
        rem = required_good_highway % g
        if rem > 0:
            remaining_bad_highway = k * b
        else:
            remaining_bad_highway = (k - 1) * b
        if remaining_bad_highway >= (n - (n + 1) // 2):
            answer = required_good_highway + remaining_bad_highway
        else:
            answer = n
        print(answer)


if __name__ == '__main__':
    main()

# correct
