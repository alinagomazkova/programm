#include <iostream>
#include <cmath>
using namespace std;

void menu();
void sum();
void diff();
void prod();
void quot();
void power();
void matrix();
int number(double a) { //cin >> a; 
    if (cin.fail()) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "It is not a number!" << endl;
        return 0;
    }
    else {
        cout << "Good job!" << endl;
        return 1;
    }
}
int main() {
    char choice;
    do {
        menu();
        cout << "Do u want to continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}

void menu() {
    cout << "Calculator created with love <3\n\n";
    cout << "Menu\n";
    cout << "1. Addition +\n"; //сложение
    cout << "2. Subtraction - \n"; //вычитание
    cout << "3. Multiplication *\n"; //умножение
    cout << "4. Division /\n";//деление
    cout << "5. Power ^\n";
    // cout << "6. Square root\n";
    // cout << "7. Factorial\n"; 
    cout << "6. Matrix [][]\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        sum();
        break;
    case 2:
        diff();
        break;
    case 3:
        prod();
        break;
    case 4:
        quot();
        break;
    case 5:
        power();
        break;
    case 6:
        matrix();
        break;
    default:
        cout << "Invalid choice\n";
    }
}

void sum() {
    double num1, num2;
    cout << "Enter number to add: (a=) ";
    cin >> num1;
    do {
        if (number(num1) == 0) {
            cout << "enter again" << endl;
            cin >> num1;
        }
    } while (number(num1) == 0);
    cout << "Enter number to add: (b=) ";
    cin >> num2;
    do {
        if (number(num2) == 0) {
            cout << "enter again" << endl;
            cin >> num2;
        }
    } while (number(num2) == 0);
    cout << "The sum is (a+b)=" <<(num1 + num2);
}

void diff() {
    double num1, num2;
    cout << "Enter number to add: (a=) ";
    cin >> num1;
    do {
        if (number(num1) == 0) {
            cout << "enter again" << endl;
            cin >> num1;
        }
    } while (number(num1) == 0);
    cout << "Enter number to add : (b=) ";
    cin >> num2;
    do {
        if (number(num2) == 0) {
            cout << "enter again" << endl;
            cin >> num2;
        }
    } while (number(num2) == 0);
    cout << "The difference is " << num1 - num2 << endl;
}

void prod() {
    double num1, num2;
    cout << "Enter number to add : (a=) ";
    cin >> num1;
    do {
        if (number(num1) == 0) {
            cout << "enter again" << endl;
            cin >> num1;
        }
    } while (number(num1) == 0);
    cout << "Enter number to add : (b=) ";
    cin >> num2;
    do {
        if (number(num2) == 0) {
            cout << "enter again" << endl;
            cin >> num2;
        }
    } while (number(num2) == 0);
    cout << "The product is " << num1 * num2 << endl;
}

void quot() {
    double num1, num2;
    cout << "Enter number to add : (a=) ";
    cin >> num1;
    do {
        if (number(num1) == 0) {
            cout << "enter again" << endl;
            cin >> num1;
        }
    } while (number(num1) == 0);
    cout << "Enter number to add : (b=) ";
    cin >> num2;
    do {
        if (number(num2) == 0) {
            cout << "enter again" << endl;
            cin >> num2;
        }
    } while (number(num2) == 0);
    if (num2 == 0) {
        cout << "Error: division by 0\n";
    }
    else {
        cout << "The quotient is " << num1 / num2 << endl;
    }
}

void power() {
    double num1, num2;
    cout << "Enter number to add : (a=) ";
    cin >> num1;
    do {
        if (number(num1) == 0) {
            cout << "enter again" << endl;
            cin >> num1;
        }
    } while (number(num1) == 0);
    cout << "Enter number to add : (b=) ";
    cin >> num2;
    do {
        if (number(num2) == 0) {
            cout << "enter again" << endl;
            cin >> num2;
        }
    } while (number(num2) == 0);
    cout << "The result is " << pow(num1, num2) << endl;
}

void matrix() {
    const int rows = 3;
    const int cols = 3;
    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];
    cout << "Enter the elements of the first matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix1[i][j];
        }
    }
    cout << "Enter the elements of the second matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix2[i][j];
        }
    }
    cout << "The sum of the matrices is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}