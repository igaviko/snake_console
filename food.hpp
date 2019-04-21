#ifndef __FOOD_HPP__
#define __FOOD_HPP__

#include "drawable.hpp"
#include "virt_drawer.hpp"
#include "xy_crds.hpp"

struct t_virtDrawer;

class t_Food : i_Drawable
{
	public:
		t_Food(int x, int y, const char sym);
		~t_Food();
		
		const t_XYCrds* GetPos() const;		
		void RePos(const t_XYCrds &new_coords);		
		
		const char* GetSym() const;
		void Draw(t_virtDrawer *drawer);
		
	private:
	
		t_XYCrds posXY;
		char _sym;		
};

#endif