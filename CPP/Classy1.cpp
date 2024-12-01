#include <iostream>

using namespace std;

class Number {
    public:
        void print() {
            cout << real << endl;
        }
        float operator + (Number a) {
            return real + a.real;
        }
    private:
        float real = 0;
};

class Complex : public Number {
    public:
        void print() {
            cout << real << " " << imag << "i" << endl;
        }
        float getReal() {
            return real;
        }
        float getImag() {
            return imag;
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
    private:
        float imag = 0;
        float real = 0;
};


int main() {
    Complex a(1,2);
    Complex b(2,3);
    Complex c;
    c = a + b;
    c.print();

    return 0;
}

