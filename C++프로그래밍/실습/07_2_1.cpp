#include<iostream>
using namespace std;

class Car
{
private:
	int gas;
public:
	Car(int gas) :gas(gas)
	{ }
	int getgas()
	{
		return gas;
	}
};

class hybridcar :public Car
{
private:
	int electric;
public:
	hybridcar(int gas, int elec)
		:Car(gas), electric(elec)
	{ }
	int getele()
	{
		return electric;
	}
};

class hybridwater :public hybridcar
{
private:
	int water;
public:
	hybridwater(int gas, int ele, int water)
		:hybridcar(gas,ele), water(water)
	{ }
	void show()
	{
		cout << "ÀÜ¿© °¡¼Ö¸°: " << getgas() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << getele() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·® " << water << endl;
	}
};

int main(void)
{
	hybridwater a(79, 65, 35);
	a.show();
}
//20200109