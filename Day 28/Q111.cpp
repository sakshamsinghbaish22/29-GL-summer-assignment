#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void showSeats(const vector<vector<bool>>& booked) {
    cout << "\nSeat Layout (0 = available, X = booked):\n";
    cout << "   ";
    for (size_t c = 0; c < booked[0].size(); ++c) {
        cout << c + 1 << " ";
    }
    cout << "\n";
    for (size_t r = 0; r < booked.size(); ++r) {
        cout << r + 1 << ": ";
        for (size_t c = 0; c < booked[r].size(); ++c) {
            cout << (booked[r][c] ? 'X' : '0') << " ";
        }
        cout << "\n";
    }
}

int main() {
    const int rows = 5;
    const int cols = 5;
    vector<vector<bool>> booked(rows, vector<bool>(cols, false));
    vector<vector<string>> customer(rows, vector<string>(cols, ""));
    int choice = 0;

    while (true) {
        cout << "\nTicket Booking System\n";
        cout << "1. Show seats\n";
        cout << "2. Book ticket\n";
        cout << "3. Cancel ticket\n";
        cout << "4. View booking details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            showSeats(booked);
        } else if (choice == 2) {
            int r, c;
            cout << "Enter row number (1-" << rows << "): ";
            cin >> r;
            cout << "Enter column number (1-" << cols << "): ";
            cin >> c;
            if (r < 1 || r > rows || c < 1 || c > cols) {
                cout << "Invalid seat selection.\n";
                continue;
            }
            if (booked[r-1][c-1]) {
                cout << "Seat already booked. Please choose another seat.\n";
            } else {
                cout << "Enter customer name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, customer[r-1][c-1]);
                booked[r-1][c-1] = true;
                cout << "Seat booked successfully.\n";
            }
        } else if (choice == 3) {
            int r, c;
            cout << "Enter row number (1-" << rows << "): ";
            cin >> r;
            cout << "Enter column number (1-" << cols << "): ";
            cin >> c;
            if (r < 1 || r > rows || c < 1 || c > cols) {
                cout << "Invalid seat selection.\n";
                continue;
            }
            if (!booked[r-1][c-1]) {
                cout << "Seat is not booked.\n";
            } else {
                booked[r-1][c-1] = false;
                customer[r-1][c-1].clear();
                cout << "Booking cancelled successfully.\n";
            }
        } else if (choice == 4) {
            cout << "\nBooked seat details:\n";
            bool any = false;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (booked[i][j]) {
                        cout << "Row " << i + 1 << ", Column " << j + 1 << ": " << customer[i][j] << "\n";
                        any = true;
                    }
                }
            }
            if (!any) {
                cout << "No bookings yet.\n";
            }
        } else if (choice == 5) {
            cout << "Exiting booking system.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
