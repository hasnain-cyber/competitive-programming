actualDay, actualMonth, actualYear = list(map(int, input().split()))
expectedDay, expectedMonth, expectedYear = list(map(int, input().split()))

yearDifference = actualYear - expectedYear
monthDifference = actualMonth - expectedMonth
dayDifference = actualDay - expectedDay
if yearDifference > 0:
    print(10000)
elif yearDifference < 0:
    print(0)
elif monthDifference > 0:
    print(500 * monthDifference)
elif monthDifference < 0:
    print(0)
elif dayDifference > 0:
    print(15 * dayDifference)
else:
    print(0)

# correct
