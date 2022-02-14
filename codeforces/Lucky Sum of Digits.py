def main():
    n = int(input())

    for i in range(n // 7, -1, -1):
        if (n - i * 7) % 4 == 0:
            print("4" * ((n - i * 7) // 4) + "7" * i)
            return
    print(-1)


if __name__ == "__main__":
    main()

# correct
