#include "snake.hpp"

t_Snake::t_Snake(int headX, int headY, const char sym): points_list()
{	
	t_XYCrds* headPosXY = new t_XYCrds();
	headPosXY->x = headX;
	headPosXY->y = headY;
	item_max = 10;
	points_list = new t_XYCrds* [item_max];	
	points_list[0] = headPosXY;
	item_cnt = 1;
	_sym = sym;
	isCollapse = false;
}

t_Snake::~t_Snake()
{
	for (int i = 0; i < item_cnt; ++i)
		delete points_list[i];
	
	delete [] points_list;
}

const t_XYCrds* t_Snake::GetHeadPos() const
{
	return points_list[item_cnt-1];
}

const char* t_Snake::GetSym() const
{
	return &_sym;
}

void t_Snake::Move(const t_XYCrds &mv_crds)
{
	t_XYCrds h_coord = *(points_list[item_cnt-1]) + mv_crds;
	//int hx = points_list[item_cnt-1]->x + mv_crds.x;
	//int hy = points_list[item_cnt-1]->y + mv_crds.y;
	
	if (item_cnt > 1)
	{	
		for (int i = 0; i < item_cnt-1; ++i)
		{
			*(points_list[i]) = *(points_list[i+1]);
			
			if ((points_list[i]->x == h_coord.x)&&(points_list[i]->y == h_coord.y))
				isCollapse = true;
		}
	}
	
	*(points_list[item_cnt-1]) = h_coord;
	
	if ((h_coord.x < 0)||(h_coord.x > BORDER_H)||(h_coord.y < 0)||(h_coord.y > BORDER_W))
		isCollapse = true;	
}

const bool t_Snake::IsCollapse() const
{
	return isCollapse;
}

const int t_Snake::GetItemsCnt() const
{
	return item_cnt;
}

const t_XYCrds* t_Snake::GetItem(int i) const
{
	if (i > item_cnt - 1)
		return 0;
	
	return points_list[i];
}

void t_Snake::AddItem(const t_XYCrds &mv_crds)
{
	++item_cnt;
	if (item_cnt > item_max)
	{
		item_max *= 2;
		t_XYCrds **new_list = new t_XYCrds* [item_max];
		for (int i = 0; i<item_cnt-1; ++i)
			new_list[i] = points_list[i];
		delete points_list;
		points_list = new_list;
	}
	
	t_XYCrds *new_item = new t_XYCrds(*(points_list[item_cnt-2]) + mv_crds);
	points_list[item_cnt-1] = new_item;
	
}


void t_Snake::Draw(t_virtDrawer *drawer)
{
	drawer->DrawSnake(this);
}

