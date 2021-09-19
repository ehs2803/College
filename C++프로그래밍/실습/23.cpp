#include<iostream>
using namespace std;

class complex
{
private:
	double real;
	double imag;
public:
	complex()
	{
		real = 0;
		imag = 0;
	}
	complex(double a, double b)
	{
		real = a;
		imag = b;
	}
	complex add(complex& c)
	{
		complex temp;
		temp.real = this->real + c.real;
		temp.imag = this->imag + c.imag;

		return temp;
	}
	double getreal()
	{
		return real;
	}
	double getimag()
	{
		return imag;
	}
	void print()
	{
		cout << real << " + " << imag << "i" << endl;
	}
};

complex adder(complex& a, complex& b) //일반함수로 구현
{
	double real = a.getreal() + b.getreal();
	double imag = a.getimag() + b.getimag();
	complex temp(real, imag);

	return temp;
}

int main(void)
{
	complex x(2, 3), y(4, 6), z, k;

	cout << "first complex x: ";
	x.print();

	cout << "second complex y: ";
	y.print();

	z = x.add(y);
	k = adder(x, y);

	cout << "z = x + y = ";
	z.print();

	cout << "k = x + y = ";
	k.print();
}
//20200118