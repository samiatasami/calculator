#include <iostream>
#include <limits> // For input validation

using namespace std;

void displayMenu() {
    cout << "\nSimple Calculator Menu:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Exit\n";
    cout << "Enter your choice (1-5): ";
}

double getNumber(const string& prompt) {
    double number;
    while (true) {
        cout << prompt;
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
    }
}

int main() {
    int choice;
    double num1, num2, result;

    cout << "Welcome to Simple Calculator!\n";

    do {
        displayMenu();
        
        // Input validation for menu choice
        while (!(cin >> choice) || choice < 1 || choice > 5) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter a number between 1 and 5: ";
        }

        if (choice == 5) {
            cout << "Exiting calculator. Goodbye!\n";
            break;
        }

        num1 = getNumber("Enter first number: ");
        num2 = getNumber("Enter second number: ");

        switch (choice) {
            case 1: // Addition
                result = num1 + num2;
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case 2: // Subtraction
                result = num1 - num2;
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case 3: // Multiplication
                result = num1 * num2;
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case 4: // Division
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                }
                else {
                    cout << "Error: Division by zero is not allowed.\n";
                }
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}