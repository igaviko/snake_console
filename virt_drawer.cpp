#include "virt_drawer.hpp"
#include <curses.h>

void t_Drawer::DrawSnake(const t_Snake *snake)
{
	for (int i = 0; i < snake->GetItemsCnt(); ++i)
		mvprintw( snake->GetItem(i)->x, snake->GetItem(i)->y, snake->GetSym());
}

void t_Drawer::DrawFood(const t_Food *food)
{
	mvprintw( food->GetPos()->x, food->GetPos()->y, food->GetSym());
}

void t_Drawer::DrawBorder(const t_Border *border)
{
	for (int i = 0; i<border->GetHeight(); ++i)
	{		
		if ((i == 0)||(i == border->GetHeight()-1))
		{
			for (int j = 0; j<border->GetWidth(); ++j)
				mvprintw( border->GetStartPos().x+i, border->GetStartPos().y+j, border->GetSym());
		}
		else
		{
			mvprintw( border->GetStartPos().x+i, border->GetStartPos().y, border->GetSym());
			mvprintw( border->GetStartPos().x+i, border->GetStartPos().y+border->GetWidth(), border->GetSym());
		}
	}
}
