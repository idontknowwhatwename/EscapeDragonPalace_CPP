#pragma once
#include "init.h"

// ������ ���� ������
typedef enum
{
	E_ITEM_SPEED,   // �ӵ� ����
	E_ITEM_LIFE,    // ü�� ����
	E_ITEM_DEBUFF,  // �ӵ� �� ü�� ���� (�����)
} ItemType;

// ������ Ŭ����
class Item
{
public:
	Item(const ItemType p_type, const float p_x, const float p_y, bool p_isHeld, const float p_width, const float p_height);
	static vector<Item> InitItem();

protected:
	ItemType type;          // ������ ����
	float x, y;             // ������ ��ġ ��ǥ
	bool isHeld;            // �÷��̾� ���� ����
	float width, height;    // ������ �ʺ�, ����
	MapStatus mapStatus;    // �������� �����ϴ� ��
};


