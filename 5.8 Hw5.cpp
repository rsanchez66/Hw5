#include <iostream>
#include <vector>

class StudentRecords {
private:
    std::vector<int> scores;

public:
    // Constructors, destructor, copy constructor, move constructor, assignment operator...

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

    // Return a new collection consisting of records within the specified range
    StudentRecords RecordsWithinRange(int lowGrade, int highGrade) const {
        StudentRecords result;
        for (int score : scores) {
            if (score >= lowGrade && score <= highGrade) {
                result.addRecord(score);
            }
        }
        return result;
    }
};

int main() {
    // Create a collection of student records
    StudentRecords records;

    // Add some records
    records.addRecord(85);
    records.addRecord(90);
    records.addRecord(75);
    records.addRecord(70);
    records.addRecord(80);

    // Calculate and display the average score
    std::cout << "Average score: " << records.averageRecord() << std::endl;

    // Get a new collection consisting of records within the specified range
    StudentRecords rangeRecords = records.RecordsWithinRange(75, 80);

    // Display the scores within the specified range
    std::cout << "Scores within the range 75-80: ";
    for (int score : rangeRecords.getScores()) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    return 0;
}