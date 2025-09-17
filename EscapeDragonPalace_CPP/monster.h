#pragma once

// 몬스터 클래스
class Monster
{
protected:
	int HP;						// 체력
	int attack;					// 공격력
	float speed;				// 이동 속도
	bool isAlive;				// 생존 여부
	bool isDamaged;				// 피격 당한 상태
	unsigned long lastHitTime;	// 마지막 피격 시간
};

// 몬스터 타입 열거형
enum MonsterType
{
	E_MONSTER_FISH,
	E_MONSTER_CRAB,
	E_MONSTER_CLAM,
	E_MONSTER_TURTLE,
	E_MONSTER_SMALLFISH,
	E_MONSTER_TYPE_COUNT
};