#include "Vector2.h"

Vector2::Vector2()
{
	_x = 0;
	_y = 0;
}

Vector2::Vector2(int x, int y)
{
	_x = x;
	_y = y;
}

void Vector2::set(int x, int y)
{
	_x = x;
	_y = y;
}

void Vector2::set(Vector2 v)
{
	_x = v._x;
	_y = v._y;
}

void Vector2::rotate()
{
	int tx = _x;
	_x = _y;
	_y = tx;
}

int Vector2::x()
{
	return _x;
}

int Vector2::y()
{
	return _y;
}

Vector2 Vector2::get()
{
	return { _x, _y };
}