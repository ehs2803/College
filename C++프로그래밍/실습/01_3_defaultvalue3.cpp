#include<iostream>
int box(int a, int b=1, int c=1);//int box(int a=1, int b=1, int c); ºÒ°¡´É

int main(void)
{
	std::cout << "[3, 3, 3] : " << box(3, 3, 3) << std::endl;
	std::cout << "[5, ,5, D] : " << box(5, 5) << std::endl;
	std::cout << "[7, D, D] : " << box(7) << std::endl;
	//std::cout << "[D, D, D] : " << box() << std::endl;
}

int box(int a, int b, int c)
{
	return a * b * c;
}
//20191224