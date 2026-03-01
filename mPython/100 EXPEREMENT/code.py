# Write a Python function that takes a company name as input and generates a custom alphanumeric code based on the first word of the company name. The code must follow a specific format: the first 4 characters consist of the alphabetic position (A=1 to Z=26) of the first and last letters of the first word (each as a 2-digit number). Next, append a symbol (@ if the sum of those 4 digits is even, # if odd). Then append the first word of the company name, with only the first character capitalized. After that, append a second symbol determined by the sum of the digits in a 4-digit segment — where the first 2 digits represent the length of the first word, and the last 2 digits represent half of that length (floor division). The second symbol is @ if the digit sum is even, otherwise #. Finally, append that 4-digit segment to complete the code. The resulting output is a structured string that uniquely represents the company’s identity based on its first word.

#<2-digit-char-code><Symbol1><FirstWord><Symbol2><Final4Digits>

def generate_custom_code(company_name):
    # Step 1: Extract and format first word
    first_word = company_name.strip().split()[0].capitalize()

    # Step 2: Get first and last characters and their alphabetic values
    first_char = first_word[0].lower()
    last_char = first_word[-1].lower()
    first_val = ord(first_char) - ord('a') + 1
    last_val = ord(last_char) - ord('a') + 1

    # Step 3: Build the 4-digit code from character values
    char_code = f"{first_val:02d}{last_val:02d}"  # Example: H + N → "0814"

    # Step 4: Symbol1 — Based on sum of digits in char_code
    sum_char_digits = sum(int(d) for d in char_code)
    symbol1 = '@' if sum_char_digits % 2 == 0 else '#'

    # Step 5: Final 4-digit block (length and half-length)
    len_first = len(first_word)
    half_len = len_first // 2
    final4digits = f"{len_first:02d}{half_len:02d}"

    # Step 6: Symbol2 — Based on sum of digits in final4digits
    sum_final_digits = sum(int(d) for d in final4digits)
    symbol2 = '@' if sum_final_digits % 2 == 0 else '#'

    # Step 7: Combine and return the final code
    custom_code = f"{char_code}{symbol1}{first_word}{symbol2}{final4digits}"
    return custom_code


# 🔁 Example usage
if __name__ == "__main__":
    company = input("Enter the company name: ")
    result = generate_custom_code(company)
    print("Generated Code:", result)
