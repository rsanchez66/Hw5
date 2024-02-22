#include <iostream>
#include <vector>

class StudentRecords {
private:
    std::vector<int> scores;

public:
    // Constructors
    StudentRecords() {}

    // Destructor
    ~StudentRecords() {}

    // Copy constructor
    StudentRecords(const StudentRecords& other) : scores(other.scores) {}

    // Move constructor
    StudentRecords(StudentRecords&& other) noexcept : scores(std::move(other.scores)) {}

    // Overloaded assignment operator
    StudentRecords& operator=(const StudentRecords& other) {
        if (this != &other) {
            scores = other.scores;
        }
        return *this;
    }

    // Add a new score to the records
    void addRecord(int score) {
        scores.push_back(score);
    }

    // Calculate the average score
    double averageRecord() const {
        if (scores.empty()) {
            std::cerr << "No records available." << std::endl;
            return 0.0;
        }

        int total = 0;
        for (int score : scores) {
            total += score;
        }
        return static_cast<double>(total) / scores.size();
    }
};

int main() {
    // Create a collection of student records
    StudentRecords records;

    // Add some records
    records.addRecord(85);
    records.addRecord(90);
    records.addRecord(75);

    // Calculate and display the average score
    std::cout << "Average score: " << records.averageRecord() << std::endl;

    return 0;
}