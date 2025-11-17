#pragma once

#ifndef OUT
#define OUT

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <conio.h>
#include "mtg.h"

using namespace std;

// 열거형
// 방향
enum E_Dir {
    Right,
    Left,
};

// 전역변수
static int g_Key;	// 입력 키

#define SCREEN_WIDTH 80 // 화면 너비
#define SCREEN_HEIGHT 25 // 화면 높이

// CMD 색깔
typedef enum CMDColor
{
	E_Black,
	E_Blue,
	E_Green,
	E_Teal, // 청록색
	E_Red,
	E_Purple,
	E_Yellow,
	E_White,
	E_Gray,
	E_BrightBlue,
	E_BrightGreen,
	E_BrightTeal,
	E_BrightRed,
	E_BrightPurple,
	E_BrightYellow,
	E_BrightWhite,
} CMDColor;

#endif