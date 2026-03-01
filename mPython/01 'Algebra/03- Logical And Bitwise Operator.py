num1 = int(input('Num 1 : '))
num2 = int(input('Num 2 : '))

# NOW we Are going to Discuss about Realtional oprator
# 1. Greater than (>)
# 2. Less than (<)
# 3. Greater than or equal to (>=)
# 4. Less than or equal to (<=)
# 5. Equal to (==)
# 6. Not equal to (!=)


            #! LOGICAL OPERATORS (Work with booleans)
# 1. Logical AND - Returns True if both are True
print(True and True)     # True
print(True and False)    # False
print(False and False)   # False

# 2. Logical OR - Returns True if at least one is True
print(True or False)     # True
print(False or False)    # False

# 3. Logical NOT - Reverses the boolean value
print(not True)          # False
print(not False)         # True

            #! BITWISE OPERATORS (Work with binary of integers)
# 4. Bitwise XOR (^) - 1 if bits are different
print(5 ^ 3)             # 0101 ^ 0011 = 0110 -> 6

# 5. Bitwise AND (&) - 1 only if both bits are 1
print(5 & 3)             # 0101 & 0011 = 0001 -> 1

# 6. Bitwise OR (|) - 1 if at least one bit is 1
print(5 | 3)             # 0101 | 0011 = 0111 -> 7

# 7. Bitwise NOT (~) - Inverts all bits (2's complement)
print(~5)                # ~0101 = -(0101 + 1) = -6

# ⚠️ Note: Python does not have built-in logical NAND, NOR, XNOR operators.
# But you can simulate them using logical combinations.

# Example of logical NAND (not AND)
print(not (True and True))   # False
