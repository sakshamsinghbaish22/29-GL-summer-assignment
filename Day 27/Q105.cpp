#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    int id;
    std::string name;
    int age;
    char grade;
};

void addStudent(std::vector<Student>& students) {
    Student s;
    std::cout << "Enter student id: ";
    std::cin >> s.id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter student name: ";
    std::getline(std::cin, s.name);
    std::cout << "Enter student age: ";
    std::cin >> s.age;
    std::cout << "Enter student grade: ";
    std::cin >> s.grade;
    students.push_back(s);
    std::cout << "Student added successfully.\n";
}

void displayStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No student records available.\n";
        return;
    }
    std::cout << "Student Records:\n";
    for (const auto& s : students) {
        std::cout << "ID: " << s.id
                  << ", Name: " << s.name
                  << ", Age: " << s.age
                  << ", Grade: " << s.grade << "\n";
    }
}

std::vector<Student>::iterator findStudent(std::vector<Student>& students, int id) {
    return std::find_if(students.begin(), students.end(), [id](const Student& s) {
        return s.id == id;
    });
}

void searchStudent(const std::vector<Student>& students) {
    int id;
    std::cout << "Enter student id to search: ";
    std::cin >> id;
    auto it = std::find_if(students.begin(), students.end(), [id](const Student& s) {
        return s.id == id;
    });
    if (it == students.end()) {
        std::cout << "Student not found.\n";
    } else {
        std::cout << "ID: " << it->id
                  << ", Name: " << it->name
                  << ", Age: " << it->age
                  << ", Grade: " << it->grade << "\n";
    }
}

void updateStudent(std::vector<Student>& students) {
    int id;
    std::cout << "Enter student id to update: ";
    std::cin >> id;
    auto it = findStudent(students, id);
    if (it == students.end()) {
        std::cout << "Student not found.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter new name: ";
    std::getline(std::cin, it->name);
    std::cout << "Enter new age: ";
    std::cin >> it->age;
    std::cout << "Enter new grade: ";
    std::cin >> it->grade;
    std::cout << "Student record updated.\n";
}

void deleteStudent(std::vector<Student>& students) {
    int id;
    std::cout << "Enter student id to delete: ";
    std::cin >> id;
    auto it = findStudent(students, id);
    if (it == students.end()) {
        std::cout << "Student not found.\n";
        return;
    }
    students.erase(it);
    std::cout << "Student record deleted.\n";
}

int main() {
    std::vector<Student> students;
    int choice;
    do {
        std::cout << "\nStudent Record Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display All Students\n";
        std::cout << "3. Search Student\n";
        std::cout << "4. Update Student\n";
        std::cout << "5. Delete Student\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);
    return 0;
}
