#pragma once
#include "init.h"

// ���� Ŭ����
class Weapon
{
public:
	Weapon(const string name, const vector<string>& sprite, const int attack, const int attackSpeed);
	static vector<Weapon> InitWeapon();

protected:
	string name;			// ���� �̸�
	vector<string> sprite;	// ���� ��������Ʈ
	int attack;             // ���ݷ�
	int attackSpeed;        // ���ݼӵ�
};

string buffer[50];				// ���� ���� ��¿� ����