#include "game.hpp"

#include <curses.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

t_Game::t_Game(): drawer()
{
	snake = new t_Snake(BORDER_H/2, BORDER_W/2, '*');
	food = new t_Food(rand()%(BORDER_H-1) + 1, rand()%(BORDER_W-1) + 1, '$');
	border = new t_Border(0,0,BORDER_W, BORDER_H, '#');
	//game_on = false;
}

t_Game::~t_Game()
{
	delete snake;
	delete food;
	delete border;
}

void t_Game::GameFunc()
{
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, true);
	nodelay(stdscr, true);
	refresh;

	bool game_on = true;
	int mv = 3;
	t_XYCrds mv_coodrds(0,1);
	while(game_on)
	{
		Sleep(500);
		clear();
		
		switch(getch())
		{
			case KEY_UP:
				mv = 0;
				mv_coodrds.x = -1;
				mv_coodrds.y = 0;
				break;	
			case KEY_DOWN:
				mv = 1;
				mv_coodrds.x = 1;
				mv_coodrds.y = 0;
				break;
			case KEY_LEFT:
				mv = 2;
				mv_coodrds.x = 0;
				mv_coodrds.y = -1;
				break;
			case KEY_RIGHT:
				mv = 3;
				mv_coodrds.x = 0;
				mv_coodrds.y = 1;
				break;
			case 27:
				game_on = false;
				break;
			default: break;
		}
		
		border->Draw(&drawer);
		food->Draw(&drawer);
		snake->Move(mv_coodrds);		
		snake->Draw(&drawer);	
		refresh();
		
		if ((food->GetPos()->x == snake->GetHeadPos()->x)&&
			(food->GetPos()->y == snake->GetHeadPos()->y))
		{
			snake->AddItem(mv_coodrds);
			bool coords_ok = false;
			while(!coords_ok)
			{
				t_XYCrds new_food_coords(rand()%(BORDER_H-1) + 1, rand()%(BORDER_W-1) + 1);
				coords_ok = true;
				for (int i = 0; i<snake->GetItemsCnt(); ++i)
					if ((snake->GetItem(i)->x == new_food_coords.x)&&
						(snake->GetItem(i)->y == new_food_coords.y))
						coords_ok = false;
				food->RePos(new_food_coords);
			}	
		}
		
		if (snake->IsCollapse())
			game_on = false;
	}
	
	nodelay(stdscr, false);
	mvprintw( BORDER_H/2, BORDER_W/2 - 4, "GAME OVER");
	refresh;
	
	getch(); 	
    endwin();
}