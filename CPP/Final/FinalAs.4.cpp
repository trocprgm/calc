#include <iostream>

using namespace std;

class Number {
    public:
        void print() {
            cout << real << endl;
        }
        float real = 0;
        float operator + (Number a) {
            return real + a.real;
        }
};

class Complex : public Number {
    public:
        float imag = 0;
        float real = 0;
        void print() {
            cout << real << " " << imag << "i" << endl;
        }
        Complex() {}
        Complex(float r, float i) : real(r), imag(i) {
        }

        Complex operator + (Complex a) {
            Complex t(a.real + real, a.imag + imag);
            return t;
        }
        Complex operator - (Complex a) {
            Complex t(a.real - real, a.imag - imag);
            return t;
        }
};


int main() {
    Complex a(1,2);
    Complex b(2,3);
    Complex c;
    c = a + b;
    c.print();

    return 0;
}

