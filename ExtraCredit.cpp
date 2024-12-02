#include <iostream>
#include <iomanip> 
#include <string>

// Add this line to avoid repeating std::
using namespace std;

// Prototype for the extractNumeric function
double extractNumeric(const string& str);

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

double extractNumeric(const string& str) {
    if (str.empty() || str.length() > 20) {
        return -999999.99;
    }

    size_t i = 0;
    bool hasSign = false, hasDecimal = false, hasDigit = false;

    if (str[i] == '+' || str[i] == '-') { // check for plus or minus sign
        hasSign = true; 
        ++i;
    }

    for (; i < str.length(); ++i) { // parses
        char c = str[i];
        if (isdigit(c)) {
            hasDigit = true;
        } else if (c == '.') { // cant have multiple decimals
            if (hasDecimal) {
                return -999999.99; 
            }
            hasDecimal = true;
        } else {
            return -999999.99;
        }
    }

    if (!hasDigit) { // makes sure that at least that one digit is present
        return -999999.99;
    }

    try { // convert to double
        return stod(str);
    } catch (...) { // catch exceptions
        return -999999.99;
    }
}
