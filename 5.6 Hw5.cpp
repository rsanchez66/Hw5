#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;
    int length;

    // Private support method to adjust end position and shift characters
    void shiftCharacters(int startPos, int endPos) {
        memmove(str + startPos, str + endPos, length - endPos + 1);
        length -= (endPos - startPos);
    }

public:
    // Constructors, destructor, copy constructor, move constructor, assignment operator...
    // (omitted for brevity)

    // Remove method
    void remove(int startPos, int numChars) {
        if (startPos < 0 || startPos >= length || numChars <= 0) // Check for invalid parameters
            return;

        int endPos = startPos + numChars;
        if (endPos > length) // Adjust endPos if it's beyond the length of the string
            endPos = length;

        shiftCharacters(startPos, endPos);
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