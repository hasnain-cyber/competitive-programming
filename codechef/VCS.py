def main():
    for _ in range(int(input())):
        n, m, k = list(map(int, input().split()))
        ignored_files = set(map(int, input().split()))
        tracked_files = set(map(int, input().split()))

        all_files = set(range(1, n + 1))
        unignored_files = all_files - ignored_files
        untracked_files = all_files - tracked_files

        print(
            len(ignored_files.intersection(tracked_files)),
            len(unignored_files.intersection(untracked_files)),
        )


if __name__ == "__main__":
    main()

# correct
