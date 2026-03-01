import datetime

# Get the current date and time
now = datetime.datetime.now()

# Extract components
current_date = now.date()
current_day = now.strftime("%A")  # Full weekday name
current_year = now.year
current_month = now.strftime("%B")  # Full month name
current_seconds = now.second

# Display the results
print("Current Date     :", current_date)
print("Day of the Week  :", current_day)
print("Year             :", current_year)
print("Month            :", current_month)
print("Current Seconds  :", current_seconds)
