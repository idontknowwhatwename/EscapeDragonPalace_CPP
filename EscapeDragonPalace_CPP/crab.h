#pragma once
#include "monster.h"

enum CrabStatus
{
	E_NONE,		// 기본 상태
	E_ATTACK,	// 공격
};

class Crab : Monster
{
	Skill skill;	// 스킬 구현 (1개)

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