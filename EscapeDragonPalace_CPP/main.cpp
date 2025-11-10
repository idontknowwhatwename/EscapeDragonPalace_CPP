#include "init.h"
#include "data.h"
#include "monster.h"
#include "mtg.h"

// 클래스 구현
float MyPoint::getX()
{
	return this->x;
}
void MyPoint::setX(float p_x)
{
	this->x = p_x;
}
float MyPoint::getY()
{
	return this->y;
}
void MyPoint::setY(float p_y)
{
	this->y = p_y;
}

// 전역변수
static int g_Key;	// 입력 키

int main()
{
	ifstream fin;		// 파일 입력 스트림 객체 생성
	string str[5];
	fin.open("map_jail.txt");
	if (!fin)
	{
		cout << "파일 열기 실패" << endl;
		return 0;
	}

	fin >> str[0];
	fin >> str[1];
	fin >> str[2];
	fin >> str[3];
	fin >> str[4];

	cout << str[0] << endl;
	cout << str[1] << endl;
	cout << str[2] << endl;
	cout << str[3] << endl;
	cout << str[4] << endl;

	fin.close();

	return 0;
}