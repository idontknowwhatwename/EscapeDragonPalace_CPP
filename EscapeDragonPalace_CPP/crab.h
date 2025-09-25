#pragma once
#include "data.h"
#include "monster.h"

// ��ũ��
#define CRAB_WIDTH 10   // �ɰ� �ʺ�
#define CRAB_HEIGHT 3   // �ɰ� ����
#define CRAB_CNT 17     // �ɰ� �迭 ��
#define CRAB_EYE 15     // �ɰ� �ν� ����
#define CRAB_SPEED  0.5 // �ɰ� �ӵ�

#define AGGRO_X 20      // �ɰ� ��׷� ���� X
#define AGGRO_Y 6       // �ɰ� ��׷� ���� Y (�䳢 ���� + ���� ����)
#define AGGRO_OFF_X 38  // �ɰ� ��׷� Ǯ���� ����
#define AGGRO_SPEED 0.8 // �ɰ� ��׷� �ɷ��� �� ���ϴ� �ӵ�

#define CRAB_SKILL_COOLTIME 4000  // �ɰ� ��ų ��Ÿ��

const static char g_CrabGraphic[2][CRAB_HEIGHT][CRAB_WIDTH] =
{
	{
		"(\\/) (\\/)",
		 "  \\o_o/ ",
		 " =(___)= "
	}, // �⺻

	{
		"(|)   (|)",
		 "  \\o_o/ ",
		 " =(___)= "
	} // ����
};

// Ŭ����
class Crab : public MonsterSkill
{
	MyPoint pos;		// ��ġ
	float startPosX;	// ���� x ��ġ
};

class MonsterSkill : public Monster
{
	bool isAttack;		// ��ų ��� ������ ����
	int attackCnt;		// ��ų ���� Ƚ��
	int attack;			// ��ų ���ݷ�
	long coolTime;		// ��ų ��Ÿ�� (ms)
};