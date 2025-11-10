#pragma once

#include "init.h"

using namespace std;

//===============================================================================

#define RABBIT_WIDTH 10 // 토끼 너비
#define RabbitX 25 // Rabbit char 가로 크기
#define RabbitY 3 // Rabbit char 세로 크기
#define RABBIT_SPEED 1.2	// Rabbit 이동 속도

#define JUMP_POWER -2.5f // 점프 높이 (음수로 갈 수록 점프 높아짐)
#define GRAVITY 0.5f // 중력 가속도
#define MAX_FALL_SPEED 4.0f  // 최대 낙하 속도

#define RabbitXPos 7.0f
#define RabbitYPos 21.0f

#define DURATION 5000

#define SLOWDURATION 3000

#define INVINCIBLE_TIME 1000  // 토끼 무적시간 (1초)

//===============================================================================

class Rabbit
{
protected:
	int HP;				 	// 토끼 체력
	float x, y; 			// 토끼 위치
	int Direction;			// 토끼 방향 (0: 오른쪽, 1: 왼쪽)

	float Speed; 			// 토끼 이동 속도
	float velY;				// 토끼 수직 속도

	bool isJumping;			// 점프 상태
	bool isAttacking;		// 공격 상태
	bool isInvincible;		// 무적 상태

	unsigned long invincibleStartTime; // 무적 시작 시간

	vector <string> RabbitSprite[14]; // 토끼 스프라이트

public:
	Rabbit();				// 생성자
	virtual ~Rabbit();		// 소멸자

	void Draw();			// 그리기
	void Move();			// 이동
	void Jump();			// 점프
	void Attack();			// 공격
	void GravityEffect();	// 중력 효과 적용
	void Update();			// 상태 업데이트
	void TakeDamage();		// 데미지 처리
	float GetX() const { return x; } // X 좌표 반환
	float GetY() const { return y; } // Y 좌표 반환
	bool GetIsInvincible() const { return isInvincible; } // 무적 상태 반환
};


int g_Key;	// 입력 키