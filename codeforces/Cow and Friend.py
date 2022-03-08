import math


def main():
    for _ in range(int(input())):
        n, x = map(int, input().split())
        arr = list(map(int, input().split()))

        if x in arr:
            print(1)
        else:
            print(max(2, math.ceil(x / max(arr))))


if __name__ == "__main__":
    main()

# correct
