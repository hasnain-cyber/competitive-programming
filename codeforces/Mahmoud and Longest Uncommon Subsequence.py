def main():
    a, b = input(), input()
    if a == b:
        print(-1)
    else:
        print(max(len(a), len(b)))


if __name__ == "__main__":
    main()

# correct
