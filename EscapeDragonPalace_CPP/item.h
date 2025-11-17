#pragma once
#include "init.h"
#include "MapManager.h"

#define MAX_ITEM_COUNT 100      // 맵에 등장할 수 있는 아이템 인스턴스 수

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
	int width, height; // 크기
	ItemType itemType;  // 아이템 종류
	E_MapStatus mapStatus; // 아이템이 존재하는 맵

public:
	Item(); // 기본 생성자
	
	virtual const string* const* GetSprite() const = 0;

	bool GetIsHeld() const { return isHeld; }
	void SetIsHeld(bool val) { isHeld = val; }
	float GetX() const { return x; }
	float GetY() const { return y; }
	int GetWidth() const { return width; }
	int GetHeight() const { return height; }
	ItemType GetItemType() const { return itemType; }
	E_MapStatus GetMapStatus() const { return mapStatus; }

	virtual ~Item();              // 소멸자 (가상)
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

	const string* const* GetSprite() const override
	{
		return (const string* const*)sprite;
	}

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

	const string* const* GetSprite() const override
	{
		return (const string* const*)sprite;
	}

	virtual ~BUBBLES() {};
};

// 조개 클래스
class CLAM : public Item
{
protected:
	const string sprite[1][1] = { "(\\ /)" }; // 조개 모양

public:
	CLAM(float p_x, float p_y, bool p_isHeld, E_MapStatus p_mapStatus);

	const string* const* GetSprite() const override
	{
		return (const string* const*)sprite;
	}

	virtual ~CLAM() {};
};

class ItemManager
{
private:
	static ItemManager* item_Instance;

	vector<Item*> itemList;   // 전체 아이템
	int frame = 0;            // 모션 프레임
	clock_t lastFrameTime = 0;	// 마지막 프레임 시간
	const int frameDelay = 400;	 // 프레임 전환 딜레이 (밀리초)

public:
	ItemManager() {}

	static ItemManager* GetInstance();

	void InitItems();                     // 아이템 초기화
	void ResetItems(E_MapStatus map);     // 해당 맵 아이템만 리셋
	void UpdateFrame();                   // 모션 프레임 계산
	void DrawItems(E_MapStatus currentMap);// 현재 맵 아이템만 그리기

	// Getters and Setters
	int GetFrame() const { return frame; }
	void SetFrame(int val) { frame = val; }
	clock_t GetLastFrameTime() const { return lastFrameTime; }
	void SetLastFrameTime(clock_t val) { lastFrameTime = val; }
	int GetFrameDelay() const { return frameDelay; }

	~ItemManager();
};