#include "Rabbit.h"


Rabbit::Rabbit()
{
	HP = 10;
	x = RabbitXPos;
	y = RabbitYPos;
	Speed = RABBIT_SPEED;
	velY = 0.0f;
	isJumping = false;
	isAttacking = false;
	isInvincible = false;
	invincibleStartTime = 0;

	RabbitSprite[0] = { /* 장검 오른쪽 기본 */ "        (\\(\\", "        ('-')", "       o(　--|====>" };

	RabbitSprite[1] = { /* 장검 왼쪽 기본 */ "         /)/)", "        ('-')", "  <====|--　)o" };

	RabbitSprite[2] = { /* 장검 오른쪽 공격 */ "        (\\(\\ ", "        ('-')", "       o(　　--|====>" };

	RabbitSprite[3] = { /* 장검 왼쪽 공격 */ "         /)/) ", "        ('-') ", "<====|--　　)o" };

	RabbitSprite[4] = { /* 단검 오른쪽 기본 */ "        (\\(\\ ", "        ('-')", "       o(　-|=>" };

	RabbitSprite[5] = { /* 단검 왼쪽 기본 */ "         /)/) ", "        ('-') ", "      <=|-　)o" };

	RabbitSprite[6] = { /* 단검 오른쪽 공격 */ "        (\\(\\ ", "        ('-')", "       o(　　-|=>" };

	RabbitSprite[7] = { /* 단검 왼쪽 공격 */  "         /)/) ", "        ('-') ", "    <=|-　　)o" };

	RabbitSprite[8] = { /* 창 오른쪽 기본 */ "        (\\(\\ ", "        ('-')", "       o(　------>" };

	RabbitSprite[9] = { /* 창 왼쪽 기본 */ "         /)/) ", "        ('-') ", "   <------　)o" };

	RabbitSprite[10] = { /* 창 오른쪽 공격 */ "        (\\(\\ ", "        ('-')", "       o(　　------>" };

	RabbitSprite[11] = { /* 창 왼쪽 공격 */ "         /)/) ", "        ('-') ", " <------　　)o" };

	RabbitSprite[12] = { /* 플레이어 오른쪽 */ "        (\\(\\", "        ('-')", "       o(   )" };

	RabbitSprite[13] = { /* 플레이어 왼쪽 */ "         /)/) ", "        ('-') ", "        (   )o" };
}

Rabbit::~Rabbit()
{
}

void Rabbit::Move()
{
	// 이동 로직 구현
	if (_kbhit())
	{
		if (g_Key == 'a' || g_Key == 'A')
		{
			this->x -= Speed;
		}
		else if (g_Key == 'd' || g_Key == 'D')
		{
			this->x += Speed;
		}
		else if (g_Key == 'w' || g_Key == 'W')
		{
			//Jump();
		}
		else if (g_Key == 's' || g_Key == 'S')
		{
			this->y++;
			//GravityEffect();
		}
		_getch();
	}
}

void Rabbit::Draw()
{
	int idx = 0;
	// 그리기 로직 구현
	for (int y = 0; y < RabbitY; y++)
	{
		const char* line = RabbitSprite[idx][y].c_str();
		int len = strlen(line);
		for (int x = 0; x < len; x++)
		{
			if (line[x] != ' ')
			{
				char temp[2] = { line[x], '\0' };
				_DrawText((int)this->x + x, (int)this->y + y, temp);
			}
		}
	}
}