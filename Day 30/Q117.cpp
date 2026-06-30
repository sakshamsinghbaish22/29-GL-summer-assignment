#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    string name;
    int roll;
    float marks;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    if (!(cin >> n) || n <= 0 || n > MAX_STUDENTS) {
        cout << "Invalid number of students." << endl;
        return 0;
    }

    Student students[MAX_STUDENTS];

    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << " details:\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Roll number: ";
        cin >> students[i].roll;
        cout << "Marks: ";
        cin >> students[i].marks;
    }

    cout << "\nStudent records:\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << students[i].name
             << ", Roll: " << students[i].roll
             << ", Marks: " << students[i].marks << endl;
    }

    return 0;
}
