#pragma once
#include "init.h"

#define NUMWEAPON 3 // 무기 종류 갯수


class Weapon
{
protected:
    string name;                // 무기 이름
    int attack;                 // 공격력
    int attackSpeed;            // 공격속도
	string sprite;              // 무기 모양

public:
    Weapon();

    string GetName() const;
    int GetAttack() const;
    int GetAttackSpeed() const;
    string GetSprite() const;

    virtual ~Weapon();
};

class LongSword : public Weapon
{
public:
    LongSword();
	virtual ~LongSword();
};

class ShortSword : public Weapon
{
public:
	ShortSword();
	virtual ~ShortSword();
};

class Spear : public Weapon
{
public:
	Spear();
	virtual ~Spear();
};

class WeaponManager
{
private:
    static WeaponManager* weapon_Instance;

    vector<Weapon*> weaponList;   // 전체 아이템

    int selectedIndex = 0;   // 현재 선택 중인 무기 인덱스
    bool weaponChosen = false;  // Enter로 선택했는지 여부

public:
    WeaponManager();
    static WeaponManager* GetInstance();
    static void ReleaseInstance();  // 싱글톤 해제 함수

    void InitWeapon();                  // 무기 초기화 함수
    const vector<Weapon*>& GetWeaponList() const;

    int GetSelectedIndex() const;
    void SetSelectedIndex(int idx);

    bool IsWeaponChosen() const;
    void SetWeaponChosen(bool val);

    void SelectWeapon();
    void DrawWeapons();

    virtual ~WeaponManager();
};