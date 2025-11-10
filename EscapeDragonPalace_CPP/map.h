#pragma once
#include "init.h"

// 맵 클래스
class Maps
{
	vector<string> BG;			// 맵 배경
	vector<string> Platform;	// 맵 발판
	
public:
	Maps();				// 생성자
	virtual ~Maps();	// 소멸자

	//void GetMapData(string p_file);		// 맵 데이터 받아오기 (파일입출력)
};