#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::string name;
    std::string roll;
    int mathematics;
    int physics;
    int chemistry;
    int english;
    int computer;

    std::cout << "Enter student name: ";
    std::getline(std::cin, name);

    std::cout << "Enter roll number: ";
    std::getline(std::cin, roll);

    std::cout << "Enter marks for Mathematics Physics Chemistry English Computer: ";
    if (!(std::cin >> mathematics >> physics >> chemistry >> english >> computer)) {
        std::cerr << "Invalid input. Please enter numeric marks." << std::endl;
        return 1;
    }

    int total = mathematics + physics + chemistry + english + computer;
    double percentage = total / 5.0;
    std::string grade;

    if (percentage >= 90) {
        grade = "A+";
    } else if (percentage >= 80) {
        grade = "A";
    } else if (percentage >= 70) {
        grade = "B";
    } else if (percentage >= 60) {
        grade = "C";
    } else if (percentage >= 50) {
        grade = "D";
    } else {
        grade = "F";
    }

    std::cout << "\n========== MARKSHEET ==========" << std::endl;
    std::cout << "Name      : " << name << std::endl;
    std::cout << "Roll No.  : " << roll << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "Subject" << std::setw(10) << "Marks" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "Mathematics" << std::setw(10) << mathematics << std::endl;
    std::cout << std::left << std::setw(15) << "Physics" << std::setw(10) << physics << std::endl;
    std::cout << std::left << std::setw(15) << "Chemistry" << std::setw(10) << chemistry << std::endl;
    std::cout << std::left << std::setw(15) << "English" << std::setw(10) << english << std::endl;
    std::cout << std::left << std::setw(15) << "Computer" << std::setw(10) << computer << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << std::left << std::setw(15) << "Total" << std::setw(10) << total << std::endl;
    std::cout << std::left << std::setw(15) << "Percentage" << std::fixed << std::setprecision(2) << percentage << std::endl;
    std::cout << std::left << std::setw(15) << "Grade" << grade << std::endl;
    std::cout << "================================" << std::endl;

    return 0;
}
