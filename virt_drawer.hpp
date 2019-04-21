#ifndef __VIRTDRAWER_HPP__
#define __VIRTDRAWER_HPP__

#include "snake.hpp"
#include "food.hpp"
#include "border.hpp"

class t_Border;
class t_Snake;
class t_Food;

struct t_virtDrawer
{
	virtual ~t_virtDrawer() {}
	virtual void DrawSnake(const t_Snake *snake) = 0;
	virtual void DrawFood(const t_Food *food) = 0;
	virtual void DrawBorder(const t_Border *border) = 0;
};

struct t_Drawer : t_virtDrawer
{
	void DrawSnake(const t_Snake *snake);
	void DrawFood(const t_Food *food);
	void DrawBorder(const t_Border *border);		
};



#endif