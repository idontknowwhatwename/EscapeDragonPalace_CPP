#pragma once
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