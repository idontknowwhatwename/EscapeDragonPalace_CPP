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
	
	virtual const vector<string>& GetSpriteFrame(int frame) const = 0;

	bool GetIsHeld() const;
	void SetIsHeld(bool val);
	float GetX() const;
	float GetY() const;
	int GetWidth() const;
	int GetHeight() const;
	ItemType GetItemType() const;
	E_MapStatus GetMapStatus() const;

	virtual ~Item();              // 소멸자 (가상)
};

// 해초 클래스
class SEAWEED : public Item
{
protected:
	vector<vector<string>> sprite = {
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

	virtual const vector<string>& GetSpriteFrame(int frame) const override;

	virtual ~SEAWEED();
};

// 공기방울 클래스
class BUBBLES : public Item
{
protected:
	vector<vector<string>> sprite = {
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

	virtual const vector<string>& GetSpriteFrame(int frame) const override;

	virtual ~BUBBLES();
};

// 조개 클래스
class CLAM : public Item
{
protected:
	vector<vector<string>> sprite = { { "(\\ /)" } }; // 조개 모양

public:
	CLAM(float p_x, float p_y, bool p_isHeld, E_MapStatus p_mapStatus);

	virtual const vector<string>& GetSpriteFrame(int frame) const override;

	virtual ~CLAM();
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
	ItemManager();

	static ItemManager* GetInstance();
	static void ReleaseInstance();  // 싱글톤 해제 함수

	void InitItems();                     // 아이템 초기화
	void ResetItems(E_MapStatus map);     // 해당 맵 아이템만 리셋
	void UpdateFrame();                   // 모션 프레임 계산
	void DrawItems(E_MapStatus currentMap);// 현재 맵 아이템만 그리기

	// Getters and Setters
	int GetFrame() const;
	void SetFrame(int val);
	clock_t GetLastFrameTime() const;
	void SetLastFrameTime(clock_t val);
	int GetFrameDelay() const;

	~ItemManager();
};