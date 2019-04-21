#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include "drawable.hpp"
#include "virt_drawer.hpp"
#include "xy_crds.hpp"

struct t_virtDrawer;

class t_Snake : i_Drawable
{
	public:
		t_Snake(int headX, int headY, const char sym);
		~t_Snake();
		
		const t_XYCrds* GetHeadPos() const;		
		
		void Move(const t_XYCrds &mv_crds);
		void AddItem(const t_XYCrds &mv_crds);
		const bool IsCollapse() const;
		const int GetItemsCnt() const;
		const t_XYCrds* GetItem(int i) const;
		
		const char* GetSym() const;
		void Draw(t_virtDrawer *drawer);
		
	private:
		t_Snake(const t_Snake &other);
		t_Snake& operator=(const t_Snake &other);
	
	
		t_XYCrds **points_list;
		int item_cnt;
		int item_max;
		char _sym;	
		bool isCollapse;
}; 




#endif