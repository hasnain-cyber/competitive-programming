def main():
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(lambda x: "{0:032b}".format(int(x)), input().split()))

        ans = ["0" for _ in range(32)]
        for i in range(32):
            counter = 0
            for element in arr:
                if element[i] == "1":
                    if counter == 0:
                        counter += 1
                    elif counter == 1:
                        ans[i] = "1"
                        break
        print(int("".join(ans), 2))


if __name__ == "__main__":
    main()

# correct
