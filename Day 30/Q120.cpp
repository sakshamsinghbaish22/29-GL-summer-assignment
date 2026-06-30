#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

const int MAX_STUDENTS = 5;

void displayMenu() {
    std::cout << "\nStudent Record Mini Project\n";
    std::cout << "1. Add student record\n";
    std::cout << "2. Display all records\n";
    std::cout << "3. Search record by name\n";
    std::cout << "4. Update grade\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter choice: ";
}

void addStudent(std::string names[], int ids[], double grades[], int &count) {
    if (count >= MAX_STUDENTS) {
        std::cout << "Record limit reached.\n";
        return;
    }
    std::cout << "Enter student name: ";
    std::getline(std::cin, names[count]);
    std::cout << "Enter student ID: ";
    std::cin >> ids[count];
    std::cout << "Enter grade: ";
    std::cin >> grades[count];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    count++;
    std::cout << "Record added successfully.\n";
}

void displayStudents(const std::string names[], const int ids[], const double grades[], int count) {
    if (count == 0) {
        std::cout << "No records to display.\n";
        return;
    }
    std::cout << std::left << std::setw(20) << "Name" << std::setw(10) << "ID" << std::setw(8) << "Grade" << '\n';
    std::cout << std::string(38, '-') << '\n';
    for (int i = 0; i < count; ++i) {
        std::cout << std::left << std::setw(20) << names[i] << std::setw(10) << ids[i] << std::setw(8) << grades[i] << '\n';
    }
}

int findStudentIndex(const std::string names[], int count, const std::string &searchName) {
    for (int i = 0; i < count; ++i) {
        if (names[i] == searchName) {
            return i;
        }
    }
    return -1;
}

void searchStudent(const std::string names[], const int ids[], const double grades[], int count) {
    if (count == 0) {
        std::cout << "No records available.\n";
        return;
    }
    std::string query;
    std::cout << "Enter name to search: ";
    std::getline(std::cin, query);
    int index = findStudentIndex(names, count, query);
    if (index >= 0) {
        std::cout << "Record found:\n";
        std::cout << "Name: " << names[index] << "\n";
        std::cout << "ID: " << ids[index] << "\n";
        std::cout << "Grade: " << grades[index] << "\n";
    } else {
        std::cout << "Student not found.\n";
    }
}

void updateGrade(std::string names[], double grades[], int count) {
    if (count == 0) {
        std::cout << "No records available.\n";
        return;
    }
    std::string query;
    std::cout << "Enter name to update grade: ";
    std::getline(std::cin, query);
    int index = findStudentIndex(names, count, query);
    if (index >= 0) {
        std::cout << "Current grade: " << grades[index] << "\n";
        std::cout << "Enter new grade: ";
        std::cin >> grades[index];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Grade updated successfully.\n";
    } else {
        std::cout << "Student not found.\n";
    }
}

int main() {
    std::string names[MAX_STUDENTS];
    int ids[MAX_STUDENTS] = {0};
    double grades[MAX_STUDENTS] = {0.0};
    int recordCount = 0;

    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addStudent(names, ids, grades, recordCount);
                break;
            case 2:
                displayStudents(names, ids, grades, recordCount);
                break;
            case 3:
                searchStudent(names, ids, grades, recordCount);
                break;
            case 4:
                updateGrade(names, grades, recordCount);
                break;
            case 5:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
