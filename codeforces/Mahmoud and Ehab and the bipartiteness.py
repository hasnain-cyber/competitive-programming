from queue import Queue


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

    current_color = 1
    colors_array = [0 for _ in range(n)]
    visited = [False for _ in range(n)]

    stack = []
    stack.append(1)
    while len(stack) > 0:
        current_node = stack.pop()
        visited[current_node - 1] = True
        colors_array[current_node - 1] = current_color
        current_color = 1 - current_color

        for neighbor in edges_dict[current_node]:
            if not visited[neighbor - 1]:
                stack.append(neighbor)

    zero_nodes = colors_array.count(0)
    one_nodes = n - zero_nodes

    print(zero_nodes * one_nodes - n + 1)


if __name__ == "__main__":
    main()

# giving wrong answer in the second test case
