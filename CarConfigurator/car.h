#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <vector>

class Car {
public:
    Car(const std::string& make, const std::string& model, double price, const std::string& color,
        const std::vector<std::string>& accessories, const std::string& engineType, const std::string& material);

    std::string getMake() const;
    std::string getModel() const;
    int getPrice() const;
    std::string getColor() const;
    std::vector<std::string> getAccessories() const;
    std::string getEngineType() const;
    std::string getMaterial() const;
    std::string getRimStyle() const;
    std::string getFrontColor() const;
    std::string getRearColor() const;


    void setMake(const std::string& make);
    void setModel(const std::string& model);
    void setPrice(double price);
    void setColor(const std::string& color);
    void addAccessory(const std::string& accessory);
    void removeAccessory(const std::string& accessory);
    void setEngineType(const std::string& engineType);
    void setMaterial(const std::string& material);
    void setRimStyle(const std::string& rimStyle);
    void setFrontColor(const std::string& frontColor);
    void setRearColor(const std::string& rearColor);
    void listAvailableAccessories() const;
    void listAvailableTrims() const;

    std::vector<std::string> availableRimStyles;

    std::vector<std::string> getAvailableColors() const;
    std::vector<std::string> getAvailableEngineTypes() const;
    std::vector<std::string> getAvailableMaterials() const;
    std::vector<std::string> getAvailableRimStyles() const;

    void calculateOptionPrices();
    void calculateTotalPrice();
    void printCarAscii() const;

private:
    std::string make;
    std::string model;
    double price;
    std::string color;
    std::vector<std::string> accessories;
    std::string engineType;
    std::string material;
    std::string rimStyle;
    std::string frontColor;
    std::string rearColor;

    std::vector<std::string> availableTrims;

    double enginePrice_;
    double rimPrice_;
    double materialPrice_;
    double accessoryPrice_;
    double totalPrice_;

    
};

#endif // CAR_H
