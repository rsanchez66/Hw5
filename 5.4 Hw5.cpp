#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;
    int length;

public:
    // Constructors
    MyString() : str(nullptr), length(0) {}
    
    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Destructor
    ~MyString() {
        delete[] str;
    }

    // Copy constructor
    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // Move constructor
    MyString(MyString&& other) noexcept {
        length = other.length;
        str = other.str;
        other.str = nullptr;
    }

    // Overloaded assignment operator
    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Overloaded [] operator
    char& operator[](int index) {
        if (index >= 0 && index < length)
            return str[index];
        else {
            static char nullchar = '\0'; // Static to avoid returning a reference to a local variable
            return nullchar; // Return null character if index is out of bounds
        }
    }

    // Getter for length
    int getLength() const {
        return length;
    }

    // Getter for string
    const char* getString() const {
        return str;
    }
};

int main() {
    MyString str("Hello");

    // Testing overloaded [] operator
    std::cout << "Character at index 1: " << str[1] << std::endl;

    return 0;
}