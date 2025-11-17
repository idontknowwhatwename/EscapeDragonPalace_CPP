#pragma once
#include "init.h"
#include "MapManager.h"

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
	E_MapStatus mapStatus; // 아이템이 존재하는 맵

public:
	Item(); // 기본 생성자

	// 함수
	void InitItem();        // 아이템 초기화
	void DrawItem();        // 아이템 그리기
	void ResetItem();       // 아이템 isHeld false로 초기화
	void ItemFrameDelay();  // 아이템 모션 효과

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
	SEAWEED(float p_x, float p_y, bool p_isHeld, E_MapStatus p_mapStatus);
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
	BUBBLES(float p_x, float p_y, bool p_isHeld, E_MapStatus p_mapStatus);
	virtual ~BUBBLES() {};
};

// 조개 클래스
class CLAM : public Item
{
protected:
	const string sprite = "(\\ /)"; // 조개 모양

public:
	CLAM(float p_x, float p_y, bool p_isHeld, E_MapStatus p_mapStatus);
	virtual ~CLAM() {};
};
