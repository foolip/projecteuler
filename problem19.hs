isLeapYear year = year `mod` 4 == 0 && (year `mod` 100 /= 0 || year `mod` 400 == 0)

daysInMonth (year, 1) = 31
daysInMonth (year, 2) = if isLeapYear year then 29 else 28
daysInMonth (year, 3) = 31
daysInMonth (year, 4) = 30
daysInMonth (year, 5) = 31
daysInMonth (year, 6) = 30
daysInMonth (year, 7) = 31
daysInMonth (year, 8) = 31
daysInMonth (year, 9) = 30
daysInMonth (year, 10) = 31
daysInMonth (year, 11) = 30
daysInMonth (year, 12) = 31

dateAfter (year, month, day) =
  if day == daysInMonth (year, month)
  then if month == 12
       then (year + 1, 1, 1)
       else (year, month + 1, 1)
  else (year, month, day + 1)

dateRange fromDate@(fromYear, fromMonth, fromDay) toDate@(toYear, toMonth, toDay)
  | fromDate == toDate = [fromDate]
  | otherwise = fromDate : dateRange (dateAfter fromDate) toDate

weekdays = ["mon", "tue", "wed", "thu", "fri", "sat", "sun"]

datesWithWeekdays = zip (cycle weekdays) $ dateRange (1900, 1, 1) (2000, 12, 31)

answer = length $ filter (\(weekday, (year, month, day)) -> weekday == "sun" && day == 1 && year >= 1901) datesWithWeekdays

main = print answer
