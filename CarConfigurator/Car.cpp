#include "car.h"

Car::Car(const std::string& make, const std::string& model, double price, const std::string& color,
         const std::vector<std::string>& accessories, const std::string& engineType, const std::string& material)
    : make(make), model(model), price(price), color(color), accessories(accessories), engineType(engineType),
      material(material), enginePrice_(0.0), rimPrice_(0.0), materialPrice_(0.0), accessoryPrice_(0.0), totalPrice_(0.0) {
    availableRimStyles = {"Standard", "Alloy", "Sport"};
    calculateOptionPrices();
    calculateTotalPrice();
}

std::vector<std::string> Car::getAvailableRimStyles() const {
    return availableRimStyles;
}

void Car::setRimStyle(const std::string& rimStyle) {
    this->rimStyle = rimStyle;
    calculateOptionPrices();
    calculateTotalPrice();
}

std::string Car::getMake() const {
    return make;
}

std::string Car::getModel() const {
    return model;
}

int Car::getPrice() const {
    return static_cast<int>(totalPrice_);
}

std::string Car::getColor() const {
    return color;
}

std::vector<std::string> Car::getAccessories() const {
    return accessories;
}

std::string Car::getEngineType() const {
    return engineType;
}

std::string Car::getMaterial() const {
    return material;
}

std::string Car::getRimStyle() const {
    return rimStyle;
}

std::string Car::getFrontColor() const {
    return frontColor;
}

std::string Car::getRearColor() const {
    return rearColor;
}

void Car::setMake(const std::string& make) {
    this->make = make;
}

void Car::setModel(const std::string& model) {
    this->model = model;
}

void Car::setPrice(double price) {
    this->price = price;
    calculateTotalPrice();
}

void Car::setColor(const std::string& color) {
    this->color = color;
    calculateTotalPrice();
}

void Car::addAccessory(const std::string& accessory) {
    accessories.push_back(accessory);
    calculateOptionPrices();
    calculateTotalPrice();
}

void Car::removeAccessory(const std::string& accessory) {
    for (auto it = accessories.begin(); it != accessories.end(); ++it) {
        if (*it == accessory) {
            accessories.erase(it);
            calculateOptionPrices();
            calculateTotalPrice();
            break;
        }
    }
}

void Car::listAvailableAccessories() const {
    std::cout << "Available Accessories: " << std::endl;
    for (const auto& accessory : accessories) {
        std::cout << "- " << accessory << " ($500)" << std::endl;
    }
    std::cout << std::endl;
}

void Car::listAvailableTrims() const {
    std::cout << "Available Trims: ";
    for (const auto& trim : availableTrims) {
        std::cout << trim << " ";
    }
    std::cout << std::endl;
}

void Car::setEngineType(const std::string& engineType) {
    this->engineType = engineType;
    calculateOptionPrices();
    calculateTotalPrice();
}

void Car::setMaterial(const std::string& material) {
    this->material = material;
    calculateOptionPrices();
    calculateTotalPrice();
}


void Car::setFrontColor(const std::string& frontColor) {
    this->frontColor = frontColor;
    calculateOptionPrices();
    calculateTotalPrice();
}

void Car::setRearColor(const std::string& rearColor) {
    this->rearColor = rearColor;
    calculateOptionPrices();
    calculateTotalPrice();
}

std::vector<std::string> Car::getAvailableColors() const {
    std::vector<std::string> availableColors = {"Red", "Blue", "Green", "White", "Black"};
    return availableColors;
}

std::vector<std::string> Car::getAvailableEngineTypes() const {
    std::vector<std::string> availableEngineTypes = {"Basic", "Economic", "Sport"};
    return availableEngineTypes;
}

std::vector<std::string> Car::getAvailableMaterials() const {
    std::vector<std::string> availableMaterials = {"Cloth", "Leather", "Synthetic"};
    return availableMaterials;
}


void Car::calculateOptionPrices() {
    if (engineType == "Basic")
        enginePrice_ = 1000.0;
    else if (engineType == "Economic")
        enginePrice_ = 2000.0;
    else if (engineType == "Sport")
        enginePrice_ = 3000.0;

    rimPrice_ = (rimStyle == "Standard") ? 500.0 : 1000.0;

    if (material == "Cloth")
        materialPrice_ = 0.0;
    else if (material == "Leather")
        materialPrice_ = 2000.0;
    else if (material == "Synthetic")
        materialPrice_ = 1000.0;

    accessoryPrice_ = static_cast<double>(accessories.size()) * 500.0;
}

void Car::calculateTotalPrice() {
    totalPrice_ = price + enginePrice_ + rimPrice_ + materialPrice_ + accessoryPrice_;
}


void Car::printCarAscii() const {
    std::cout << "\nMake: " << make << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Price: $" << static_cast<int>(totalPrice_) << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Accessories: ";
    for (const auto& accessory : accessories) {
        std::cout << accessory << " ";
    }
    std::cout << std::endl;
    std::cout << "Engine Type: " << engineType << std::endl;
    std::cout << "Material: " << material << std::endl;
    std::cout << "Rim Style: " << rimStyle << std::endl;
    std::cout << "Front Color: " << frontColor << std::endl;
    std::cout << "Rear Color: " << rearColor << std::endl;
}
