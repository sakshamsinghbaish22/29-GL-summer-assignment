#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Employee {
    int id;
    std::string name;
    std::string department;
    double salary;
};

void addEmployee(std::vector<Employee>& employees) {
    Employee emp;
    std::cout << "Enter employee ID: ";
    std::cin >> emp.id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter employee name: ";
    std::getline(std::cin, emp.name);
    std::cout << "Enter department: ";
    std::getline(std::cin, emp.department);
    std::cout << "Enter salary: ";
    std::cin >> emp.salary;
    employees.push_back(emp);
    std::cout << "Employee added successfully.\n";
}

void displayEmployees(const std::vector<Employee>& employees) {
    if (employees.empty()) {
        std::cout << "No employees found.\n";
        return;
    }
    std::cout << "\nEmployee List:\n";
    for (const auto& emp : employees) {
        std::cout << "ID: " << emp.id << " | Name: " << emp.name
                  << " | Department: " << emp.department
                  << " | Salary: " << emp.salary << "\n";
    }
}

Employee* findEmployee(std::vector<Employee>& employees, int id) {
    for (auto& emp : employees) {
        if (emp.id == id) {
            return &emp;
        }
    }
    return nullptr;
}

void searchEmployee(const std::vector<Employee>& employees) {
    int id;
    std::cout << "Enter employee ID to search: ";
    std::cin >> id;
    for (const auto& emp : employees) {
        if (emp.id == id) {
            std::cout << "Employee found:\n";
            std::cout << "ID: " << emp.id << " | Name: " << emp.name
                      << " | Department: " << emp.department
                      << " | Salary: " << emp.salary << "\n";
            return;
        }
    }
    std::cout << "Employee with ID " << id << " not found.\n";
}

void updateEmployee(std::vector<Employee>& employees) {
    int id;
    std::cout << "Enter employee ID to update: ";
    std::cin >> id;
    Employee* emp = findEmployee(employees, id);
    if (!emp) {
        std::cout << "Employee not found.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter new name (leave blank to keep current): ";
    std::string name;
    std::getline(std::cin, name);
    if (!name.empty()) {
        emp->name = name;
    }
    std::cout << "Enter new department (leave blank to keep current): ";
    std::string department;
    std::getline(std::cin, department);
    if (!department.empty()) {
        emp->department = department;
    }
    std::cout << "Enter new salary (0 to keep current): ";
    double salary;
    std::cin >> salary;
    if (salary > 0) {
        emp->salary = salary;
    }
    std::cout << "Employee updated successfully.\n";
}

void deleteEmployee(std::vector<Employee>& employees) {
    int id;
    std::cout << "Enter employee ID to delete: ";
    std::cin >> id;
    auto it = std::remove_if(employees.begin(), employees.end(), [id](const Employee& emp) {
        return emp.id == id;
    });
    if (it == employees.end()) {
        std::cout << "Employee not found.\n";
        return;
    }
    employees.erase(it, employees.end());
    std::cout << "Employee deleted successfully.\n";
}

int main() {
    std::vector<Employee> employees;
    int choice = 0;
    while (true) {
        std::cout << "\nEmployee Management System\n";
        std::cout << "1. Add Employee\n";
        std::cout << "2. Display All Employees\n";
        std::cout << "3. Search Employee\n";
        std::cout << "4. Update Employee\n";
        std::cout << "5. Delete Employee\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                addEmployee(employees);
                break;
            case 2:
                displayEmployees(employees);
                break;
            case 3:
                searchEmployee(employees);
                break;
            case 4:
                updateEmployee(employees);
                break;
            case 5:
                deleteEmployee(employees);
                break;
            case 6:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}
