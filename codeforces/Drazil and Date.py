def main():
    a, b, s = list(map(int, input().split()))

    extra_steps = s - (abs(a) + abs(b))
    if extra_steps < 0:
        print("No")
    elif extra_steps % 2 == 0:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()

# correct
