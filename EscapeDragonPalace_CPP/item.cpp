#include "item.h"
#include "data.h"

// 기본 생성자
Item::Item()
{
	x = 0;
	y = 0;
	isHeld = false;
	width = 0;
	height = 0;
	itemType = E_ITEM_SPEED; // 기본값
}

// 해초 생성자
SEAWEED::SEAWEED(float p_x, float p_y, bool p_isHeld)
{
	x = p_x;
	y = p_y;
	isHeld = p_isHeld;
	width = 11;
	height = 3;
	itemType = E_ITEM_LIFE;
}

// 공기방울 생성자
BUBBLES::BUBBLES(float p_x, float p_y, bool p_isHeld)
{
	x = p_x;
	y = p_y;
	isHeld = p_isHeld;
	width = 5;
	height = 2;
	itemType = E_ITEM_SPEED;
}

// 조개 생성자
CLAM::CLAM(float p_x, float p_y, bool p_isHeld)
{
	x = p_x;
	y = p_y;
	isHeld = p_isHeld;
	width = 6;
	height = 1;
	itemType = E_ITEM_DEBUFF;
}

// 아이템 초기화 함수
vector<Item*> Item::InitItem()
{
	vector<Item*> itemList = {
		new SEAWEED(10, 5, false),
		new BUBBLES(20, 3, false),
		new CLAM(30, 2, false)
	};
	return itemList;
}
