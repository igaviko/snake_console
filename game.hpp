
#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "snake.hpp"
#include "food.hpp"
#include "border.hpp"


class t_Game
{
	public:
		t_Game();
		~t_Game();
		void GameFunc();
		
		
	private:
		t_Snake *snake;
		t_Food *food;
		t_Border *border;	
		t_Drawer drawer;
		//bool game_on;
};





#endif