#include <iostream>
#include <vector>
#include "car.h"

void printOptions(const std::vector<std::string>& options) {
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << i + 1 << ". " << options[i] << std::endl;
    }
}

int main() {
    std::vector<Car> cars = {
        Car("Toyota", "Camry", 25000, "Red", {"GPS", "Sunroof"}, "V6", "Aluminum"),
        Car("Honda", "Accord", 28000, "Blue", {"GPS", "Leather Seats"}, "4-cylinder", "Steel"),
        Car("Ford", "Mustang", 35000, "Yellow", {"Racing Stripes", "Sport Suspension"}, "V8", "Carbon Fiber")
    };

    char continueChoice = 'y';
    while (continueChoice == 'y' || continueChoice == 'Y') {
        std::cout << "Available cars:" << std::endl;
        for (int i = 0; i < cars.size(); i++) {
            std::cout << "- " << i + 1 << ". " << cars[i].getModel() << " by " << cars[i].getMake() << std::endl;
        }
        std::cout << std::endl;

        int carIndex;
        while (true) {
            std::cout << "Select a car by number: ";
            std::cin >> carIndex;
            std::cout << std::endl;

            if (carIndex >= 1 && carIndex <= cars.size()) {
                break;
            } else {
                std::cout << "Invalid selection. Please try again." << std::endl;
            }
        }

        Car selectedCar = cars[carIndex - 1];
        std::cout << "Selected Car Details:" << std::endl;
        selectedCar.printCarAscii();

        
        std::cout << "Select a color: " << std::endl;
        printOptions(selectedCar.getAvailableColors());
        int colorIndex;
        while (true) {
            std::cout << "Enter the color number: ";
            std::cin >> colorIndex;
            std::cout << std::endl;

            if (colorIndex >= 1 && colorIndex <= selectedCar.getAvailableColors().size()) {
                break;
            } else {
                std::cout << "Invalid selection. Please try again." << std::endl;
            }
        }
        std::string color = selectedCar.getAvailableColors()[colorIndex - 1];
        selectedCar.setColor(color);

        
        std::cout << "Select a rim style: " << std::endl;
        printOptions(selectedCar.getAvailableRimStyles());
        int rimIndex;
        while (true) {
            std::cout << "Enter the rim style number: ";
            std::cin >> rimIndex;
            std::cout << std::endl;

            if (rimIndex >= 1 && rimIndex <= selectedCar.getAvailableRimStyles().size()) {
                break;
            } else {
                std::cout << "Invalid selection. Please try again." << std::endl;
            }
        }
        std::string rimStyle = selectedCar.getAvailableRimStyles()[rimIndex - 1];
        selectedCar.setRimStyle(rimStyle);

        
        std::string frontColor;
        std::cout << "Enter the color for the front part: ";
        std::cin >> frontColor;
        selectedCar.setFrontColor(frontColor);

        
        std::string rearColor;
        std::cout << "Enter the color for the rear part: ";
        std::cin >> rearColor;
        selectedCar.setRearColor(rearColor);

        
        while (true) {
            selectedCar.listAvailableAccessories();
            std::cout << "Add an accessory (Y/N): ";
            std::string choice;
            std::cin >> choice;
            std::cout << std::endl;

            if (choice == "Y" || choice == "y") {
                std::cout << "Enter the accessory: ";
                std::string accessory;
                std::cin >> accessory;
                std::cout << std::endl;
                selectedCar.addAccessory(accessory);
                std::cout << "Updated Car Details:" << std::endl;
                selectedCar.printCarAscii();
            } else if (choice == "N" || choice == "n") {
                break;
            } else {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }

        
        std::cout << "Select an engine type: " << std::endl;
        printOptions(selectedCar.getAvailableEngineTypes());
        int engineIndex;
        while (true) {
            std::cout << "Enter the engine type number: ";
            std::cin >> engineIndex;
            std::cout << std::endl;

            if (engineIndex >= 1 && engineIndex <= selectedCar.getAvailableEngineTypes().size()) {
                selectedCar.printCarAscii();
                break;
            } else {
                std::cout << "Invalid selection. Please try again." << std::endl;
            }
        }
        std::string engineType = selectedCar.getAvailableEngineTypes()[engineIndex - 1];
        selectedCar.setEngineType(engineType);
        selectedCar.printCarAscii();

        
        std::cout << "Select a material: " << std::endl;
        printOptions(selectedCar.getAvailableMaterials());
        int materialIndex;
        while (true) {
            std::cout << "Enter the material number: ";
            std::cin >> materialIndex;
            std::cout << std::endl;

            if (materialIndex >= 1 && materialIndex <= selectedCar.getAvailableMaterials().size()) {
                selectedCar.printCarAscii();
                break;
            } else {
                std::cout << "Invalid selection. Please try again." << std::endl;
            }
        }
        std::string material = selectedCar.getAvailableMaterials()[materialIndex - 1];
        selectedCar.setMaterial(material);

        std::cout << "Updated Car Details:" << std::endl;
        selectedCar.printCarAscii();

        std::cout << "Do you want to select a different car model? (y/n): ";
        std::cin >> continueChoice;
        std::cout << std::endl;
    }

    return 0;
}