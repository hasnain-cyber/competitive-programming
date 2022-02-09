from ctypes import pointer


def main():
    string = input()

    if len(string) >= 3:
        pointer = 0
        while pointer < len(string):
            if string[pointer] == "1":
                if pointer + 1 == len(string):
                    break
                if string[pointer + 1] == "4":
                    if pointer + 2 == len(string):
                        break
                    if string[pointer + 2] == "4":
                        pointer += 3
                    else:
                        pointer += 2
                else:
                    pointer += 1
            else:
                print("NO")
                return
        print("YES")
    else:
        if string in ["1", "11", "14"]:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()

# correct
