#include <iostream>
#include <string>

class Automobile {
private:
    std::string manufacturerName;
    std::string modelName;
    int modelYear;

public:
    // Constructor
    Automobile(const std::string& manufacturer, const std::string& model, int year)
        : manufacturerName(manufacturer), modelName(model), modelYear(year) {}

    // Getter methods
    std::string getManufacturerName() const {
        return manufacturerName;
    }

    std::string getModelName() const {
        return modelName;
    }

    int getModelYear() const {
        return modelYear;
    }

    // Setter methods
    void setManufacturerName(const std::string& manufacturer) {
        manufacturerName = manufacturer;
    }

    void setModelName(const std::string& model) {
        modelName = model;
    }

    void setModelYear(int year) {
        modelYear = year;
    }
};

int main() {
    // Create an instance of Automobile
    Automobile car("Toyota", "Camry", 2022);

    // Get and display the automobile details
    std::cout << "Manufacturer: " << car.getManufacturerName() << std::endl;
    std::cout << "Model: " << car.getModelName() << std::endl;
    std::cout << "Year: " << car.getModelYear() << std::endl;

    // Update the automobile details
    car.setManufacturerName("Honda");
    car.setModelYear(2023);

    // Display the updated details
    std::cout << "\nUpdated Manufacturer: " << car.getManufacturerName() << std::endl;
    std::cout << "Updated Year: " << car.getModelYear() << std::endl;

    return 0;
}