#include "weapon.h"
#include "data.h"


int selectedIndex = 0;   // 현재 선택 중인 무기 인덱스
bool weaponChosen = false;  // Enter로 선택했는지 여부

Weapon::Weapon()
{
    name = "";
    attack = 0;
    attackSpeed = 0;
	sprite = "";
}

LongSword::LongSword()
{
    name = "LongSword";
    attack = 2;
    attackSpeed = 2;
}

ShortSword::ShortSword()
{
    name = "ShortSword";
    attack = 1;
    attackSpeed = 3;
}

Spear::Spear()
{
    name = "Spear";
    attack = 3;
    attackSpeed = 1;
}

void Weapon::InitWeapon()
{
    vector<Weapon*> weaponList = {
        new LongSword,
        new ShortSword,
        new Spear
    };
}

// 무기출력
void Weapon::DrawWeapon(vector<Weapon*> w, int i, int isSelected)
{
    int baseX = 6 + (i * 28);


    _DrawText(28, 18, const_cast < char*>("Enter 키를 눌러 무기 선택"));

    /*
    if (isSelected)
        _SetColor(E_Yellow); // 노란색 (현재 선택중인 무기)
    else
        _SetColor(E_White); // 흰색 (기본)
    */

    sprintf_s(buffer, const_cast <char*>("종류: "), w[selectedIndex]->name);
    _DrawText(baseX, 10, buffer);

    sprintf_s(buffer, const_cast < char*>("공격력: %d"), w[selectedIndex]->attack);
    _DrawText(baseX, 11, buffer);

    sprintf_s(buffer, const_cast < char*>("공격속도: %d"), w[selectedIndex]->attackSpeed);
    _DrawText(baseX, 12, buffer);

    sprintf_s(buffer, const_cast < char*>("형태: "), w[selectedIndex]->sprite);
    _DrawText(baseX, 13, buffer);

    //_SetColor(E_White); // 색상 초기화
}

void Weapon::SelectWeapon()
{
    // 무기 선택 안했을 때
    while (!weaponChosen)
    {
        // 키 입력 받기
        if (_kbhit())
        {
            char key = _getch();

            // A or a 키를 누르면 왼쪽 무기 설명으로 이동
            if (key == 'a' || key == 'A')
            {
                selectedIndex = (selectedIndex - 1 + NUMWEAPON) % NUMWEAPON;
            }
            // D or d 키를 누르면 오른쪽 무기 설명으로 이동
            else if (key == 'd' || key == 'D')
            {
                selectedIndex = (selectedIndex + 1) % NUMWEAPON;
            }
            // Enter 키를 누르면 무기 선택
            else if (key == '\r')
            {
                weaponChosen = true; // 무기 선택 여부 true로 변경
            }
        }

        _Invalidate();
    }
}

// 선택된 무기 인덱스 가져오기
int Weapon::GetSelectedIndex()
{
	return selectedIndex;
}

// 무기 선택 여부 가져오기
bool Weapon::GetWeaponChosen()
{
    return weaponChosen;
}

// 무기 선택 여부 세팅
void Weapon::SetWeaponChosen(bool src)
{
    weaponChosen = src;
}