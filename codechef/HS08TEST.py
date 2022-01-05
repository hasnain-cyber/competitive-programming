def main():
    transaction_amount, balance = list(map(float, input().split()))

    value = balance - transaction_amount - 0.5
    if transaction_amount % 5 == 0 and value >= 0:
        print(value)
    else:
        print(balance)


if __name__ == "__main__":
    main()


# correct
