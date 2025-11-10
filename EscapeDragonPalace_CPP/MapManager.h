#pragma once
#include "init.h"

#define MAP_HEIGHT 25   // 맵 높이
#define MAP_WIDTH 700	// 맵 너비

class Maps;

// 맵 상태 enum
enum E_MapStatus
{
	JAIL = 0,
	DRAGON_PALACE,
	SEA1,
	SEA2,
	GROUND,
	MAX,
};

// 맵 매니저 클래스
class MapManager
{
private:
	static MapManager* m_Instance;

protected:
	Maps* m_mapArr[(int)E_MapStatus::MAX];
	E_MapStatus m_mapStatus;
	int m_focusX;		// 플레이어를 기준으로 하는 x좌표 이동값

public:
	MapManager();
	virtual ~MapManager();

	static MapManager* GetInstance();

	E_MapStatus GetMapStatus();	// 현재 맵 레벨 불러오기
	void SetMapNext();			// 다음 맵 레벨로 변경하기

	int GetFocusX();			// x좌표 이동값 불러오기
	void SetFocusX(int p_x);	// x좌표 이동값 변경하기

	void Init();		// 맵 초기화
	void Update();		// 맵 업데이트
	void Draw();		// 맵 그리기
	void Destroy();		// 맵 해제
};

