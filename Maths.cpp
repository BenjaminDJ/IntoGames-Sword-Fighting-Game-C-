#include "Maths.h"

vec2::vec2() :
	x(0), y(0)
{
}

vec2::vec2(int _x, int _y) :
	x(_x), y(_y)
{
}

vec2::vec2(const vec2& other) :
	x(other.x), y(other.y)
{
}

vec2 vec2::operator+(const vec2& other)
{
	return vec2(this->x + other.x, this->y + other.y);
}

vec2 vec2::operator+=(const vec2& other)
{
	vec2* thisClass = this;
	return *thisClass + other;
}

vec2 vec2::operator-(const vec2& other)
{
	vec2 result;
	result.x = this->x - other.x;
	result.y = this->y - other.y;
	return vec2();
}

int vec2::GetX()
{
	return x;
}

void vec2::SetX(int _x)
{
	x = _x;
}

int vec2::GetY()
{
	return y;
}

void vec2::SetY(int _y)
{
	y = _y;
}


std::ostream& operator<<(std::ostream& os, const vec2& point) {
	os << point.x << ", " << point.y;
	return os;
}
