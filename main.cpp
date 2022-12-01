#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

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
                sum2 = sum2 + x / (i + j);
            }
            sum1 = sum1 + sum2;
        }

        result = sum1;

    }

    return result;

}

int main() {
    
    double a, b, n, step;

    do {

        cout << "Please input 'a' and 'b' which are the range of 'x'. Remember! 'b' must be greater than 'a'" << endl;
        cout << "a: ";

        while(!(cin >> a)) {         // enter loop scope if "cin >> a" fails
            if(cin.eof()) return -1;      // return if the stream was closed
            cin.clear();                  // clear the stream state

            // ignore everything until a newline char is found
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Icorrect data! Please try again." << endl;
            cout << "a: ";
        }

        cout << "b: ";

        while(!(cin >> b)) {         // enter loop scope if "cin >> b" fails
            if(cin.eof()) return -1;      // return if the stream was closed
            cin.clear();                  // clear the stream state

            // ignore everything until a newline char is found
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Icorrect data! Please try again." << endl;
            cout << "b: ";
        }

    } while(a > b);

    do {

        cout << "Please input 'n'. Warning! 'n' must be greater than 2." << endl;
        cout << "n: ";

        while(!(cin >> n)) {         // enter loop scope if "cin >> n" fails
            if(cin.eof()) return -1;      // return if the stream was closed
            cin.clear();                  // clear the stream state

            // ignore everything until a newline char is found
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Icorrect data! Please try again." << endl;
            cout << "n: ";
        }

    } while(n < 2 || !(n == (int)n));

    do {

        cout << "Please input step of this program. Remember! 'step' must be positive'." << endl;
        cout << "step: ";

        while(!(cin >> step)) {         // enter loop scope if "cin >> step" fails
            if(cin.eof()) return -1;      // return if the stream was closed
            cin.clear();                  // clear the stream state

            // ignore everything until a newline char is found
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Icorrect data! Please try again." << endl;
            cout << "step: ";
        }

    } while(step <= 0);
    
    for(a; a <= b; a = a + step) {
        cout << "x = " << a << ", y = ";
        cout << formula( a, n) << endl;
    }

    return 0;

}