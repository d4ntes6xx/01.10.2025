#include "Fraction.h"
using namespace std;

int main() {
    try {
        cout << "=== Fraction Class Demonstration ===\n\n";
        
        Fraction frac1(1, 2);
        Fraction frac2(3, 4);
        
        cout << "Fraction 1: ";
        frac1.display();
        cout << endl;
        
        cout << "Fraction 2: ";
        frac2.display();
        cout << endl;
        
        cout << "\nArithmetic Operations:\n";
        
        Fraction sum = frac1.add(frac2);
        cout << "Addition: ";
        frac1.display();
        cout << " + ";
        frac2.display();
        cout << " = ";
        sum.display();
        cout << " (" << sum.toDecimal() << ")" << endl;
        
        Fraction diff = frac1.subtract(frac2);
        cout << "Subtraction: ";
        frac1.display();
        cout << " - ";
        frac2.display();
        cout << " = ";
        diff.display();
        cout << " (" << diff.toDecimal() << ")" << endl;
        
        Fraction product = frac1.multiply(frac2);
        cout << "Multiplication: ";
        frac1.display();
        cout << " * ";
        frac2.display();
        cout << " = ";
        product.display();
        cout << " (" << product.toDecimal() << ")" << endl;
        
        Fraction quotient = frac1.divide(frac2);
        cout << "Division: ";
        frac1.display();
        cout << " / ";
        frac2.display();
        cout << " = ";
        quotient.display();
        cout << " (" << quotient.toDecimal() << ")" << endl;
        
        cout << "\n=== Input Fraction from Keyboard ===\n";
        Fraction frac3;
        frac3.input();
        
        cout << "Entered fraction: ";
        frac3.display();
        cout << " (" << frac3.toDecimal() << ")" << endl;
        
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    
    return 0;
}