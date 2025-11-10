#pragma once
#include "monster.h"

enum CrabStatus
{
	E_NONE,		// 기본 상태
	E_ATTACK,	// 공격
};

class Crab : Monster
{
	// 스킬
	bool isAttack;		// 스킬 사용 중인지 여부
	int attackCnt;		// 스킬 구현 횟수
	int attack;			// 스킬 공격력
	long coolTime;		// 스킬 쿨타임 (ms)

	// 일반
	float startPosX;	// 시작 x 위치
	CrabStatus attackStatus;	// 몬스터 공격 상태 (그래픽)

public: 
	virtual void Init() override;					// 초기화
	virtual void Reset() override;					// 리셋
	virtual void Update() override;					// 업데이트
	virtual void Draw() override;					// 그리기
	virtual void MonsterHitPlayer() override;		// 몬스터 피격 처리 함수
	virtual void PlayerHitMonster() override;		// 플레이어 -> 몬스터 피격 처리 함수
};