#include<iostream>
#include<stdlib.h>

#define RESET_COLOR "\e[m"
#define GREEN  "\e[32m"

using namespace std;
template<typename T>
class polynomial
{
public:
    template<typename U>
    void mf(const U& u) 
    {
    
    };
    int* coeff, degree; /* variable declaration */
    int get_data(); /*function declaration */
    int display(int* coeff, int degree);
    void addition(polynomial P1, polynomial P2);
    void substraction(polynomial P1, polynomial P2);
    void multiplication(polynomial P1, polynomial P2);
};

int polynomial<int>::display(int* coeff, int degree) {
    int i, j;
    for (i = degree; i >= 0; i--) {
        cout << coeff[i] << "x^" << i;
        if ((i - 1) != -1)
            cout << "+";
    }
    cout << "\n";
    return 0;
}

int polynomial<int>::get_data() {
    int i;
    cout << "Enter Degree Of Polynomial:";
    cin >> degree;
    coeff = new int[degree + 1];
    for (i = degree; i >= 0; i--) {
        cout << "Enter coefficient of x^" << i << ":";
        cin >> coeff[i];
    }

    return 0;
}

void polynomial<int>::addition(polynomial P1, polynomial P2) {
    int max, i;
    max = (P1.degree > P2.degree) ? P1.degree : P2.degree;
    int* add = new int[max + 1];
    if (P1.degree == P2.degree) {
        for (i = P1.degree; i >= 0; i--)
            add[i] = P1.coeff[i] + P2.coeff[i];
    }

    if (P1.degree > P2.degree) {
        for (i = P1.degree; i > P2.degree; i--)
            add[i] = P1.coeff[i];
        for (i = P2.degree; i >= 0; i--)
            add[i] = P1.coeff[i] + P2.coeff[i];
    }

    if (P1.degree < P2.degree) {
        for (i = P2.degree; i > P1.degree; i--)
            add[i] = P2.coeff[i];
        for (i = P1.degree; i >= 0; i--)
            add[i] = P1.coeff[i] + P2.coeff[i];
    }
    cout << "\nAddition:";
    display(add, max);
    cout << "\n";
}

void polynomial<int>::substraction(polynomial P1, polynomial P2) {
    int max, i;
    max = (P1.degree > P2.degree) ? P1.degree : P2.degree;
    int* sub = new int[max + 1];
    if (P1.degree == P2.degree) {
        for (i = P1.degree; i >= 0; i--)
            sub[i] = P1.coeff[i] - P2.coeff[i];
    }

    if (P1.degree > P2.degree) {
        for (i = P1.degree; i > P2.degree; i--)
            sub[i] = P1.coeff[i];
        for (i = P2.degree; i >= 0; i--)
            sub[i] = P1.coeff[i] - P2.coeff[i];
    }

    if (P1.degree < P2.degree) {
        for (i = P2.degree; i > P1.degree; i--)
            sub[i] = -P2.coeff[i];
        for (i = P1.degree; i >= 0; i--)
            sub[i] = P1.coeff[i] - P2.coeff[i];
    }
    cout << "\nSubstraction:";
    display(sub, max);
    cout << "\n";
}

void polynomial<int>::multiplication(polynomial P1, polynomial P2) {
    int i, j, max;
    max = P1.degree + P2.degree;
    int* mul = new int[max + 1];

    for (i = P1.degree; i >= 0; i--)
        for (j = P2.degree; j >= 0; j--)
            mul[i + j] = P1.coeff[i] * P2.coeff[j];
    cout << "\nMultiplication:";
    display(mul, max);
}



int main() {
    int choice;
    polynomial<int> P1, P2, P3;
    cout << GREEN << "Instruction:- \nExample:-\nP(x)=5x^3+3x^1\nEnter the Polynomial like\nP(x)=5x^3+0x^2+3x^1+0x^0\n" << RESET_COLOR;
    cout << "Enter Polynomial1:-" << endl;
    P1.get_data();
    cout << "Enter Polynomial2:-" << endl;
    P2.get_data();

    while (1) {
        cout << "\n****** Menu Selection ******" << endl;
        cout << "1: Addition\n2: Substraction\n3: Multiplication\n0: Exit" << endl;
        cout << "Enter ypur choice:";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << GREEN << "\n--------------- Addition ---------------\n";
            cout << "Polynomial1:";
            P1.display(P1.coeff, P1.degree);
            cout << "Polynomial2:";
            P2.display(P2.coeff, P2.degree);
            P3.addition(P1, P2);
            cout << "----------------------------------------\n" << RESET_COLOR;
            break;
        case 2:

            cout << GREEN << "\n------------- Substraction -------------\n";
            cout << "Polynomial1:";
            P1.display(P1.coeff, P1.degree);
            cout << "Polynomial2:";
            P2.display(P2.coeff, P2.degree);
            P3.substraction(P1, P2);
            cout << "----------------------------------------\n" << RESET_COLOR;
            break;
        case 3:
            cout << GREEN << "\n----------- Multiplication -------------\n";
            cout << "Polynomial1:";
            P1.display(P1.coeff, P1.degree);
            cout << "Polynomial2:";
            P2.display(P2.coeff, P2.degree);
            P3.multiplication(P1, P2);
            cout << "----------------------------------------\n" << RESET_COLOR;
            break;
        case 0:
            cout << "Good Bye...!!!" << endl;
            exit(0);
        }
    }
    return 0;
}
