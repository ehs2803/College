#include<iostream>
using namespace std;

class Tower {
	int height;
public:
	Tower();
	Tower(int n);
	int getHeight();
	~Tower();
};

Tower::Tower() :Tower(1) {}

Tower::Tower(int n) : height(n) { }

Tower::~Tower() {
	cout << "높이는 " << getHeight() << "미터" << endl;
}

int Tower::getHeight() {
	return height;
}

int main(void) {
	cout << "2019305059 이현수" << endl<<endl;
	Tower myTower;
	Tower seoulTower(100);
}