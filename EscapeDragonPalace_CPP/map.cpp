#include "init.h"
#include "map.h"


// 생성자
Maps::Maps()
{
	ifstream fin;		// 파일 입력 스트림 객체 생성
	
	this->status = E_MapStatus::Jail;	// 첫 번째 맵: 감옥


	fin.open("map_jail.txt");
	if (!fin)
	{
		cout << "파일 열기 실패" << endl;
		return;
	}

	while (fin.get() != EOF)
	{

	}

	cout << str[0] << endl;
	cout << str[1] << endl;
	cout << str[2] << endl;
	cout << str[3] << endl;
	cout << str[4] << endl;
}