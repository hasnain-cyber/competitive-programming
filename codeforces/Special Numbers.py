def main():
    for _ in range(int(input())):
        n, k = map(int, input().split())

        binary_k = "{0:b}".format(k)
        length = len(binary_k)

        answer = 0
        for i in range(length):
            answer += int(binary_k[length - i - 1]) * (n**i)

        print(answer % (10**9 + 7))


if __name__ == "__main__":
    main()

# correct
