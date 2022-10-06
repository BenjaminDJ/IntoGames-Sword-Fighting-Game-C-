#pragma once
#include <iostream>

class vec2 {
public:
	vec2();
	vec2(int _x, int _y);
	vec2(const vec2& other);

	vec2 operator+(const vec2& other);
	vec2 operator+=(const vec2& other);
	vec2 operator-(const vec2& other);

	friend std::ostream& operator<<(std::ostream& os, const vec2& point);

	int GetX();
	void SetX(int _x);
	int GetY();
	void SetY(int _y);
	
	static vec2 Up() { return vec2(0, -1); }

private:
	int x;
	int y;
};

