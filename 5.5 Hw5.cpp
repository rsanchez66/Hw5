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

    // Remove method
    void remove(int startPos, int numChars) {
        if (startPos < 0 || startPos >= length || numChars <= 0) // Check for invalid parameters
            return;

        int endPos = startPos + numChars;
        if (endPos > length) // Adjust endPos if it's beyond the length of the string
            endPos = length;

        memmove(str + startPos, str + endPos, length - endPos + 1);
        length -= (endPos - startPos);
    }
};

int main() {
    MyString str("Hello World!");

    // Testing remove method
    std::cout << "Original String: " << str.getString() << std::endl;
    str.remove(5, 6); // Remove 6 characters starting at position 5
    std::cout << "After removing 6 characters from position 5: " << str.getString() << std::endl;

    return 0;
}