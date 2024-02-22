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

    // Getter for length
    int getLength() const {
        return length;
    }

    // Append function
    void append(const char* s) {
        int newLength = length + strlen(s);
        char* temp = new char[newLength + 1];
        strcpy(temp, str);
        strcat(temp, s);
        delete[] str;
        str = temp;
        length = newLength;
    }

    // Concatenate function
    MyString concatenate(const MyString& other) const {
        MyString result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    // CharacterAt function
    char characterAt(int index) const {
        if (index >= 0 && index < length)
            return str[index];
        else
            return '\0'; // Null character if index out of bounds
    }

    // Getter for string
    const char* getString() const {
        return str;
    }
};

int main() {
    MyString str1("Hello");
    MyString str2(" World!");

    // Testing append
    str1.append(" ");
    str1.append("World!");

    std::cout << "Appended String: " << str1.getString() << std::endl;

    // Testing concatenate
    MyString result = str1.concatenate(str2);
    std::cout << "Concatenated String: " << result.getString() << std::endl;

    // Testing characterAt
    std::cout << "Character at index 6: " << result.characterAt(6) << std::endl;

    return 0;
}