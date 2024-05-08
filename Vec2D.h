#pragma once
#ifndef VEC_2D
#define VEC_2D


class Vec2D
{
private:
	float x;
	float y;

public:
	Vec2D(float x, float y) : x{ x }, y{ y } {};
	
	void setX(float x);

	void setY(float y);

	float getX() const;

	float getY() const;

	float magnitude() const;

};

#endif // !VEC_2D