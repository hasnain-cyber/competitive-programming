def main():
    n, m, k = map(int, input().split())

    paths_dict = {}
    for _ in range(m):
        u, v, x = map(int, input().split())

        if u in paths_dict:
            paths_dict[u].append((v, x))
        else:
            paths_dict[u] = [(v, x)]

        if v in paths_dict:
            paths_dict[v].append((u, x))
        else:
            paths_dict[v] = [(u, x)]

    if k > 0:
        bakeries = set(map(int, input().split()))
    else:
        bakeries = set()

    min_length = float("inf")
    for bakery in bakeries:
        if bakery in paths_dict:
            for adjacent_city in paths_dict[bakery]:
                if not adjacent_city[0] in bakeries:
                    min_length = min(min_length, adjacent_city[1])

    print(min_length if min_length != float("inf") else -1)


if __name__ == "__main__":
    main()

# correct
