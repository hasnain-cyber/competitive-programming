def main():
    n = int(input())

    edges_dict = {}
    for _ in range(n - 1):
        u, v = map(int, input().split())
        if u not in edges_dict:
            edges_dict[u] = [v]
        else:
            edges_dict[u].append(v)

        if v not in edges_dict:
            edges_dict[v] = [u]
        else:
            edges_dict[v].append(u)

    colors_dict = {1: 0}

    bfs_set = {1}
    while len(bfs_set) > 0:
        temp_set = set()
        for node in bfs_set:
            for neighbor in edges_dict[node]:
                if neighbor not in colors_dict:
                    colors_dict[neighbor] = 1 - colors_dict[node]
                    temp_set.add(neighbor)
        bfs_set = temp_set

    zero_nodes = list(colors_dict.values()).count(0)
    one_nodes = n - zero_nodes
    possible_edges = zero_nodes * one_nodes

    print(possible_edges - (n - 1))


if __name__ == "__main__":
    main()

# correct
