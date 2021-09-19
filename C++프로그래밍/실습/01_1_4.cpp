#include<iostream>

int main(void)
{
	int num;

	while (1)
	{
       std::cout << "input sale money: ";
	   std::cin >> num;
	   if (num == -1)
	   {
		   break;
	   }
	   else
	   {
		   int result;
		   result = 50 + num * 0.12;
		   std::cout << "month salary is " << result << std::endl;
	   }
	}
	std::cout << "programming end\n";
}
//20191224