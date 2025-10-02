#include "fraction.h"
#include <string>
#include <limits>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayHeader() {
    cout << "========================================\n";
    cout << "           FRACTION CALCULATOR          \n";
    cout << "========================================\n";
}

void showMenu() {
    clearScreen();
    displayHeader();
    cout << "\n--- MAIN MENU ---\n";
    cout << "1.  Add fractions\n";
    cout << "2.  Subtract fractions\n";
    cout << "3.  Multiply fractions\n";
    cout << "4.  Divide fractions\n";
    cout << "5.  Compare fractions\n";
    cout << "6.  Power of fraction\n";
    cout << "7.  Reciprocal of fraction\n";
    cout << "8.  Convert to decimal\n";
    cout << "9.  Display as mixed number\n";
    cout << "10. Negate fraction\n";
    cout << "0.  Exit\n";
    cout << "Choose operation: ";
}

void printResult(const Fraction& result, const string& operation) {
    cout << "\nResult: " << operation << " = ";
    result.display();
    cout << " (decimal: " << result.toDecimal() << ")\n";
}

void performOperation(int choice) {
    try {
        Fraction f1, f2;
        int exponent;
        
        switch (choice) {
            case 1: // Addition
                clearScreen();
                cout << "--- ADDITION ---\n\n";
                cout << "Enter first fraction:\n"; f1.input();
                cout << "Enter second fraction:\n"; f2.input();
                cout << "\nResult: ";
                f1.display(); cout << " + "; f2.display(); cout << " = ";
                f1.add(f2).display();
                cout << " (" << f1.add(f2).toDecimal() << ")\n";
                break;
                
            case 2: // Subtraction
                clearScreen();
                cout << "--- SUBTRACTION ---\n\n";
                cout << "Enter first fraction:\n"; f1.input();
                cout << "Enter second fraction:\n"; f2.input();
                cout << "\nResult: ";
                f1.display(); cout << " - "; f2.display(); cout << " = ";
                f1.subtract(f2).display();
                cout << " (" << f1.subtract(f2).toDecimal() << ")\n";
                break;
                
            case 3: // Multiplication
                clearScreen();
                cout << "--- MULTIPLICATION ---\n\n";
                cout << "Enter first fraction:\n"; f1.input();
                cout << "Enter second fraction:\n"; f2.input();
                cout << "\nResult: ";
                f1.display(); cout << " * "; f2.display(); cout << " = ";
                f1.multiply(f2).display();
                cout << " (" << f1.multiply(f2).toDecimal() << ")\n";
                break;
                
            case 4: // Division
                clearScreen();
                cout << "--- DIVISION ---\n\n";
                cout << "Enter first fraction:\n"; f1.input();
                cout << "Enter second fraction:\n"; f2.input();
                cout << "\nResult: ";
                f1.display(); cout << " / "; f2.display(); cout << " = ";
                f1.divide(f2).display();
                cout << " (" << f1.divide(f2).toDecimal() << ")\n";
                break;
                
            case 5: // Comparison
                clearScreen();
                cout << "--- COMPARISON ---\n\n";
                cout << "Enter first fraction:\n"; f1.input();
                cout << "Enter second fraction:\n"; f2.input();
                cout << "\nComparison results:\n";
                cout << f1.toDecimal() << " == " << f2.toDecimal() << " : " 
                     << (f1.isEqual(f2) ? "true" : "false") << endl;
                cout << f1.toDecimal() << " > " << f2.toDecimal() << " : " 
                     << (f1.isGreater(f2) ? "true" : "false") << endl;
                cout << f1.toDecimal() << " < " << f2.toDecimal() << " : " 
                     << (f1.isLess(f2) ? "true" : "false") << endl;
                break;
                
            case 6: // Power
                clearScreen();
                cout << "--- POWER ---\n\n";
                cout << "Enter fraction:\n"; f1.input();
                cout << "Enter exponent: "; cin >> exponent;
                cout << "\nResult: ";
                f1.display(); cout << "^" << exponent << " = ";
                f1.power(exponent).display();
                cout << " (" << f1.power(exponent).toDecimal() << ")\n";
                break;
                
            case 7: // Reciprocal
                clearScreen();
                cout << "--- RECIPROCAL ---\n\n";
                cout << "Enter fraction:\n"; f1.input();
                cout << "Reciprocal of "; f1.display(); cout << " is ";
                f1.reciprocal().display();
                cout << " (" << f1.reciprocal().toDecimal() << ")\n";
                break;
                
            case 8: // To Decimal
                clearScreen();
                cout << "--- DECIMAL CONVERSION ---\n\n";
                cout << "Enter fraction:\n"; f1.input();
                cout << "Decimal form: " << f1.toDecimal() << endl;
                break;
                
            case 9: // Mixed Number
                clearScreen();
                cout << "--- MIXED NUMBER ---\n\n";
                cout << "Enter fraction:\n"; f1.input();
                cout << "Mixed number: "; f1.displayMixed(); cout << endl;
                break;
                
            case 10: // Negate
                clearScreen();
                cout << "--- NEGATION ---\n\n";
                cout << "Enter fraction:\n"; f1.input();
                cout << "Negation: "; f1.negate().display(); cout << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    int choice;
    
    while (true) {
        showMenu();
        cin >> choice;
        
        if (choice == 0) {
            clearScreen();
            cout << "Thank you for using Fraction Calculator!\n";
            cout << "Goodbye!\n";
            break;
        }
        
        if (choice >= 1 && choice <= 10) {
            performOperation(choice);
            waitForEnter();
        } else {
            cout << "Invalid choice! Please try again.\n";
            waitForEnter();
        }
    }
    
    return 0;
}