#include<iostream>
using namespace std;

#define IDLEN 20
#define MAXSPD 200
#define FUEL 2
#define ACC 10
#define BRK 10

struct car {
	char gameid[IDLEN];
	int fuel;
	int speed;
};

void showcarstate(const car& car)
{
	cout << "owner id: " << car.gameid << endl;
	cout << "fuel: " << car.fuel << "%" << endl;
	cout << "speed: " << car.speed << "km/s" << endl << endl;
}

void accel(car& car)
{
	if (car.fuel <= 0)
	{
		return;
	}
	else
	{
		car.fuel -= FUEL;
	}

	if (car.speed + ACC >= MAXSPD)
	{
		car.speed = MAXSPD;
		return;
	}

	car.speed += ACC;
}

void Break(car & car)
{
	if (car.speed < BRK)
	{
		car.speed = 0;
		return;
	}

	car.speed -= BRK;
}

int main(void)
{
	car run99 = { "run99",100,0 };
	accel(run99);
	accel(run99);
	showcarstate(run99);
	Break(run99);
	showcarstate(run99);

	car sped77 = { "sped77",100,0 };
	accel(sped77);
	Break(sped77);
	showcarstate(sped77);
}
//20191231