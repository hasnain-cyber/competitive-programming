from queue import Queue


def main():
    n, m = map(int, input().split())

    counter = 0
    queue = Queue()
    queue.put(n)

    while m not in queue:
        test_values = []
        while not queue.empty():
            value = queue.get()
            test_values.append(value - 1)
            test_values.append(value * 2)

        for value in test_values:
            queue.put(value)

        counter += 1


if __name__ == "__main__":
    main()


# try a bfs
