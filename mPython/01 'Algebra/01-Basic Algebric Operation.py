dividend = int(input('Dividend : '))
divisor = int(input('Divisor : '))

quotient = int(dividend / divisor)                      #for integer division use //     insted of       / , int()
reminder = dividend - (divisor * quotient) 

print(f'Dividend = {dividend}, Divisor = {divisor}, Quotient = {quotient}, Reminder = {reminder}')