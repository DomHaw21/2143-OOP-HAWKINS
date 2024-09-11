#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int num, int den) : numerator(num), denominator(den) {
        // Consider validating that denominator is not 0
    }

    // Overloaded addition operator
    Fraction operator+(const Fraction& other) {
        // TODO: Use LCM and LCD to add fractions correctly
        // Add comments explaining how you use LCD and LCM to add fractions
        // Steps:
        // 1. Find the least common denominator (LCD)
        // 2. Adjust both fractions to have this denominator
        // 3. Add the numerators
        // 4. Return the result as a new fraction
    }

    // Additional overloaded operators (students should implement these)
    // Overloaded subtraction operator
    Fraction operator-(const Fraction& other) {
        // TODO: Implement the subtraction logic
    }

    // Overloaded multiplication operator
    Fraction operator*(const Fraction& other) {
        // TODO: Implement the multiplication logic
    }

    // Overloaded division operator
    Fraction operator/(const Fraction& other) {
        // TODO: Implement the division logic
    }

    // Overloaded equality operator (==)
    bool operator==(const Fraction& other) const {
        // TODO: Check if two fractions are equal by comparing numerators and denominators
    }

    // Overload output operator (<<) for printing fractions
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    // TODO: Implement methods to read input from stdin (lecture topic)
};

// Function to calculate Least Common Denominator (LCD)
int Fraction::lcd(int a, int b) {
    // TODO: Implement logic for LCD
}

// Function to calculate Least Common Multiple (LCM)
int Fraction::lcm(int a, int b) {
    // TODO: Implement logic for LCM
}

// Additional overloaded operators (you should implement these)
// Overloaded subtraction operator
Fraction Fraction::operator-(const Fraction& other) {
    // TODO: Implement the subtraction logic
}

// Overloaded multiplication operator
Fraction Fraction::operator*(const Fraction& other) {
    // TODO: Implement the multiplication logic
}

// Overloaded division operator
Fraction Fraction::operator/(const Fraction& other) {
    // TODO: Implement the division logic
}

int main() {
    // TODO: Design an input file that matches the format x/y operator i/j
    // Example: 1/2 + 3/4 should output 5/4 or 1 and 1/4, depending on how you format the output.

    // Example usage (students should implement actual logic)
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);

    Fraction result = frac1 + frac2;  // This should call the overloaded + operator
    std::cout << result << std::endl; // This will print the result

    return 0;
}
