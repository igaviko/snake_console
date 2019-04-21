#ifndef __XY_CRDS_HPP__
#define __XY_CRDS_HPP__

#define BORDER_W 50
#define BORDER_H 20

struct t_XYCrds
{
	t_XYCrds() : x(0),y(0) {}
	t_XYCrds(int x, int y) : x(x),y(y) {}
	
	t_XYCrds& operator=(const t_XYCrds& other) 
	{
		x = other.x;
		y = other.y;
		return *this;
	}
	
	t_XYCrds operator+(const t_XYCrds& other) const 
	{
		t_XYCrds sum;
		sum.x = x + other.x;
		sum.y = y + other.y;
		return sum;
	}
	
	t_XYCrds& operator+=(const t_XYCrds& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	int x;
	int y;
};


#endif