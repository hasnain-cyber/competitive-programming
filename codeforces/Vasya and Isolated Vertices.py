import math


def main():
    n, m = map(int, input().split())

    min_free_nodes = max(0, n - 2 * m)

    if m == 0:
        bound_nodes = 0
    else:
        bound_nodes = math.floor((1 + math.sqrt(1 + 8 * m)) / 2)

    edges_used = bound_nodes * (bound_nodes - 1) // 2
    if m == edges_used:
        max_free_nodes = n - bound_nodes
    else:
        max_free_nodes = n - (bound_nodes + 1)

    print(min_free_nodes, max_free_nodes)


if __name__ == "__main__":
    main()

# correct
