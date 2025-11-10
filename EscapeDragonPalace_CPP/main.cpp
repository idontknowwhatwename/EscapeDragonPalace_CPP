#include "init.h"
#include "data.h"
#include "monster.h"
#include "MapManager.h"
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

// 그리기 함수
void Draw()
{

}

int main()
{
	cout << "Hello World" << endl;

	return 0;
}