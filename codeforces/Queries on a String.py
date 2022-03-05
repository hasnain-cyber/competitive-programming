def main():
    arr = [character for character in input()]
    nQueries = int(input())
    queries = [input().split() for _ in range(nQueries)]

    for query in queries:
        l, r, k = int(query[0]), int(query[1]), int(query[2])

        temp_arr = [0 for _ in range(r - l + 1)]


if __name__ == "__main__":
    main()
