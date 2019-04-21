#ifndef __DRAWABLE_HPP__
#define __DRAWABLE_HPP__

#include "xy_crds.hpp"

struct t_virtDrawer;


struct i_Drawable
{
	virtual ~i_Drawable() {}
	virtual const char* GetSym() const = 0;
	virtual void Draw(t_virtDrawer *drawer) = 0;
};


#endif