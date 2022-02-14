def main():
    n = int(input())
    arr = list(map(int, input().split()))

    stack = []
    for i in range(n):
        element = arr[n - i - 1]
        if not element in stack:
            stack.append(element)

    print(len(stack))
    while len(stack) > 0:
        print(stack.pop(), end=" ")


if __name__ == "__main__":
    main()

# correct
