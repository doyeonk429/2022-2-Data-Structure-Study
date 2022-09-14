#include <stdio.h>
using namespace std;

class Rectangle
{
public:
	Rectangle();
	~Rectangle();
	int GetHeight();
	int GetWidth();
	bool operator< (Rectangle r1);

private:
	int xLow, yLow, height, width;

};

class MyRectangle
{
public:
	MyRectangle(int x, int y, int h, int w);
	~MyRectangle();

private:
	int xLow, yLow, height, width;

};

MyRectangle::MyRectangle(int x, int y, int h, int w)
{
	xLow = x;
	yLow = y;
	height = h;
	width = w;

}

MyRectangle::~MyRectangle()
{
}

Rectangle::Rectangle()
{
}

Rectangle::~Rectangle()
{
}

bool Rectangle::operator< (Rectangle r1) // 72page Q1
{
	if (height* width < r1.height*r1.width)
	{
		return true;
	}
	else
	{
		return false;
	}
}
