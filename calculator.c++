#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double num1, num2;
    char op, choice;

    do {
        cout << "\nEnter the first number: ";
        cin >> num1;

        cout << "Enter the second number: ";
        cin >> num2;

        cout << "Enter the operator (+, -, *, /, %, c, s, t, q): ";
        cin >> op;

        switch(op) {
            case '+':
                cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
                break;

            case '-':
                cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
                break;

            case '*':
                cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
                break;

            case '/':
                if (num2 == 0)
                    cout << "Error: Division by zero.\n";
                else
                    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
                break;

            case '%':
                if (num2 == 0)
                    cout << "Error: Modulo by zero.\n";
                else
                    cout << "Remainder = " << fmod(num1, num2) << endl;
                break;

            case 'c':
                cout << "cos(" << num1 << ") = " << cos(num1) << endl;
                cout << "cos(" << num2 << ") = " << cos(num2) << endl;
                break;

            case 's':
                cout << "sin(" << num1 << ") = " << sin(num1) << endl;
                cout << "sin(" << num2 << ") = " << sin(num2) << endl;
                break;

            case 't':
                cout << "tan(" << num1 << ") = " << tan(num1) << endl;
                cout << "tan(" << num2 << ") = " << tan(num2) << endl;
                break;

            case 'q':
                if (num1 < 0 || num2 < 0)
                    cout << "Error: Cannot calculate square root of a negative number.\n";
                else {
                    cout << "sqrt(" << num1 << ") = " << sqrt(num1) << endl;
                    cout << "sqrt(" << num2 << ") = " << sqrt(num2) << endl;
                }
                break;

            default:
                cout << "Invalid operator!\n";
        }

        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nCalculator exited. Goodbye!\n";

    return 0;
}