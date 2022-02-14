def main():
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))

    counter = 0
    min_score = arr[0]
    for score in arr:
        if score <= 0:
            break
        if score == min_score:
            counter += 1
        else:
            if counter >= k:
                break
            else:
                min_score = score
                counter += 1
    print(counter)


if __name__ == "__main__":
    main()

# correct
