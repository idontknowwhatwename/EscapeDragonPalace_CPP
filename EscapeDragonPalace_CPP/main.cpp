#include "init.h"
#include "data.h"
#include "Rabbit.h"
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

// 업데이트 함수
void Update()
{
	Rabbit rabbit;
	rabbit.Update();
}

// 그리기 함수
void Draw()
{
	Rabbit rabbit;
	rabbit.Draw();
}

int main()
{
	_BeginWindow();

	while (true)
	{
		Update();
		_Invalidate();
	}

	_EndWindow();
	return 0;
}