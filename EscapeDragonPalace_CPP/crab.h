#pragma once
#include "data.h"
#include "monster.h"

// 메크로
#define CRAB_WIDTH 10   // 꽃게 너비
#define CRAB_HEIGHT 3   // 꽃게 높이
#define CRAB_CNT 17     // 꽃게 배열 수
#define CRAB_EYE 15     // 꽃게 인식 범위
#define CRAB_SPEED  0.5 // 꽃게 속도

#define AGGRO_X 20      // 꽃게 어그로 범위 X
#define AGGRO_Y 6       // 꽃게 어그로 범위 Y (토끼 높이 + 점프 높이)
#define AGGRO_OFF_X 38  // 꽃게 어그로 풀리는 범위
#define AGGRO_SPEED 0.8 // 꽃게 어그로 걸렸을 때 변하는 속도

#define CRAB_SKILL_COOLTIME 4000  // 꽃게 스킬 쿨타임

const static char g_CrabGraphic[2][CRAB_HEIGHT][CRAB_WIDTH] =
{
	{
		"(\\/) (\\/)",
		 "  \\o_o/ ",
		 " =(___)= "
	}, // 기본

	{
		"(|)   (|)",
		 "  \\o_o/ ",
		 " =(___)= "
	} // 공격
};

// 클래스
class Crab : Monster
{
	MyPoint pos;		// 위치
	float startPosX;	// 시작 x 위치
};

// 스킬 클래스
class MonsterSkill
{
	bool isAttack;		// 스킬 사용 중인지 여부
	int attackCnt;		// 스킬 구현 횟수
	int attack;			// 스킬 공격력
	long coolTime;		// 스킬 쿨타임 (ms)
};