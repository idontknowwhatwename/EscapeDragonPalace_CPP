#pragma once
#include "init.h"

// 아이템 종류 열거형
typedef enum
{
	E_ITEM_SPEED,   // 속도 증가
	E_ITEM_LIFE,    // 체력 증가
	E_ITEM_DEBUFF   // 속도 및 체력 감소
} ItemType;

// 기본 아이템 클래스
class Item
{
protected:
	float x, y;         // 아이템 좌표
	bool isHeld;        // 소지 여부
	float width, height; // 크기
	ItemType itemType;  // 아이템 종류

public:
	Item(); // 기본 생성자
	static vector<Item*> InitItem(); // 아이템 초기화
	virtual ~Item() {};              // 소멸자 (가상)
};

// 해초 클래스
class SEAWEED : public Item
{
protected:
	const string sprite[2][3] = {
		{
			" )) (( ((",
			"((   )) ))",
			" )) (( (("
		},
		{
			"((  )) ))",
			" ))(( ((",
			"((  )) ))"
		}
	};

public:
	SEAWEED(float p_x, float p_y, bool p_isHeld);
	virtual ~SEAWEED() {};
};

// 공기방울 클래스
class BUBBLES : public Item
{
protected:
	const string sprite[2][2] = {
		{
			"o .o",
			".o o"
		},
		{
			".o o",
			"o .o"
		}
	};

public:
	BUBBLES(float p_x, float p_y, bool p_isHeld);
	virtual ~BUBBLES() {};
};

// 조개 클래스
class CLAM : public Item
{
protected:
	const string sprite = "(\\ /)"; // 조개 모양

public:
	CLAM(float p_x, float p_y, bool p_isHeld);
	virtual ~CLAM() {};
};
