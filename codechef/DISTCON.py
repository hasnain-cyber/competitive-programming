def main():
    d = int(input())

    if d % 2 == 0:
        k = d // 2
        print(0, k)
        print(0, -k)
        print(k, 0)
        print(-k, 0)
    else:
        print(-1)


if __name__ == "__main__":
    main()

# correct
