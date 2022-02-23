from queue import Queue


def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    if k - 1 >= n:
        print(max(arr))
    else:
        queue = Queue(n)
        for i in range(n):
            queue.put(arr[i])

        current_player = queue.get()
        current_wins = 0
        while not queue.empty():
            next_player = queue.get()
            if current_player > next_player:
                current_wins += 1
                queue.put(next_player)
            else:
                queue.put(current_player)
                current_player = next_player
                current_wins = 1

            if current_wins == k:
                break

        print(current_player)


if __name__ == "__main__":
    main()

# correct
