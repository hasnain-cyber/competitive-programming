def main():
    n = int(input())
    arr = list(map(int, input().split()))

    path = [arr[-1]]
    while path[-1] != 1:
        node = path[-1]
        path.append(arr[node - 2])
    print(*list(reversed(path)), n)


if __name__ == "__main__":
    main()

# correct
