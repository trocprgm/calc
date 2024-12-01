#include <iostream>

using namespace std;

class Number {
    public:
        virtual void print() =0;
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
            //Complex t(a.real - real, a.imag - imag);
            Complex t(real - a.real, imag - a.imag);
            return t;
        }
};


int main() {

    Complex A(2, 3);    
    Complex B(4, -5);   
    Complex C;   
    C = A + B;   
    C.print();
    Complex D;
    D = A - B;
    D.print();
    return 0;
}

