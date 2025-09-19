#pragma once
#include "init.h"

// 무기 클래스
class Weapon
{
public:
	Weapon(const string name, const vector<string>& sprite, const int attack, const int attackSpeed);
	static vector<Weapon> InitWeapon();

protected:
	string name;			// 무기 이름
	vector<string> sprite;	// 무기 스프라이트
	int attack;             // 공격력
	int attackSpeed;        // 공격속도
};

string buffer[50];				// 무기 정보 출력용 버퍼