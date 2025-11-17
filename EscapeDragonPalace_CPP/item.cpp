#include "item.h"
#include "data.h"
#include "MapManager.h"


ItemManager* ItemManager::item_Instance = nullptr;

ItemManager* ItemManager::GetInstance()
{
	if (ItemManager::item_Instance == nullptr)
	{
		ItemManager::item_Instance = new ItemManager();
	}

	return ItemManager::item_Instance;
}

// 기본 생성자
Item::Item()
{
	x = 0;
	y = 0;
	isHeld = false;
	width = 0;
	height = 0;
	itemType = E_ITEM_SPEED; // 기본값
}

// 해초 생성자
SEAWEED::SEAWEED(float p_x, float p_y, bool p_isHeld, E_MapStatus p_mapStatus)
{
	x = p_x;
	y = p_y;
	isHeld = p_isHeld;
	width = 11;
	height = 3;
	itemType = E_ITEM_LIFE;
	mapStatus = p_mapStatus;
}

// 공기방울 생성자
BUBBLES::BUBBLES(float p_x, float p_y, bool p_isHeld, E_MapStatus p_mapStatus)
{
	x = p_x;
	y = p_y;
	isHeld = p_isHeld;
	width = 5;
	height = 2;
	itemType = E_ITEM_SPEED;
	mapStatus = p_mapStatus;
}

// 조개 생성자
CLAM::CLAM(float p_x, float p_y, bool p_isHeld, E_MapStatus p_mapStatus)
{
	x = p_x;
	y = p_y;
	isHeld = p_isHeld;
	width = 6;
	height = 1;
	itemType = E_ITEM_DEBUFF;
	mapStatus = p_mapStatus;
}

// 아이템 초기화 함수
void ItemManager::InitItems()
{
	// 감옥맵 JAIL ===============================================
	
	// 해초
	itemList.push_back(new SEAWEED(353, 14, false, JAIL));
	itemList.push_back(new SEAWEED(530, 12, false, JAIL));

	// 공기방울
	itemList.push_back(new BUBBLES(160, 22, false, JAIL));
	itemList.push_back(new BUBBLES(570, 22, false, JAIL));

	// 조개
	itemList.push_back(new CLAM(119, 13, false, JAIL));
	itemList.push_back(new CLAM(251, 18, false, JAIL));
	itemList.push_back(new CLAM(400, 23, false, JAIL));

	// =============================================================

	// 용궁맵 DRAGON_PALACE =========================================

	// 해초
	itemList.push_back(new SEAWEED(206, 9, false, DRAGON_PALACE));
	itemList.push_back(new SEAWEED(288, 6, false, DRAGON_PALACE));
	itemList.push_back(new SEAWEED(467, 1, false, DRAGON_PALACE));

	// 공기방울
	itemList.push_back(new BUBBLES(190, 22, false, DRAGON_PALACE));
	itemList.push_back(new BUBBLES(340, 22, false, DRAGON_PALACE));
	itemList.push_back(new BUBBLES(484, 22, false, DRAGON_PALACE));

	// 조개
	itemList.push_back(new CLAM(145, 19, false, DRAGON_PALACE));
	itemList.push_back(new CLAM(308, 13, false, DRAGON_PALACE));
	itemList.push_back(new CLAM(413, 23, false, DRAGON_PALACE));

	// =============================================================

	// 바다맵 1 SEA1 ================================================

	// 해초
	itemList.push_back(new SEAWEED(99, 21, false, SEA1));
	itemList.push_back(new SEAWEED(429, 21, false, SEA1));

	// 공기방울
	itemList.push_back(new BUBBLES(131, 9, false, SEA1));
	itemList.push_back(new BUBBLES(282, 8, false, SEA1));
	itemList.push_back(new BUBBLES(386, 14, false, SEA1));
	itemList.push_back(new BUBBLES(563, 13, false, SEA1));

	// 조개
	itemList.push_back(new CLAM(140, 23, false, SEA1));
	itemList.push_back(new CLAM(226, 23, false, SEA1));
	itemList.push_back(new CLAM(404, 23, false, SEA1));
	itemList.push_back(new CLAM(532, 23, false, SEA1));

	// =============================================================

	// 바다맵 2 SEA2 ================================================

	// 해초
	itemList.push_back(new SEAWEED(100, 21, false, SEA2));
	itemList.push_back(new SEAWEED(210, 5, false, SEA2));
	itemList.push_back(new SEAWEED(471, 21, false, SEA2));
	itemList.push_back(new SEAWEED(542, 11, false, SEA2));

	// 공기방울
	itemList.push_back(new BUBBLES(138, 11, false, SEA2));
	itemList.push_back(new BUBBLES(440, 17, false, SEA2));

	// 조개
	itemList.push_back(new CLAM(62, 23, false, SEA2));
	itemList.push_back(new CLAM(167, 23, false, SEA2));
	itemList.push_back(new CLAM(247, 23, false, SEA2));
	itemList.push_back(new CLAM(335, 23, false, SEA2));
	itemList.push_back(new CLAM(374, 18, false, SEA2));

	// =============================================================

}

// 아이템 모션효과 frame 계산 함수
void ItemManager::UpdateFrame()
{
	clock_t now = clock();
	int elapsed = (now - lastFrameTime) * 1000 / CLOCKS_PER_SEC;

	if (elapsed >= frameDelay)
	{
		frame = (frame + 1) % 2;
		lastFrameTime = now;
	}

	_Invalidate();  // 매 프레임 그리기는 계속
}

// 아이템 그리는 함수
void ItemManager::DrawItems(E_MapStatus currentMap)
{
	MapManager* MapMgr = MapManager::GetInstance();

	// 아이템 배열인덱스 만큼	반복
	for (int i = 0; i < itemList.size(); i++)
	{
		// 아이템이 바닥에 있을 때만 그리기 ( 현재 스테이지에 플레이어가 먹지 않은 아이템만 그리기 )
		if (!itemList[i]->GetIsHeld() && itemList[i]->GetMapStatus() == currentMap)
		{

			// 아이템 타입에 따라 해초 or 공기방울 or 조개 sprite 선택
			switch (itemList[i]->GetItemType())
			{
			case E_ITEM_LIFE:	// 체력증가(해초)일 때
				_SetColor(E_Green);
				break;
			case E_ITEM_SPEED:	// 속도증가(공기방울)일 때
				_SetColor(E_BrightTeal);
				break;
			case E_ITEM_DEBUFF:	// 속도감소(조개)일 때
				_SetColor(E_White);
				break;
			}



			int tempX = itemList[i]->GetX() - MapMgr->GetFocusX();
			char buf[2];

			switch (itemList[i]->GetItemType())
			{

			case E_ITEM_LIFE: case E_ITEM_SPEED:
				for (int row = 0; row < itemList[i]->GetHeight(); row++)
				{
					const string& line = (itemList[i]->GetSprite())[frame][row];
					if (line.empty()) break;  // 빈 줄이면 중단

					for (int col = 0; col < itemList[i]->GetWidth(); col++)
					{
						// 아이템 위치가 화면 내에 있을 때만 출력
						if (0 <= tempX + col && SCREEN_WIDTH > tempX + col)
						{

							buf[0] = line[col];
							buf[1] = '\0';
							_DrawText(tempX + col, itemList[i]->GetY() + row, buf);
						}
					}
				}
				break;
			case E_ITEM_DEBUFF:
				// 조개일 경우 프레임 없이 출력
				const string& line = (itemList[i]->GetSprite())[0][0];
				for (int col = 0; col < itemList[i]->GetWidth(); col++)
					if (0 <= tempX + col && SCREEN_WIDTH > tempX + col)
					{
						buf[0] = line[col];
						buf[1] = '\0';
						_DrawText(tempX + col, itemList[i]->GetY(), buf);
					}
				break;
			}
		}
	}
}

// 아이템 isHeld false로 초기화 함수
void ItemManager::ResetItems(E_MapStatus map)
{
	for (int i = 0; i < itemList.size(); i++)
	{
		if (itemList[i]->GetMapStatus() == map)
			itemList[i]->SetIsHeld(false);
	}
}

Item::~Item()
{
}

ItemManager::~ItemManager()
{
	for (int i = 0; i < itemList.size(); i++)
	{
		delete itemList[i];
	}
	itemList.clear();
}