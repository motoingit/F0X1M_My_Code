def check_day(day):
    match day:
        case 1:
            print("Monday")
        case 2:
            print("Tuesday")
        case 3:
            print("Wednesday")
        case _:  # default case
            print("Unknown day")

def describe(value): #new
    match value:
        case 0:
            return "zero"
        case 1 | 2 | 3:  # multiple values
            return "small number"
        case int() if value > 10:  # with condition
            return "large number"
        case str():
            return "it's a string"
        case _:
            return "something else"
        
def check_day(day): #old
    switcher = {
        1: "Monday",
        2: "Tuesday",
        3: "Wednesday",
    }
    print(switcher.get(day, "Unknown day"))

