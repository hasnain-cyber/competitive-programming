def main():
    n, k = list(map(int, input().split()))
    password_arr = []
    for i in range(n):
        password_arr.append(input())
    real_password = input()

    total_time_best = 0
    total_time_worst = 0
    error_counter_best = 0
    error_counter_worst = 0
    equality_error_triggered = False
    for password in password_arr:
        if len(password) < len(real_password):
            total_time_best += 1
            error_counter_best += 1
            total_time_worst += 1
            error_counter_worst += 1

        elif len(password) == len(real_password):
            total_time_worst += 1
            error_counter_worst += 1

        if error_counter_best == k:
            total_time_best += 5
            error_counter_best = 0
        if error_counter_worst == k:
            total_time_worst += 5
            error_counter_worst = 0
            equality_error_triggered = True
    if equality_error_triggered and error_counter_worst == 0:
        total_time_worst -= 5
    print(total_time_best + 1, total_time_worst)


if __name__ == "__main__":
    main()

# correct
