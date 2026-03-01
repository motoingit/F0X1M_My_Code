dividend = float(input('Dividend: '))
divisor = float(input('Divisor: '))


quotient = round(dividend / divisor, 5)  # Keep 5 decimal places
remainder = round(dividend - (divisor * quotient), 5)  # Round remainder too
print(f'{dividend} {divisor} {quotient} {remainder}')
