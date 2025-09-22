#pragma once

// 몬스터 클래스
class Monster
{
public: 
	// 생성자
	Monster();
	virtual ~Monster();
protected:
	int HP;						// 체력
	int attack;					// 공격력
	float speed;				// 이동 속도
	bool isAlive;				// 생존 여부
	bool isDamaged;				// 피격 당한 상태
	unsigned long lastHitTime;	// 마지막 피격 시간
public:
	// 함수
	virtual void UpdateMonster();	// 업데이트
	void DrawMonster();		// 그리기
	virtual bool MonsterHitPlayer();	// 몬스터 -> 플레이어 피격처리
	virtual bool PlayerHitMonster();	// 플레이어 -> 몬스터 공격처리
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