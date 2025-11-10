#include "weapon.h"
#include "data.h"

// 생성자
Weapon::Weapon(const string p_name, const vector<string>& p_sprite, const int p_attack, const int p_attackSpeed)
{
	name = p_name;
	sprite = p_sprite;
	attack = p_attack;
	attackSpeed = p_attackSpeed;
}

// 무기 초기화
vector<Weapon> Weapon::InitWeapon()
{
	vector<string> longSword = { "--|====>" };
	vector<string> shortSword = { "-|=>" };
	vector<string> spear = { "------>" };

	vector<Weapon> weaponList = { Weapon("Long Sword", longSword, 2, 2),
					Weapon("Short Sword", shortSword, 1, 3), Weapon("Spear", spear, 3, 1) };

	return weaponList;

}