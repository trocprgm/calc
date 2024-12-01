#include <iostream>
#include <string>

using namespace std;

//Exam 2 Problem 4

class Complex 
{
    private:
        double real;
        double imag;
    public:
        Complex() {}
        Complex(double r, double i) : real(r), imag(i) {
            //cout << "You've made a complex number object!" << endl;
        }
        Complex operator + (const Complex& a) {
            return Complex((real + a.real),(imag + a.imag)); 
        }
        Complex operator - (const Complex& a) {
            return Complex((real - a.real),(imag - a.imag)); 
        }
        double getReal() {
            return real;
        }
        double getImag() {
            return imag;
        }
        void print() {
            cout << real << " " << imag << "i" << endl;
        }
        


};



int main() {
    Complex A(2,3);
    Complex B(4,-5);
    Complex C;
    Complex D;
    C = A + B;
    C.print();
    D = A-B;
    D.print();
    

    return 0;

}

