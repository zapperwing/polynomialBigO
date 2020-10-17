#include <iostream>
#include <vector>
#include <string>

using namespace std;

string RemoveSpaces (string userPolynomial) {
    int i;
    string newPolynomial;
    for (i=0; i<userPolynomial.size(); ++i) {
        if (userPolynomial.at(i) != ' ') {
            newPolynomial.push_back(userPolynomial.at(i));
        }
    }
    return newPolynomial;
}

string GetNextNumber(string polynomial, int current) {
    string numbers = "";
    int i;

    for (i=current; i<polynomial.size() && isdigit(polynomial.at(i)) ; ++i){

        numbers.push_back(polynomial.at(i));

    }
    return numbers;
}

bool isNumber(string polynomial) {
    for(int i=0; i<polynomial.size(); ++i) {
        if (isdigit(polynomial.at(i))==false) {
            return false;
        }
    }
    return true;
}

bool CheckValidity(string userPolynomial) {
        for (int i=0; i<userPolynomial.size(); ++i) {
            if (userPolynomial.at(i) == '-' || userPolynomial.at(i) == ')' || userPolynomial.at(i) == '(') {
                return false;
            }
        }
        for (int i=0; i<userPolynomial.size(); ++i) {
            if (userPolynomial.at(i) == '^') {
                return isNumber(GetNextNumber(userPolynomial, i+1));
            }
        }
    return true;
}

void CalcBigO(string userPolynomial) {
    int i;
    int numberAsInt;
    vector<int> exponents;


    for (i=0; i<userPolynomial.size(); ++i) {
        if (userPolynomial.at(i) == '^') {
            //exponents.push_back(GetNextNumber(userPolynomial, i+1));
            numberAsInt = stoi(GetNextNumber(userPolynomial, i+1));
            exponents.push_back(numberAsInt);

        }
    }


   int max = exponents.at(0);
    for (i=0; i<exponents.size(); ++i) {
        if (exponents.at(i) > max) {
            max = exponents.at(i);
        }
    }

    cout << "n^" << max << endl;


}



int main() {
    string userPolynomial;
    string polynomialWithSpaces;

    cout << "Enter your polynomial that does not include negation or parentheses:" << endl;
    getline(cin,polynomialWithSpaces);

    userPolynomial = RemoveSpaces(polynomialWithSpaces);

    if (CheckValidity(userPolynomial)==true) {
        cout << polynomialWithSpaces << " is a valid polynomial, the big-O notation is: ";
        CalcBigO(userPolynomial);
    }
    else {
        cout << polynomialWithSpaces << " is not a valid polynomial." << endl;
    }
    

}

