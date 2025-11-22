#include "weapon.h"
#include "data.h"

WeaponManager* WeaponManager::weapon_Instance = nullptr;

WeaponManager* WeaponManager::GetInstance()
{
    if (WeaponManager::weapon_Instance == nullptr)
    {
        WeaponManager::weapon_Instance = new WeaponManager();
    }

    return WeaponManager::weapon_Instance;
}

void WeaponManager::ReleaseInstance()
{
    if (weapon_Instance != nullptr)
    {
        delete weapon_Instance;
        weapon_Instance = nullptr;
    }
}

// weaponManager 생성자
WeaponManager::WeaponManager()
    : selectedIndex(0), weaponChosen(false)
{
}

// weaponManager 소멸자
WeaponManager::~WeaponManager()
{
    for (int i = 0; i < weaponList.size(); i++)
    {
        delete weaponList[i];
    }
    weaponList.clear();
}

// 무기 초기화
void WeaponManager::InitWeapon()
{
    weaponList.push_back(new LongSword());
    weaponList.push_back(new ShortSword());
    weaponList.push_back(new Spear());
}

// 무기 리스트 접근
const vector<Weapon*>& WeaponManager::GetWeaponList() const
{
    return weaponList;
}

// 무기 선택 인덱스 getter setter
int WeaponManager::GetSelectedIndex() const { return selectedIndex; }
void WeaponManager::SetSelectedIndex(int idx) { selectedIndex = idx; }

// 무기 선택 여부 getter setter
bool WeaponManager::IsWeaponChosen() const { return weaponChosen; }
void WeaponManager::SetWeaponChosen(bool val) { weaponChosen = val; }

Weapon::Weapon()
{
    name = "";
    attack = 0;
    attackSpeed = 0;
	sprite = "";
}

string Weapon::GetName() const { return name; }
int Weapon::GetAttack() const { return attack; }
int Weapon::GetAttackSpeed() const { return attackSpeed; }
string Weapon::GetSprite() const { return sprite; };

Weapon::~Weapon() {}

// 장검
LongSword::LongSword()
{
    name = "LongSword";
    attack = 2;
    attackSpeed = 2;
    sprite = "--|====>";
}

LongSword::~LongSword() {}

// 단검
ShortSword::ShortSword()
{
    name = "ShortSword";
    attack = 1;
    attackSpeed = 3;
    sprite = "-|=>";
}

ShortSword::~ShortSword() {}

// 창
Spear::Spear()
{
    name = "Spear";
    attack = 3;
    attackSpeed = 1;
	sprite = "------>";
}

Spear::~Spear() {}


// 무기출력
void WeaponManager::DrawWeapons()
{

    for (int i = 0; i < NUMWEAPON; i++)
    {
        char buffer[50];
        int baseX = 6 + (i * 28);


        _DrawText(28, 18, const_cast <char*>("Enter 키를 눌러 무기 선택"));

        if (selectedIndex == i)
            _SetColor(E_Yellow); // 노란색 (현재 선택중인 무기)
        else
            _SetColor(E_White); // 흰색 (기본)

        sprintf_s(buffer, sizeof(buffer), "종류: %s", weaponList[i]->GetName().c_str());
        _DrawText(baseX, 10, buffer);

        sprintf_s(buffer, sizeof(buffer), ("공격력: %d"), weaponList[i]->GetAttack());
        _DrawText(baseX, 11, buffer);

        sprintf_s(buffer, sizeof(buffer), ("공격속도: %d"), weaponList[i]->GetAttackSpeed());
        _DrawText(baseX, 12, buffer);

        sprintf_s(buffer, sizeof(buffer), ("형태: %s"), weaponList[i]->GetSprite());
        _DrawText(baseX, 13, buffer);

        _SetColor(E_White); // 색상 초기화
    }
}

// 무기 선택
void WeaponManager::SelectWeapon()
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