#include "Fraction.h"
#include <string>
using namespace std;

void displayHeader() {
    cout << "========================================\n";
    cout << "           FRACTION CALCULATOR          \n";
    cout << "========================================\n";
}

void showMenu() {
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
            case 1:
                cout << "\n--- ADDITION ---\n";
                cout << "Enter first fraction:\n"; f1.input();
                cout << "Enter second fraction:\n"; f2.input();
                cout << "\nResult: ";
                f1.display(); cout << " + "; f2.display(); cout << " = ";
                f1.add(f2).display();
                cout << " (" << f1.add(f2).toDecimal() << ")\n";
                break;
                
            case 2:
                cout << "\n--- SUBTRACTION ---\n";
                cout << "Enter first fraction:\n"; f1.input();
                cout << "Enter second fraction:\n"; f2.input();
                cout << "\nResult: ";
                f1.display(); cout << " - "; f2.display(); cout << " = ";
                f1.subtract(f2).display();
                cout << " (" << f1.subtract(f2).toDecimal() << ")\n";
                break;
                
            case 3:
                cout << "\n--- MULTIPLICATION ---\n";
                cout << "Enter first fraction:\n"; f1.input();
                cout << "Enter second fraction:\n"; f2.input();
                cout << "\nResult: ";
                f1.display(); cout << " * "; f2.display(); cout << " = ";
                f1.multiply(f2).display();
                cout << " (" << f1.multiply(f2).toDecimal() << ")\n";
                break;
                
            case 4: // Division
                cout << "\n--- DIVISION ---\n";
                cout << "Enter first fraction:\n"; f1.input();
                cout << "Enter second fraction:\n"; f2.input();
                cout << "\nResult: ";
                f1.display(); cout << " / "; f2.display(); cout << " = ";
                f1.divide(f2).display();
                cout << " (" << f1.divide(f2).toDecimal() << ")\n";
                break;
                
            case 5: // Comparison
                cout << "\n--- COMPARISON ---\n";
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
                
            case 6:
                cout << "\n--- POWER ---\n";
                cout << "Enter fraction:\n"; f1.input();
                cout << "Enter exponent: "; cin >> exponent;
                cout << "\nResult: ";
                f1.display(); cout << "^" << exponent << " = ";
                f1.power(exponent).display();
                cout << " (" << f1.power(exponent).toDecimal() << ")\n";
                break;
                
            case 7:
                cout << "\n--- RECIPROCAL ---\n";
                cout << "Enter fraction:\n"; f1.input();
                cout << "Reciprocal of "; f1.display(); cout << " is ";
                f1.reciprocal().display();
                cout << " (" << f1.reciprocal().toDecimal() << ")\n";
                break;
                
            case 8:
                cout << "\n--- DECIMAL CONVERSION ---\n";
                cout << "Enter fraction:\n"; f1.input();
                cout << "Decimal form: " << f1.toDecimal() << endl;
                break;
                
            case 9:
                cout << "\n--- MIXED NUMBER ---\n";
                cout << "Enter fraction:\n"; f1.input();
                cout << "Mixed number: "; f1.displayMixed(); cout << endl;
                break;
                
            case 10:
                cout << "\n--- NEGATION ---\n";
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

int main() {
    int choice;
    
    displayHeader();
    cout << "Welcome to Fraction Calculator!\n";
    cout << "Perform arithmetic operations with fractions.\n";
    
    while (true) {
        showMenu();
        cin >> choice;
        
        if (choice == 0) {
            cout << "\nThank you for using Fraction Calculator!\n";
            cout << "Goodbye!\n";
            break;
        }
        
        performOperation(choice);
        

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    return 0;
}