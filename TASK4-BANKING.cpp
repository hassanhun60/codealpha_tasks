#include <iostream>
using namespace std;

int main() {
    string name;
    int choice;
    float balance = 0, amount;

    cout << "Enter your name: ";
    cin >> name;

    do {
        cout << "\n===== Simple Banking System =====" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                balance += amount;
                cout << "Deposited successfully!" << endl;
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (amount > balance) {
                    cout << "Insufficient balance!" << endl;
                } else {
                    balance -= amount;
                    cout << "Withdrawn successfully!" << endl;
                }
                break;

            case 3:
                cout << "Current Balance: " << balance << endl;
                break;

            case 4:
                cout << "Thank you for using our bank, " << name << "!" << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
