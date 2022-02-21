import math


def main():
    s, t = input(), input()
    n = len(s)

    counter = 0
    for i in range(n):
        if s[i] != t[i]:
            counter += 1

    if counter % 2 == 1:
        print("impossible")
        return

    required_change = counter // 2
    temp_string = ""
    counter = 0
    for i in range(n):
        if s[i] == t[i] or counter >= required_change:
            temp_string += s[i]
        else:
            temp_string += t[i]
            counter += 1
    print(temp_string)


if __name__ == "__main__":
    main()

# correct
