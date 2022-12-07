#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void checkAandB(double &a, double &b) {

    cout << "Please input 'a' and 'b' which are the range of 'x'. Remember! 'b' must be greater than 'a'" << endl;
    cout << "a: ";

    if(!(cin >> a)) {
        throw "Error! Incorrect data!";
    }

    cout << "b: ";

    if(!(cin >> b)) {
        throw "Error! Incorrect data!";
    }

    if(a > b) {
        throw "Error! 'a' cannot be greater than 'b'.";
    }

}

void checkN(double &n) {

    cout << "Please input 'n'. Warning! 'n' must be greater than 2." << endl;
    cout << "n: ";

    if(!(cin >> n)) {
        throw "Error! Incorrect data!";
    }

    if(n < 2) {
        throw "Error! 'n' cannot be less than 2.";
    }

    if(!(n == (int)n)) {
        throw "Error! 'n' must be integer.";
    }
}

void checkStep(double &step) {

    cout << "Please input step of this program. Remember! 'step' must be positive'." << endl;
    cout << "step: ";

    if(!(cin >> step)) {
        throw "Error! Incorrect data!";
    }

    if(step <= 0) {
        throw "Error! 'step' must be greater than 0.";
    }
}

double formula(double x, int n) {

    double result;

    if(x <= 0) {

        int mlt = 1;

        for(int i = 1; i <= n - 1; i++) {
            mlt *= pow(i, 2) + i;
        }

        result = mlt;

    } else {

        double sum1 = 0;

        for(double i = 1; i <= n - 1; i++) {
            double sum2 = 0;
            for(double j = 0; j <= n - 1; j++) {
                if(i + j == 0) {
                    throw "Error! Division by zero.";
                }
                sum2 = sum2 + x / (i + j);
            }
            sum1 = sum1 + sum2;
        }

        result = sum1;

    }

    return result;

}

void range(double &a, double &b, double n, double step) {
    for(a; a <= b; a = a + step) {
        cout << "x = " << a << ", y = " << formula( a, n)<< endl;
    }
}

int main() {
    
    double a, b, n, step;

    try {
        checkAandB(a, b);
        checkN(n);
        checkStep(step);
        range(a, b, n, step);
    }
    catch(const char* message) {
        cout << message << endl;
    } catch(...) {
        cout << "Unknown error!" << endl;
    }

    return 0;

}