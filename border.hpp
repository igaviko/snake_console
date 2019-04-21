#ifndef __BORDER_HPP__
#define __BORDER_HPP__

#include "drawable.hpp"
#include "virt_drawer.hpp"
#include "xy_crds.hpp"

struct t_virtDrawer;

class t_Border : i_Drawable
{
	public:
		t_Border(int startX, int startY, int w, int h, const char sym);
		~t_Border();
		
		int GetWidth() const;
		int GetHeight() const;
		const t_XYCrds& GetStartPos() const;
		
		const char* GetSym() const;
		void Draw(t_virtDrawer *drawer);
			
	private:
		t_Border(const t_Border &other);
		t_Border& operator=(const t_Border &other);
	
		t_XYCrds _startPos;
		
		int width;
		int heght;
		char _sym;
};

#endif