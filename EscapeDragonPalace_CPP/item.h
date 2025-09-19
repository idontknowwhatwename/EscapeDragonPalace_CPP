#pragma once
#include "init.h"

// 아이템 종류 열거형
typedef enum
{
	E_ITEM_SPEED,   // 속도 증가
	E_ITEM_LIFE,    // 체력 증가
	E_ITEM_DEBUFF,  // 속도 및 체력 감소 (디버프)
} ItemType;

// 아이템 클래스
class Item
{
public:
	Item(const ItemType p_type, const float p_x, const float p_y, bool p_isHeld, const float p_width, const float p_height);
	static vector<Item> InitItem();

protected:
	ItemType type;          // 아이템 종류
	float x, y;             // 아이템 위치 좌표
	bool isHeld;            // 플레이어 소지 여부
	float width, height;    // 아이템 너비, 높이
	MapStatus mapStatus;    // 아이템이 등장하는 맵
};


