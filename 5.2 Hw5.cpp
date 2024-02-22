#include <iostream>
#include <string>
#include <chrono> // For calculating age

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

    // Support methods
    std::string getDescription() const {
        return std::to_string(modelYear) + " " + manufacturerName + " " + modelName;
    }

    int getAgeInYears() const {
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        std::tm year_tm = *std::localtime(&now_c);

        int currentYear = year_tm.tm_year + 1900;

        return currentYear - modelYear;
    }
};

int main() {
    // Create an instance of Automobile
    Automobile car("Toyota", "Camry", 2022);

    // Get and display the complete description of the automobile
    std::cout << "Description: " << car.getDescription() << std::endl;

    // Get and display the age of the automobile
    std::cout << "Age of the automobile: " << car.getAgeInYears() << " years" << std::endl;

    return 0;
}