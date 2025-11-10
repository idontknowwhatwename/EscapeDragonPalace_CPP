#include "init.h"
#include "map.h"
#include "MapManager.h"

// 생성자
Maps::Maps()
{

}

// 소멸자
Maps::~Maps()
{

}

// 맵 데이터 불러오기 (파일 입출력)
//void Maps::GetMapData(string p_file)
//{
//	fstream fin;
//	string tempStr;
//
//	fin.open(p_file, 'r');		// 읽기 전용으로 불러오기
//
//	// 파일이 없을 경우
//	if (!fin.is_open())
//	{
//		cout << "파일이 없습니다." << endl;
//		return;
//	}
//
//	while (getline(fin, tempStr))
//	{
//		cout << tempStr << endl;
//		//this->m_mapArr[this->m_mapStatus] = tempStr;
//	}
//
//	fin.close();
//}
