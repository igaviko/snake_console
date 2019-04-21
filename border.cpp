#include "border.hpp"

t_Border::t_Border(int startX, int startY, int w, int h, const char sym)
	: _startPos(), width(w), heght(h), _sym(sym)
{
	_startPos.x = startX;
	_startPos.y = startY;
	width = w;
	heght = h;
}

t_Border::~t_Border()
{
}

int t_Border::GetWidth() const
{
	return width;
}

int t_Border::GetHeight() const
{
	return heght;
}

const t_XYCrds& t_Border::GetStartPos() const
{
	return _startPos;
}

const char* t_Border::GetSym() const
{
	return &_sym;
}


void t_Border::Draw(t_virtDrawer *drawer)
{
	drawer->DrawBorder(this);
}