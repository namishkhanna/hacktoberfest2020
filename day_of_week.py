import datetime


def day_of_week():
    date = input("Enter a date in YYYY-MM-DD format: ")
    year, month, day = map(int, date.split('-'))
    date1 = datetime.date(year, month, day)
    if date1.weekday() == 0:
        return print('Monday')
    if date1.weekday() == 1:
        return print('Tuesday')
    if date1.weekday() == 2:
        return print('Wednesday')
    if date1.weekday() == 3:
        return print('Thursday')
    if date1.weekday() == 4:
        return print('Friday')
    if date1.weekday() == 5:
        return print('Saturday')
    if date1.weekday() == 6:
        return print('Sunday')

day_of_week()
