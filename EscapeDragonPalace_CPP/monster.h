#pragma once
#include "init.h"

// 몬스터 클래스
class Monster
{
public:
	// 생성자
	Monster();
	Monster(int HP, float speed);
	~Monster();	// 소멸자

protected:
	int HP;						// 체력
	float speed;				// 이동 속도
	bool isAlive;				// 생존 여부
	bool isDamaged;				// 피격 당한 상태
	unsigned long lastHitTime;	// 마지막 피격 시간
};

// 스킬 클래스
class MonsterSkill
{
	bool isAttack;		// 스킬 사용 중인지 여부
	int attackCnt;		// 스킬 구현 횟수
	int attack;			// 스킬 공격력
	long coolTime;		// 스킬 쿨타임 (ms)
};