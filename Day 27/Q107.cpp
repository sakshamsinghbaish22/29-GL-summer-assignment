#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

struct Employee {
    int id;
    std::string name;
    double basicPay;
    double hra;
    double da;
    double grossSalary;
};

void displayMenu() {
    std::cout << "Salary Management System\n";
    std::cout << "1. Add employee record\n";
    std::cout << "2. Display all records\n";
    std::cout << "3. Calculate salary for an employee\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void addEmployee(std::vector<Employee>& employees) {
    Employee emp;
    std::cout << "Enter employee id: ";
    std::cin >> emp.id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter employee name: ";
    std::getline(std::cin, emp.name);
    std::cout << "Enter basic pay: ";
    std::cin >> emp.basicPay;

    emp.hra = emp.basicPay * 0.2;
    emp.da = emp.basicPay * 0.1;
    emp.grossSalary = emp.basicPay + emp.hra + emp.da;

    employees.push_back(emp);
    std::cout << "Employee record added successfully.\n";
}

void displayRecords(const std::vector<Employee>& employees) {
    if (employees.empty()) {
        std::cout << "No employee records available.\n";
        return;
    }
    std::cout << std::left << std::setw(10) << "ID"
              << std::setw(20) << "Name"
              << std::setw(12) << "Basic Pay"
              << std::setw(10) << "HRA"
              << std::setw(10) << "DA"
              << std::setw(14) << "Gross Salary" << '\n';
    for (const auto& emp : employees) {
        std::cout << std::left << std::setw(10) << emp.id
                  << std::setw(20) << emp.name
                  << std::setw(12) << emp.basicPay
                  << std::setw(10) << emp.hra
                  << std::setw(10) << emp.da
                  << std::setw(14) << emp.grossSalary << '\n';
    }
}

void calculateSalary(const std::vector<Employee>& employees) {
    if (employees.empty()) {
        std::cout << "No employee records available.\n";
        return;
    }
    int searchId;
    std::cout << "Enter employee id to calculate salary: ";
    std::cin >> searchId;
    for (const auto& emp : employees) {
        if (emp.id == searchId) {
            std::cout << "Employee: " << emp.name << "\n";
            std::cout << "Basic Pay: " << emp.basicPay << "\n";
            std::cout << "HRA (20%): " << emp.hra << "\n";
            std::cout << "DA (10%): " << emp.da << "\n";
            std::cout << "Gross Salary: " << emp.grossSalary << "\n";
            return;
        }
    }
    std::cout << "Employee with id " << searchId << " not found.\n";
}

int main() {
    std::vector<Employee> employees;
    int choice = 0;
    while (true) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case 1:
                addEmployee(employees);
                break;
            case 2:
                displayRecords(employees);
                break;
            case 3:
                calculateSalary(employees);
                break;
            case 4:
                std::cout << "Exiting salary management system.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please select a valid option.\n";
                break;
        }
        std::cout << "\n";
    }
    return 0;
}
