def main():
    for _ in range(int(input())):
        n = int(input())
        string = input()

        a, b, greater = "1", "1", "neither"

        for i in range(1, n):
            if string[i] == "2":
                if greater == "neither":
                    a += "1"
                    b += "1"
                elif greater == "a":
                    a += "0"
                    b += "2"
                else:
                    a += "2"
                    b += "0"
            elif string[i] == "1":
                if greater == "neither":
                    a += "1"
                    b += "0"
                    greater = "a"
                elif greater == "a":
                    a += "0"
                    b += "1"
                else:
                    a += "1"
                    b += "0"
            else:
                a += "0"
                b += "0"

        print(a)
        print(b)


if __name__ == "__main__":
    main()

# correct
