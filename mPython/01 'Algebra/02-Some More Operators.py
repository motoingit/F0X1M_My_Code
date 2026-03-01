num1 = int(input('Num 1 : '))
num2 = int(input('Num 2 : '))

quotient = int(num1 // num2)  #for integer division use //
exponent = num1 ** num2       # for 2^4 (in Math) == 2**4 (in python) == 16
reminder = num1 % num2            # for reminder use % operator

print(f'Quotient (floor division) = {quotient}, Exponent = {exponent}, Reminder = {reminder}')