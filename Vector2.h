#pragma once
class Vector2
{
	int _x, _y;

public:
	Vector2();
	Vector2(int x, int y);
	void set(int x, int y);
	void set(Vector2 v);
	void rotate();
	int x();
	int y();
	Vector2 get();
};

