#pragma once
#include "init.h"
#include "mtg.h"

#define MAP_CNT 5		// 맵 갯수
#define MAP_HEIGHT 25   // 맵 높이
#define MAP_WIDTH 700	// 맵 너비

// 열거형
// 맵 상태
enum E_MapStatus
{
	Jail,
	DragonPalace,
	Sea1,
	Sea2,
	Ground, 
};

// 맵 클래스
class Maps
{
	E_MapStatus status;			// 현재 맵
	string BG[MAP_CNT][MAP_HEIGHT];		// 맵 배경
	string Platform[MAP_CNT][MAP_HEIGHT];	// 맵 발판
	
public:
	Maps();				// 생성자
	virtual ~Maps();	// 소멸자
	
	E_MapStatus GetMapStatus();					// 현재 맵 불러오기
	void SetMapStatus(E_MapStatus p_status);	// 현재 맵 설정하기

	void DrawMapLine();		// 맵 틀 그리기
	void DrawMapBG();		// 맵 배경 그리기
	void UpdateMapPos();	// 맵 위치 업데이트
};