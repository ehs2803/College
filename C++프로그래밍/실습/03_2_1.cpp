#include<iostream>
using namespace std;

class calculator 
{
private:
	int numadd;
	int numsub;
	int nummul;
	int numdiv;
public:
	void number();
	double add(double num1, double num2);
	double sub(double num1, double num2);
	double mul(double num1, double num2);
	double div(double num1, double num2);
	void show();
};
void calculator::number()
{
	numadd = 0;
	numsub = 0;
	nummul = 0;
	numdiv = 0;
}
double calculator::add(double num1, double num2)
{
	numadd++;
	return num1 + num2;
}
double calculator::sub(double num1, double num2)
{
	numsub++;
	if (num1 >= num2)
	{
		return num1 - num2;
	}
	else
	{
		return num2 - num1;
	}
}
double calculator::mul(double num1, double num2)
{
	nummul++;
	return num1 * num2;
}
double calculator::div(double num1, double num2)
{
	numdiv++;
	if (num1 >= num2)
	{
		return num1 / num2;
	}
	else
	{
		return num2 / num1;
	}
}
void calculator::show()
{
	cout << "add: " << numadd << ' ';
	cout << "sub: " << numsub << ' ';
	cout << "mul: " << nummul << ' ';
	cout << "div: " << numdiv << ' ';
}

int main(void)
{
	calculator cal;
	cal.number();
	cout << "3.2 + 2.4 = " << cal.add(3.2, 2.4) << endl;
	cout << "3.5 - 1.5 = " << cal.sub(3.5, 1.5) << endl;
	cout << "4.9 * 1.2 = " << cal.mul(4.9, 1.2) << endl;
	cout << "3.5 / 1.7 = " << cal.div(3.5, 1.7) << endl;
	cal.show();
}
//20191231