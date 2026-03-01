import random
import string

def generate_password(length):
    """
    Generates a random password of a specified length.

    The password will contain a mix of uppercase letters, lowercase letters,
    digits, and special characters.

    Args:
        length (int): The desired length of the password.

    Returns:
        str: The generated password.
    """
    if not 4 <= length <= 12:
        return "Error: Password length must be between 4 and 12 characters."

    # Define the character sets to use for the password
    characters = string.ascii_letters + string.digits + string.punctuation
    
    # Generate the password by randomly selecting characters
    password = ''.join(random.choice(characters) for _ in range(length))
    
    return password

if __name__ == "__main__":
    try:
        # Prompt the user to enter the desired password length
        password_length_str = input("Enter the desired password length (4-12 characters): ")
        
        # Convert the input to an integer
        password_length = int(password_length_str)
        
        # Generate the password
        new_password = generate_password(password_length)
        
        # Print the generated password
        print(f"Generated Password: {new_password}")

    except ValueError:
        print("Invalid input. Please enter a valid number.")
