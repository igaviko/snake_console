#include "food.hpp"

t_Food::t_Food(int x, int y, const char sym): posXY(), _sym(sym)
{
	posXY.x = x;
	posXY.y = y;
	_sym = sym;
}

t_Food::~t_Food()
{
}

const t_XYCrds* t_Food::GetPos() const
{
	return &posXY;
}

void t_Food::RePos(const t_XYCrds &new_coords)
{
	posXY = new_coords;
}

const char* t_Food::GetSym() const
{
	return &_sym;
}

void t_Food::Draw(t_virtDrawer *drawer)
{
	drawer->DrawFood(this);
}
