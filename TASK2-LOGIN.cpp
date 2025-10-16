#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isUserExists(const string& username) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "\n=== Registration ===\n";
    cout << "Enter username: ";
    cin >> username;

    if (isUserExists(username)) {
        cout << "? Username already exists. Please choose another one.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    if (username.empty() || password.empty()) {
        cout << "? Username or password cannot be empty!\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "? Registration successful!\n";
}

void loginUser() {
    string username, password;
    cout << "\n=== Login ===\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    bool found = false;

    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found)
        cout << "? Login successful! Welcome, " << username << "!\n";
    else
        cout << "? Invalid username or password!\n";
}

int main() {
    int choice;
    do {
        cout << "\n========== LOGIN SYSTEM ==========\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
