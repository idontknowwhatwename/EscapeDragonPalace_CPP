#include "item.h"
#include "data.h"

Item::Item(const ItemType p_type, const float p_x, const float p_y, bool p_isHeld, const float p_width, const float p_height)
{
	type = p_type;
	x = p_x;
	y = p_y;
	isHeld = p_isHeld;
	width = p_width;
	height = p_height;
	mapStatus = ;
}
