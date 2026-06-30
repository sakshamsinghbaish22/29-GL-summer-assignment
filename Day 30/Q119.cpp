#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Employee {
    int id;
    string name;
    string department;
    double salary;
};

int findEmployee(const vector<Employee> &employees, int id) {
    for (int i = 0; i < static_cast<int>(employees.size()); ++i) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addEmployee(vector<Employee> &employees) {
    Employee emp;
    cout << "Enter employee id: ";
    cin >> emp.id;
    if (findEmployee(employees, emp.id) != -1) {
        cout << "Employee with this id already exists.\n";
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter employee name: ";
    getline(cin, emp.name);
    cout << "Enter department: ";
    getline(cin, emp.department);
    cout << "Enter salary: ";
    cin >> emp.salary;
    employees.push_back(emp);
    cout << "Employee added successfully.\n";
}

void listEmployees(const vector<Employee> &employees) {
    if (employees.empty()) {
        cout << "No employees available.\n";
        return;
    }
    cout << "\nEmployee List:\n";
    for (const auto &emp : employees) {
        cout << "Id: " << emp.id
             << ", Name: " << emp.name
             << ", Department: " << emp.department
             << ", Salary: " << emp.salary << "\n";
    }
}

void searchEmployee(const vector<Employee> &employees) {
    int id;
    cout << "Enter employee id to search: ";
    cin >> id;
    int index = findEmployee(employees, id);
    if (index == -1) {
        cout << "Employee not found.\n";
    } else {
        const Employee &emp = employees[index];
        cout << "Id: " << emp.id
             << ", Name: " << emp.name
             << ", Department: " << emp.department
             << ", Salary: " << emp.salary << "\n";
    }
}

void updateEmployee(vector<Employee> &employees) {
    int id;
    cout << "Enter employee id to update: ";
    cin >> id;
    int index = findEmployee(employees, id);
    if (index == -1) {
        cout << "Employee not found.\n";
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter new name: ";
    getline(cin, employees[index].name);
    cout << "Enter new department: ";
    getline(cin, employees[index].department);
    cout << "Enter new salary: ";
    cin >> employees[index].salary;
    cout << "Employee updated successfully.\n";
}

void removeEmployee(vector<Employee> &employees) {
    int id;
    cout << "Enter employee id to remove: ";
    cin >> id;
    int index = findEmployee(employees, id);
    if (index == -1) {
        cout << "Employee not found.\n";
        return;
    }
    employees.erase(employees.begin() + index);
    cout << "Employee removed successfully.\n";
}

int main() {
    vector<Employee> employees;
    int choice = 0;
    do {
        cout << "\nMini Employee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. List Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Remove Employee\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addEmployee(employees);
                break;
            case 2:
                listEmployees(employees);
                break;
            case 3:
                searchEmployee(employees);
                break;
            case 4:
                updateEmployee(employees);
                break;
            case 5:
                removeEmployee(employees);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    } while (choice != 6);
    return 0;
}
