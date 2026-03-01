from abc import ABC, abstractmethod

# Abstract class
class Vehicle(ABC):
    @abstractmethod #? The @ symbol in Python is called a decorator.
    def start_engine(self):
        pass   # Abstract method — no implementation

    def fuel_type(self):
        return "Petrol or Diesel"   # Concrete method

# Child class implementing the abstract method
class Car(Vehicle):
    def start_engine(self):
        return "Car engine started with key ignition"

# Another subclass
class Bike(Vehicle):
    def start_engine(self):
        return "Bike engine started with self-start"

# Usage
car = Car()
bike = Bike()
# xvehical = Vehicle() #! this is should not done
print(car.start_engine())   # Output: Car engine started with key ignition
print(bike.start_engine())  # Output: Bike engine started with self-start
print(car.fuel_type())      # Output: Petrol or Diesel
