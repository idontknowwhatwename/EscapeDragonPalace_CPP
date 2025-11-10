#include "MapManager.h"
#include "map.h"

// 싱글톤 사용
MapManager* MapManager::m_Instance = nullptr;

// 맵 매니저 불러오기
MapManager* MapManager::GetInstance()
{
	if (MapManager::m_Instance == nullptr)
	{
		MapManager::m_Instance = new MapManager();
	}

	return MapManager::m_Instance;
}

// 맵 매니저 생성자
MapManager::MapManager()
{
	this->Init();
}

// 맵 매니저 소멸자
MapManager::~MapManager()
{
	this->Destroy();
}

// 현재 맵 위치 불러오기
E_MapStatus MapManager::GetMapStatus()
{
	return E_MapStatus();
}

// 다음 맵으로 이동
void MapManager::SetMapNext()
{
	// 보스레벨 이전 맵일 경우 다음 레벨로 이동
	if (this->m_mapStatus < E_MapStatus::GROUND)
		this->m_mapStatus = (E_MapStatus)(this->m_mapStatus + 1);
}

// x좌표 이동값 불러오기
int MapManager::GetFocusX()
{
	return this->m_focusX;
}

// x좌표 이동값 변경하기
void MapManager::SetFocusX(int p_x)
{
	this->m_focusX = p_x;
}

// 맵 생성
void MapManager::Init()
{
	// 처음 맵: 감옥으로 설정
	this->m_mapStatus = E_MapStatus::JAIL;

	// 맵 배열 생성
	//this->m_mapArr[(int)E_MapStatus::MAX] = new Maps(this->m_mapStatus);
}

// 맵 해제
void MapManager::Destroy()
{
	for (int i = 0; i < (int)E_MapStatus::MAX; i++)
	{
		if (this->m_mapArr[i])
		{
			delete this->m_mapArr[i];
			this->m_mapArr[i] = nullptr;
		}
	}
}