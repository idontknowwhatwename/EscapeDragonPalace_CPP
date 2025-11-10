#pragma once
#include "init.h"

#define NUMWEAPON 3 // 무기 종류 갯수

char buffer[50];				// 무기 정보 출력용 버퍼


class Weapon
{
protected:
    string name;                // 무기 이름
    int attack;                 // 공격력
    int attackSpeed;            // 공격속도
	string sprite;              // 무기 모양

public:
    Weapon();

    // 함수
    void SelectWeapon();		// 무기 선택 함수
    int GetSelectedIndex();		// 선택된 무기 인덱스 반환 함수
    bool GetWeaponChosen();		// 무기 선택 여부 반환 함수
    void SetWeaponChosen(bool src);		// 무기 선택 여부 설정 함수
    void InitWeapon();	// 무기 초기화 함수
    void DrawWeapon(vector<Weapon*> w, int i, int isSelected); // 무기 정보 출력 함수

    virtual ~Weapon() {};
};

class LongSword : public Weapon
{
protected:
    string sprite = "--|====>";
public:
    LongSword();
	virtual ~LongSword() {};
};

class ShortSword : public Weapon
{
protected:
	string sprite = "-|=>";
public:
	ShortSword();
	virtual ~ShortSword() {};
};

class Spear : public Weapon
{
protected:
    string sprite = "------>";
public:
	Spear();
	virtual ~Spear() {};
};