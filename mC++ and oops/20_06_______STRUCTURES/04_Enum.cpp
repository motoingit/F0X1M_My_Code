#include <iostream>
#include <string>

// Enum declaration
enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

int main() {
    TrafficLight currentLight;
    std::string userInput;

    std::cout << "Enter a traffic light color (RED, YELLOW, GREEN): ";
    std::cin >> userInput; // Read the string safely

    if (userInput == "RED") {
        currentLight = RED;
    } else if (userInput == "YELLOW") {
        currentLight = YELLOW;
    } else if (userInput == "GREEN") {
        currentLight = GREEN;
    } else {
        std::cout << "Invalid input. Defaulting to RED." << std::endl;
        currentLight = RED;
    }

    // Now, you can safely use the enum variable
    switch (currentLight) {
        case RED:
            std::cout << "The light is Red. STOP." << std::endl;
            break;
        case YELLOW:
            std::cout << "The light is Yellow. PREPARE TO STOP." << std::endl;
            break;
        case GREEN:
            std::cout << "The light is Green. GO." << std::endl;
            break;
    }

    return 0;
}